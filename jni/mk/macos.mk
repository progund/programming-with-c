
JNI_H=`find /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacO*/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers/jni.h | tail -1)`
JNI_PATH=`dirname JNI_H`
JNI_INCS=-I$(JNI_PATH)/
JNI_LD_FLAGS=-dynamiclib -fPIC
JNI_LIB_NAME=liblove.jnilib

