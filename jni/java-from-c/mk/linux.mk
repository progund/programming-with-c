JNI_PATH=/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.181-7.b13.fc27.x86_64
JNI_INCS=-I$(JNI_PATH)/include -I$(JNI_PATH)/include/linux
JNI_LD_FLAGS=-L$(JNI_PATH)/jre/lib/amd64/server/ -ljvm
LD_LIBRARY=/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.181-7.b13.fc27.x86_64/jre/lib/amd64/server/
#JNI_LIB_NAME=liblove.so
