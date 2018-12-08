JNI_H="$(shell find /cygdrive/c/Program\ Files/Java/jdk* -name "jni.h" | tail -1)"
JNI_PATH=$(shell dirname $(JNI_H))

JNI_INCS=-I"$(JNI_PATH)" -I"$(JNI_PATH)/win32" -D__int64="long long"
JNI_LD_FLAGS= -shared   -Wl,--add-stdcall-alias -shared
JNI_LIB_NAME=love.dll
DEFS=-DCYGWIN

CC=x86_64-w64-mingw32-gcc.exe

