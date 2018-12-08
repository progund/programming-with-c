
JNI_H=`find /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacO*/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers/jni.h | tail -1)/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers`
JNI_PATH=`dirname JNI_H`
#/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers/
#/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers/
#        /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers/
JNI_INCS=-I$(JNI_PATH)/
JNI_LD_FLAGS=-dynamiclib -fPIC
JNI_LIB_NAME=liblove.jnilib

