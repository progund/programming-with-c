JNI_H=$(shell find /usr/lib/jvm -name "jni.h" | tail -1)
JNI_PATH=$(shell dirname $(JNI_H))
JNI_INCS=-I$(JNI_PATH) -I$(JNI_PATH)/linux
JNI_LD_FLAGS=-shared -fPIC
JNI_LIB_NAME=liblove.so
