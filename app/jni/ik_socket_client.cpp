
#include "ik_socket_client.h"

CSocketClient::CSocketClient() {
    mSocketFd = -1;
    mPort = 0;
    mIsConnected = false;
    mHost = NULL;
}

CSocketClient::CSocketClient(char *host, int port) {
    mSocketFd = -1;
    mPort = port;
    mIsConnected = false;
    mHost = strdup(host);
}

CSocketClient::~CSocketClient(){
    if (mSocketFd != -1) {
        closeTo();
    }
	free(mHost);
}

int CSocketClient::init(char *host, int port) {
    mHost = host;
    mPort = port;
	return 0;
}

bool CSocketClient::connectTo() {
    int socketFd = socket(PF_INET, SOCK_STREAM, 0);
    if (socketFd == -1) {
        LOGD("socket failed!");
        return false;
    }

    struct sockaddr_in clientAddr;
    memset(&clientAddr, 0, sizeof(clientAddr));
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_addr.s_addr = inet_addr(mHost);
    clientAddr.sin_port = htons(mPort);

    struct timeval tv = {3, 0};
    /* 设置发送超时 */
    setsockopt(socketFd, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv));

    /* 设置接收超时,因为加了线程锁所以这里设置接收超时就很有必要了 */
    setsockopt(socketFd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv));

    int nRet = connect(socketFd, (struct sockaddr *)&clientAddr, sizeof(clientAddr));
    if (nRet < 0){
        LOGD("socket %d. Failed to connect() :%s.", socketFd, strerror(errno));
        closesocket(socketFd);
        return false;
    }
    LOGD("socket %d, connect success.", socketFd);
    mSocketFd = socketFd;
    mIsConnected = true;
    return true;
}

void CSocketClient::closeTo() {
    close(mSocketFd);
    mSocketFd = -1;
    mIsConnected = false;
}

int CSocketClient::sendToServer(void *pMsg, int pLen) {

    if (!mIsConnected) {
        if (!connectTo()) {
            LOGD("connect to %s failed!", mHost);
        }
    }

    int ret = send(mSocketFd, (char *)pMsg, pLen, 0);
    if (ret <= 0) {
        LOGD("send msg failed!");
        closeTo();
    }

    return ret;
}





