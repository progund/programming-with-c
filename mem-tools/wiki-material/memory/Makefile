SRC=allocer.c
PROG=./callocer

gperf:
	gcc -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free  -g -ltcmalloc -o $(PROG) $(SRC)
	-rm /tmp/heapprof
	HEAPPROFILE=/tmp/heapprof  HEAPCHECK=strict HEAP_CHECK_TEST_POINTER_ALIGNMENT=1   $(PROG)
	pprof --gv ./callocer /tmp/heapprof*

valgrind:
	gcc  -g -o $(PROG) $(SRC)
	valgrind --leak-check=full $(PROG)
