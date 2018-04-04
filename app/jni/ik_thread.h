
#ifndef __IK_THREAD_H__
#define __IK_THREAD_H__

#include "ik_public.h"
#include <jni.h>
#include <pthread.h>

typedef  int (*PTHREAD_ROUTINE)(void* lParam);

class CThread {
	
public:
    CThread(PTHREAD_ROUTINE func, void *lParam);
    virtual ~CThread();

public:
    static void* runThreadFunc(void *data);
    pthread_t getThreadId() { return mThreadId; }

protected:
    pthread_t           mThreadId;
    void*               mParm;
    PTHREAD_ROUTINE     mThreadFunc;
    bool                mExit;
};

#endif /* __IK_THREAD_H__ */

