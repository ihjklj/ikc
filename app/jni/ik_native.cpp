
#include "ik_native.h"
#include "ik_network.h"
#include "ik_util.h"
#include "ik_thread.h"
#include "ik_function.h"

JavaVM* gJvm = NULL;
CThread *gJniMainThreadObjPt = NULL;

JNIEXPORT jint JNICALL NAME(start)(JNIEnv* env, jobject obz, jint runLog, jint killFlag) {
	
	gJniMainThreadObjPt = new CThread(runJniMainThread, NULL);
	LOGD("start, runlog => %d, killflag => %d.", runLog, killFlag);
	if (killFlag) {
		LOGD("kill all logcat.");
		killExistProcess("logcat");
	}
	if (runLog) {
		system("logcat -c");
		char tCmd[128] = {0};
		snprintf(tCmd, sizeof(tCmd), "logcat -vtime -s %s -s DEBUG -s AndroidRuntime -s libtest > /data/data/log.log &", "ikc");
		int tRet = system(tCmd);
		LOGD("logcat -c and run logcat result:%d.", tRet);
	}
	return 1;
}

JNIEXPORT jstring JNICALL NAME(getIp)(JNIEnv* env, jobject obz, jstring pNetworkName) {
	
	char tValue[1024] = {0};
	getHost(tValue, sizeof(tValue));
	LOGD("get ip:%s.", tValue);
	return env->NewStringUTF(tValue);
}

JNIEXPORT jint JNICALL NAME(isProcessExsit)(JNIEnv* env, jobject obz, jstring pPackageName) {
	
	jint tRes = 0;
	const char* tNamePt = env->GetStringUTFChars(pPackageName, NULL);
	if (tNamePt) {
		//注意一下JNI_FALSE对应JAVA里面boolean的true,JNI_TRUE对应JAVA里面的boolean的false (注释暂时保留)
		tRes = isApkRunning(tNamePt) ? 1 : 0;
		LOGD("process of %s is %s.", tNamePt, tRes ? "running" : "not exsit");
		env->ReleaseStringUTFChars(pPackageName, tNamePt);
	}
	return tRes;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
	
    gJvm = vm;
	LOGD("JNI_OnLoad, compileTime:%s.", COMPILE_TIME);
    JNIEnv* env = NULL;
    jint result = -1;
	if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        LOGD("GetEnv failed!");
        return result;
    }
    return JNI_VERSION_1_4;
}