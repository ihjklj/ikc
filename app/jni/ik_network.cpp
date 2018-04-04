
#include "ik_network.h"

int ethIsRun(const char* szEth, BOOL *pbEthExist) {
	
	struct ifreq ifr;
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd == -1) {
		return 0;
	}
	memset(&ifr, 0, sizeof(ifr));
	strcpy(ifr.ifr_name, szEth);
	if (ioctl(fd, SIOCGIFFLAGS, (char*)&ifr) < 0){
		close(fd);
		if (pbEthExist != NULL)
			*pbEthExist = FALSE;
		return -1;
	}
	close(fd);
	return ((ifr.ifr_flags & (IFF_RUNNING | IFF_UP)) == (IFF_RUNNING | IFF_UP));
}

int getHost(char *pValue, int pLen) {
	
	struct ifreq ifr[12];
	struct ifconf ifc;
	char buffer[256];
	memset(buffer, 0, sizeof(buffer));
	int nSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (nSocket == -1) {
		LOGD("GetHost error:%d,%s.", errno, strerror(errno));
		return 0;
	}
	ifc.ifc_req = ifr;
	ifc.ifc_len = sizeof(ifr);
	if (ioctl(nSocket, SIOCGIFCONF, &ifc) < 0) {
		LOGD("GetHost SIOCGIFCONF error:%d,%s.", errno, strerror(errno));
		close(nSocket);
		return 0;
	}
	int nCnt = ifc.ifc_len / sizeof(struct ifreq);
	for (int i=0; i<nCnt; i++) {
		struct sockaddr_in sin;
		memcpy(&sin, &ifc.ifc_req[i].ifr_addr, sizeof(sin));
		int tNetStatus = ethIsRun(ifc.ifc_req[i].ifr_name, NULL);
		LOGD("name:%s, flag:%d, ip:%s, status:%s.", 
			ifc.ifc_req[i].ifr_name,
			ifc.ifc_req[i].ifr_flags, 
			inet_ntoa(sin.sin_addr),
			tNetStatus > 0 ? "running" : "not enabled");	//lo
		if (strcasecmp(ifc.ifc_req[i].ifr_name, "lo") == 0) {
			continue;
		}
		//判断网卡是否在运行
		if (tNetStatus <= 0) {
			continue;
		}
		if (strncmp(ifc.ifc_req[i].ifr_name, "ppp", 3) == 0) {
			snprintf(pValue, pLen, "%s", inet_ntoa(sin.sin_addr));
			break;
		}
		else if (strncmp(ifc.ifc_req[i].ifr_name, "eth", 3) == 0) { 
			snprintf(pValue, pLen, "%s", inet_ntoa(sin.sin_addr));
			break;
		}
		else if (strncmp(ifc.ifc_req[i].ifr_name, "wlan", 4) == 0) {
			//192.168.43.1地址是Wifi热点的地址 2015-12-07
			if (strcmp("192.168.43.1", inet_ntoa(sin.sin_addr)) == 0) {
				continue;
			}
			snprintf(pValue, pLen, "%s", inet_ntoa(sin.sin_addr));
			break;
		}
	}
	close(nSocket);
	return TRUE;
}