
#ifndef __IK_NATIVE_H__
#define __IK_NATIVE_H__

#include <jni.h>

#define CLASS Java_com_ihjklj_ikc_cnative_IkNativeMethod_
#define NAME2(CLS, FUNC) CLS##FUNC
#define NAME1(CLS, FUNC) NAME2(CLS, FUNC)
#define NAME(FUNC) NAME1(CLASS, FUNC)

#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT jint JNICALL NAME(start)(JNIEnv* env, jobject obz, jint runLog, jint killFlag);
JNIEXPORT jstring JNICALL NAME(getIp)(JNIEnv* env, jobject obz, jstring pNetworkName);
JNIEXPORT jint JNICALL NAME(isProcessExsit)(JNIEnv* env, jobject obz, jstring pPackageName);

#ifdef __cplusplus
}
#endif
#endif /* __IK_NATIVE_H__ */
