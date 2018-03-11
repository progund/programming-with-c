SRC=main.c simple-math.c
OBJS=$(SRC:%.c=%.o)

PROG=./mean
VALGRIND=valgrind

CFLAGS=-g

help:
	@echo "How to use this makefile"
	@echo "  normal - just run the program (debug unset)"
	@echo "  debug - just run the program with debug set"
	@echo "  check-mem - check memory leaks/reads/writes"
	@echo "  debug-calls - checks calls using debug mode"
	@echo "  normal-calls - checks calls using normal mode"
	@echo "  check-normal-time - checks timings using normal mode"
	@echo "  check-time-set - checks timings using debug mode and set_debug_mode"
	@echo "  check-time-unset - checks timings using debug mode and unset_debug_mode"

$(PROG): $(OBJS)
	gcc -g $(CFLAGS) -lm $(OBJS) -o $(PROG)

#&& valgrind --tool=callgrind   ./a.out 

$(OBJS): $(SRC)

$(PROG): $(OBJS)

normal: $(PROG)
	$(PROG)

debug:  clean debug-mode
	$(PROG)

debug-mode: CFLAGS+=-DMATH_DEBUG 
debug-mode: $(OBJS) $(PROG)

debug-calls: clean debug-mode check-call
	kcachegrind `ls callgrin*`

normal-calls:clean $(PROG) check-call
	kcachegrind `ls callgrin*`

check-call: 
	$(VALGRIND) --tool=callgrind $(PROG)

gprof: CFLAGS+=-DMATH_DEBUG -pg
gprof: $(PROG)


check-mem: $(PROG)
	$(VALGRIND) $(PROG)


check-normal-time: 
	@echo "Normal mode:"
	@make clean $(PROG) 
	@echo time $(PROG) | bash

check-time-unset: 
	@echo "Debug enabled with unset_debug  :"
	@make clean debug-mode 
	@echo time $(PROG) | bash

check-time-set: 
	@echo "Debug enabled with set_debug  :"
	@make clean debug-mode 
	@echo time $(PROG) extra args  | bash

dist:
	tar -cvf ../wiki-material.tar *

clean:
	@-rm *.o $(PROG) callgrind.out* *~ callgrap* gmon.out*

