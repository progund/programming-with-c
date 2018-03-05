CHAT_LIB=libchat.so
CHAT_TEST_PROG=chat_main

CHAT_INTERFACE_PATH=../chat-program/interface

CFLAGS= -Wall -Werror -Wextra -fno-strict-aliasing -I$(CHAT_INTERFACE_PATH) -g

all: $(CHAT_LIB)

$(CHAT_LIB):
	gcc $(CFLAGS) -DDEBUG -shared -fPIC  chat-lib.c -o $(CHAT_LIB)

lib: $(CHAT_LIB)

clean:
	-rm *.o *.so *.so *.o $(CHAT_LIB)  $(CHAT_TEST_PROG) 
	-find . -name "*~" | xargs rm

$(CHAT_TEST_PROG): $(CHAT_LIB) 
	gcc $(CFLAGS) -L. -lchat chat_main.c -o $(CHAT_TEST_PROG) -lpthread

test:$(CHAT_TEST_PROG)
	LD_LIBRARY_PATH=. ./$(CHAT_TEST_PROG) localhost 9999
