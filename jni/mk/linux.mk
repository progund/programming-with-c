JNI_PATH=/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.151-1.b12.fc27.x86_64
JNI_INCS=-I$(JNI_PATH)/include -I$(JNI_PATH)/include/linux
JNI_LD_FLAGS=-shared -fPIC
JNI_LIB_NAME=liblove.so
