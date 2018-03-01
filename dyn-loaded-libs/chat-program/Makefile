CHAT_PROG=chat

CFLAGS= -Wall -Werror -Wextra -fno-strict-aliasing

all: $(CHAT_PROG)

clean:
	-rm *.o *.so *.so *.o $(CHAT_PROG) 
	-find . -name "*~" | xargs rm

$(CHAT_PROG):
	gcc $(CFLAGS) -ldl chat_main.c -o $@

test:$(CHAT_TEST_PROG)
	LD_LIBRARY_PATH=. ./$(CHAT_TEST_PROG) localhost 9999
