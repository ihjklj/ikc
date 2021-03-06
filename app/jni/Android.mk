LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := test
LOCAL_C_INCLUDES := $(LOCAL_PATH) $(NDK)/sources/cxx-stl/stlport/stlport
LOCAL_SRC_FILES := ik_native.cpp \
					ik_network.cpp \
					ik_thread.cpp \
					ik_function.cpp \
					ik_util.cpp \
					ik_socket_client.cpp
LOCAL_CFLAGS := -static
LOCAL_LDLIBS := -pthread -dl
LOCAL_LDFLAGS := -L. -lc -lstdc++ -llog
LOCAL_LDLIBS := -L. -lc -llog -ldl -lz

//LOCAL_CFLAGS += -pie -fPIE
//LOCAL_LDFLAGS += -pie -fPIE

#会生成依赖关系，当库不存在时会去编译这个库。
#LOCAL_SHARED_LIBRARIES 
include $(BUILD_SHARED_LIBRARY)
#include $(BUILD_EXECUTABLE)

