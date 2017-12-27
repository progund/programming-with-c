#!/bin/bash

log_exec_cmd()
{
    CMD=$1
    echo "$CMD"
    echo $CMD | bash
    if [ $? -ne 0 ]
    then
        echo "FAILED"
        exit 1
    fi
    
}
PROG=test-prog
exec_prog()
{
    echo "Executing program:"
    ./${PROG}
    echo ""
}

build_nolib()
{
    echo "Using no libraries"
    echo "---------------------------"
    log_exec_cmd "gcc -Ilib lib/*.c test/test-book.c -o ${PROG}"
    exec_prog
}

build_static()
{
    echo "Using archive"
    echo "---------------------------"
    log_exec_cmd "cd lib && gcc -c *.c"
    log_exec_cmd "ar rcu lib/libbook.a lib/book.o lib/author.o"
    log_exec_cmd "gcc -Ilib test/test-book.c -Llib -lbook -o ${PROG}"
    exec_prog
}

build_shared()
{
    echo "Using shared library"
    echo "---------------------------"
    log_exec_cmd "rm lib/lib*.a"
    log_exec_cmd "cd lib && gcc -fPIC -c *.c"
    log_exec_cmd "gcc -shared  -o lib/libbook.so lib/book.o lib/author.o"
    log_exec_cmd "gcc -Ilib test/test-book.c -Llib -lbook -o ${PROG}"
    export LD_LIBRARY_PATH=lib
    exec_prog
}


build_nolib
build_static
build_shared
