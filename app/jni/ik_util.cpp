
#include "ik_util.h"

BOOL isApkRunning(const char *pApkName) {
	
	FILE *tFilePt = NULL;
	char tCmd[1024] = {0};
	char tValue[1024] = {0};
	BOOL tExisit = FALSE;
	
	snprintf(tCmd, sizeof(tCmd), "ps | grep %s", pApkName);
	if ((tFilePt = popen(tCmd, "r")) != NULL) {
		while (fgets(tValue, sizeof(tValue), tFilePt)) {
			LOGD("%s.", tValue);
			if (strstr(tValue, pApkName)) {
				tExisit = TRUE;
				break;
			}
		}
		pclose(tFilePt);
	}
	return tExisit;
}

void killExistProcess(const char *pName) {
	
	char tCmd[64] = {0};
	char tBuf[1024] = {0};
	FILE *tFilePt = NULL;
	int tPid = 0;
	
	snprintf(tCmd, sizeof(tCmd), "ps |grep %s", pName);
	if ((tFilePt = popen(tCmd, "r")) != NULL) {
        while (fgets(tBuf, 1024, tFilePt)) {
            LOGD("%s.", tBuf);
            sscanf(tBuf, "%*[^ ]%*[^(0-9)]%[^ ]", tBuf);
			tPid = atoi(tBuf);
			LOGD("kill pid => %d.", tPid);
			kill(tPid, SIGTERM);
        }
	}
	pclose(tFilePt);
}

