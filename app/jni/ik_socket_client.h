
#ifndef __C_SOCKET_CLIENT_H__
#define __C_SOCKET_CLIENT_H__

#include "ik_public.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <net/if.h>
#include <errno.h>

class CSocketClient {
public:
    CSocketClient();
    CSocketClient(char *host, int port);
    ~CSocketClient();

    int init(char *host, int port);
    bool connectTo();
    void closeTo();
    int sendToServer(void *pMsg, int pLen);

protected:
    int     mSocketFd;
    int     mPort;
    bool    mIsConnected;
    char*   mHost;
};
















#endif /* __C_SOCKET_CLIENT_H__ */

