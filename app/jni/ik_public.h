
#ifndef __IK_PUBLIC_H__
#define __IK_PUBLIC_H__

#include <stdio.h>
#include <unistd.h>
#include <string>
#include <pthread.h>
#include <android/log.h>

using namespace std;

typedef int BOOL;
typedef  int (*PTHREAD_ROUTINE)(void* lParam);

#define TRUE 1
#define FALSE 0
#define COMPILE_TIME __DATE__"@(8)"__TIME__
#define closesocket(x) { shutdown(x, 2); close(x); (x) = -1; }

#define LOGD(format, ...) 									\
		do { 												\
			__android_log_print(ANDROID_LOG_DEBUG,			\
					"ikc", 									\
					"%5d| "format"\n", 					\
					gettid(), 								\
					##__VA_ARGS__); 						\
		} while(0)

#endif /* __IK_PUBLIC_H__ */
