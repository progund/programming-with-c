SRC=main.c simple-math.c
OBJS=$(SRC:%.c=%.o)

PROG=./mean
VALGRIND=valgrind

CFLAGS=-g

help:
	@echo "How to use this makefile"
	@echo "  make debug - checks calls using debug mode"
	@echo "  make normal - checks calls using normal mode"
	@echo "  make check-time - checks timings using normal mode"

$(PROG): $(OBJS)
	gcc -g $(CFLAGS) -lm $(OBJS) -o $(PROG)

#&& valgrind --tool=callgrind   ./a.out 

$(OBJS): $(SRC)

$(PROG): $(OBJS)

debug-mode: CFLAGS+=-DMATH_DEBUG 
debug-mode: $(OBJS) $(PROG)

debug: clean debug-mode check-call

normal-mode: $(PROG)

normal:clean normal-mode check-call

check-call: 
	$(VALGRIND) --tool=callgrind $(PROG)

gprof: CFLAGS+=-DMATH_DEBUG -pg
gprof: $(PROG)


check-mem: $(PROG)
	$(VALGRIND) $(PROG)

check-time:
	@echo "Debug mode:"
	@make clean debug-mode 2>/dev/null 
	@time $(PROG) 2>/dev/null
	@echo "Normal mode:"
	@make clean normal-mode 2>/dev/null
	@time $(PROG) 2>/dev/null | grep -v mean

dist:
	tar -cvf ../wiki-material.tar *

clean:
	@-rm *.o $(PROG) callgrind.out* *~ callgrap* gmon.out*

