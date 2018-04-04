
#include "ik_thread.h"

extern JavaVM* gJvm;

CThread::CThread(PTHREAD_ROUTINE func, void *lParm) {

	mThreadId = 0L;
    mThreadFunc = func;
    mParm = lParm;
    mExit = false;
    if (pthread_create(&mThreadId, NULL, runThreadFunc, this) == 0){
        pthread_detach(mThreadId);
		//LOGD("run thread:%ld.", mThreadId);
    }
	else {
		LOGD("run thread failed!");
	}
}

CThread::~CThread() {
    //
}

void* CThread::runThreadFunc(void *data) {
	
	JNIEnv* env = NULL;
	if (gJvm != NULL)
		gJvm->AttachCurrentThread(&env, NULL);
    CThread *threadThis = (CThread *)data;
    threadThis->mThreadFunc(threadThis->mParm);
    threadThis->mExit = true;
	if (env == NULL)
		gJvm->AttachCurrentThread(&env, NULL);
	if (env != NULL)
		gJvm->DetachCurrentThread();
    pthread_exit(0);
    return NULL;
}

