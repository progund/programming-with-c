C_FILES=parser.c
MAIN=test/test.c 
PROG=test-parser

all: $(PROG) $(OBJS)

view:
	echo "PROG: $(PROG)"
	echo "OBJS: $(OBJS)"

check: $(PROG) $(OBJS)
	./$(PROG)

clean:
	@-rm -f *.o *~ $(PROG) test/*~ test/*.o



include ../rules.mk



