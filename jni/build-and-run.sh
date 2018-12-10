#!/bin/bash

if [ "$(uname  | grep -ic linux)" != "0" ]
then
    OS=linux
elif [ "$(uname  | grep -ic darwin)" != "0" ]
then
    OS=macos
elif [ "$(uname  | grep -ic cygwin)" != "0" ]
then
    OS=cygwin
else
    echo "$(uname) not supported"
    exit 1
fi

. setup.$OS

exit_on_error() {
    if [ $1 -ne 0 ]
    then
        if [ $2 -! "" ]
        then
            echo "Failed: $2"
        else
            echo "Failed"
        fi
        exit $1
    fi
}



using_c_from_java()
{
    echo
    echo 
    echo "--=== Using C code from Java ===---"
    echo -n "Compiling java code: "
    javac se/juneday/FromCWithLove.java &&  javac se/juneday/JNIDemo.java
    exit_on_error $?
    echo "OK"

    echo -n "Creating C header files from Java source code: "
    javah se.juneday.FromCWithLove
    exit_on_error $?
    echo "OK"

    echo -n "Compiling C code: "
    eval $CC  $JDK_C_FLAGS $JDK_LD_FLAGS c/lovin_c.c
    exit_on_error $?
    echo "OK"

    echo -n "Executing Java program (using C lib): "
    java -Djava.library.path=c se.juneday.JNIDemo
    exit_on_error $?
    echo "OK"

}

using_java_from_c()
{
    echo
    echo 
    echo "--=== Using Java code from C ===---"
    echo -n "Compiling Java source code: "
    javac se/juneday/Stupid.java
    exit_on_error $?
    echo "OK"

    echo -n "Compiling C source code: "
    eval $CC -L\"$JDK_LIB_DIR\" $JDK_C_FLAGS -ljvm c/c-program.c -o c/c-program
    exit_on_error $?
    echo "OK"

    echo -n "Executing C program (using Java code): "
    if [ "$OS" = "cygwin" ]
    then
        PATH="$JDK_LIB_DIR":$PATH ./c/c-program
    else
        LD_LIBRARY_PATH="$JDK_LIB_DIR" ./c/c-program
        exit_on_error $?
    fi
    echo "OK"

}

using_c_from_java
using_java_from_c


echo
echo 
echo "--=== Wrapping it up ===---"
echo "Using C code from Java worked fine"
echo "Using Java code from C worked fine"

