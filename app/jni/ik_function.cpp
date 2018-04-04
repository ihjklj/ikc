
#include "ik_function.h"

bool gFunctionExit = false;

int runJniMainThread(void *pObjPt) {
	
	while (!gFunctionExit) {
		LOGD("iktest => compileTime:%s.", COMPILE_TIME);
		sleep(30);
	}
	return 1;
}