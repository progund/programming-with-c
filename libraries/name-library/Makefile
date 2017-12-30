
OBJS=name.o
TEST_PROG=test-prog
.PHONY: test

CFLAGS=-fPIC -pedantic -Wconversion -Wall -Werror -Wextra -Wstrict-prototypes -I. -I..


SHARED_LIB=libname.so
ARCHIVE_LIB=libname.a
%.o:%.c
	gcc -c $(CFLAGS) $< -o $@

test:
	make test-o
	make test-a
	make test-shared

test-o: $(OBJS)
	gcc $(CFLAGS) test/test-name.c $(OBJS) -o $(TEST_PROG)
	./$(TEST_PROG)  > /dev/null 2> /dev/null

test-a: clean $(ARCHIVE_LIB)
	ls -al
	gcc $(CFLAGS) test/test-name.c -L. -lname -o $(TEST_PROG)
	./$(TEST_PROG)  > /dev/null 2> /dev/null
	test `ldd ./$(TEST_PROG) | grep -c name ` -eq 0
	file ./$(TEST_PROG)

test-shared: clean $(SHARED_LIB)
	gcc $(CFLAGS) test/test-name.c -L. -lname -o $(TEST_PROG)
	LD_LIBRARY_PATH=. ./$(TEST_PROG) > /dev/null 2> /dev/null
	file ./$(TEST_PROG)
	ldd ./$(TEST_PROG)
	test `ldd ./$(TEST_PROG) | grep -c name ` -eq 1

$(ARCHIVE_LIB): $(OBJS)
	ar rcu  $(ARCHIVE_LIB) $(OBJS)

$(SHARED_LIB): $(OBJS)
	gcc -shared -o $(SHARED_LIB) $(OBJS)

clean:
	@-rm *~ */*~ *.o $(OBJS)  $(TEST_PROG)  vgco*  $(SHARED_LIB)  $(ARCHIVE_LIB) *.ar *.gch  > /dev/null 2> /dev/null

all: clean shared 
