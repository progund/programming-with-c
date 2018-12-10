# Introduction

This source code is part of a tutorial on JNI. The tutorial (and possible videos) are linked from here: [http://wiki.juneday.se/mediawiki/index.php/Chapter:C_extra_JNI]

# Setting up your environment

## Cygwin

Copy/paste the following in to a terminal running bash:
~~~
CC=x86_64-w64-mingw32-gcc
JDKS_DIR=$(find /cygdrive/c/Program\ Files/Java/jdk* -prune -type d) 
JDK_INC_DIR=$(dirname "$(find "$JDKS_DIR" -name "jni.h" | tail -1)")
JDK_C_FLAGS="-I\"$JDK_INC_DIR\" -I\"$JDK_INC_DIR/win32\" -D__int64=\"long long\""
JDK_LD_FLAGS=" -shared   -Wl,--add-stdcall-alias -o c/love.dll"
JDK_LIB_DIR1="$(find "$JDK_INC_DIR"/../ -name 'jvm.dll')"
JDK_LIB_DIR="$(dirname "$JDK_LIB_DIR1")"
~~~

## MacOS

Copy/paste the following in to a terminal running bash:
~~~
CC=gcc
JDKS_DIR=$(find /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacO* -prune -type d)
JDK_INC_DIR=$(dirname $(find $JDKS_DIR -name "jni.h" | tail -1));
JDK_C_FLAGS=" -I\"$JDK_INC_DIR\"  -fPIC "
JDK_LD_FLAGS=" -dynamiclib -o c/liblove.jnilib"
JDK_LIB_DIR=$(dirname $(find $(/usr/libexec/java_home) -name "libjvm.dylib"))
~~~

## GNU/Linux

Copy/paste the following in to a terminal running bash:
~~~
CC=gcc
JDKS_DIR=$(find /usr/lib/jvm/* -prune -type d); 
JDK_INC_DIR=$(dirname $(find $JDKS_DIR -name "jni.h" | tail -1)); 
JDK_C_FLAGS="-I\"$JDK_INC_DIR\" -I\"$JDK_INC_DIR/linux\"  "
JDK_LD_FLAGS=" -shared -fPIC -o c/liblove.so"
JDK_LIB_DIR=$(dirname $(find $JDK_INC_DIR/../ -name "libjvm.so"))
~~~

# Use C code from Java

## Compile Java source code
~~~
$ javac se/juneday/FromCWithLove.java
$ javac se/juneday/JNIDemo.java
~~~
## Compile C source code
~~~
javah se.juneday.FromCWithLove
eval $CC  $JDK_C_FLAGS $JDK_LD_FLAGS c/lovin_c.c
~~~
## Execute Java program (using C lib)
~~~
java -Djava.library.path=c se.juneday.JNIDemo
~~~


# Use Java code from C

## Compile Java source code
~~~
$ javac se/juneday/Stupid.java
~~~
## Compile C source code
~~~
eval $CC -L"$JDK_LIB_DIR" $JDK_C_FLAGS -ljvm c/c-program.c -o c/c-program
~~~
## Execute C program (using Java class)
### Cygwin
~~~
PATH="$JDK_LIB_DIR":PATH ./c/c-program
~~~
### MacOS/GNU/linux
~~~
LD_LIBRARY_PATH="$JDK_LIB_DIR" ./c/c-program
~~~


