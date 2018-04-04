//
// Created by Administrator on 2018/4/4.
//

#ifndef IKC_IKPUBLIC_H
#define IKC_IKPUBLIC_H

#include <stdio.h>
#include <pthread.h>
#include <android/log.h>

#define LOGD(format, ...) 									\
		do { 												\
			__android_log_print(ANDROID_LOG_DEBUG,			\
					"ikc", 								    \
					"%5d| "format"\n", 					\
					gettid(), 								\
					##__VA_ARGS__); 						\
		} while(0)



#endif //IKC_IKPUBLIC_H
