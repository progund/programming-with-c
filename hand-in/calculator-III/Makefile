# Compiler settings
CC=gcc
LD=gcc

# Source code
CFLAGS=-pedantic -Wconversion -Wall -Werror  -Wextra -Wstrict-prototypes -g -I.
SRC=expression.c  parser.c strtoint.c interactive.c
OBJS=$(SRC:%.c=%.o)
PROG=calc


# code for testing expression
TEST_EXPR_SRC=test/test-expr.c
TEST_EXPR_OBJS=$(TEST_EXPR_SRC:%.c=%.o)
TEST_EXPR=test/test-expr

# code for testing parser
TEST_PARSE_SRC=test/test-parse.c
TEST_PARSE_OBJS=$(TEST_PARSE_SRC:%.c=%.o)
TEST_PARSE=test/test-parse



# Target/rule to compile c files
%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@ 

# Target/rule to build calc
$(PROG): $(OBJS) main.o
	$(LD) $(OBJS) main.o -o $@

# Target/rule to create distribution (zip and tar.gz)
dist: clean
	-rm -f *.zip *.tar *.tar.gz
	zip -r calc-handin.zip *
	tar zcvf calc-handin.tar.gz *

# Target/rule to clean up code
clean:
	-rm -f *~ $(OBJS) *.gch $(PROG) *.zip *.tar *.tar.gz *.o $(TEST_EXPR) $(TEST_PARSE) test/*.o test/*~ *.pdf
	-rm -fr latex html

# Target/rule to create test program for expression
$(TEST_EXPR): $(OBJS) $(TEST_EXPR_OBJS) 
	$(LD) $(OBJS) $(TEST_EXPR_OBJS) -o $(TEST_EXPR)

# Target/rule to create test program for parser
$(TEST_PARSE): $(OBJS) $(TEST_PARSE_OBJS)
	$(LD) $(OBJS) $(TEST_PARSE_OBJS) -o $(TEST_PARSE)

# exec expr test
expr: $(TEST_EXPR)
	@echo "Testing passed"
	./$(TEST_EXPR)
	@echo ""
	@echo "Test of expression passed"

# exec parser test
parse: $(TEST_PARSE)
	@echo "Testing parse passed"
	./$(TEST_PARSE)
	@echo ""
	@echo "Test of parse passed"

# target to make it easy to check it all, type:
#    make check
check: $(PROG) expr parse
	./test/test-suite.sh
	@echo
	@echo
	@echo
	@echo "----- summary---------"
	@echo "expr unit test:  pass"
	@echo "parse unit test: pass"
	@echo "test suite:      pass"
	@echo "----------------------"

#
# Rules to check mem when executing test code and the "real" program
#
mem-check-expr: $(TEST_EXPR) 
	valgrind   $(TEST_EXPR)

mem-check-parse: $(TEST_PARSE)
	valgrind   $(TEST_PARSE)

mem-check: $(PROG)
	valgrind   ./$(PROG) 1 + 1
	valgrind   ./$(PROG) 1 + a

doc:
	doxygen
	cd latex && make pdf
	mv latex/refman.pdf calc-api.pdf
