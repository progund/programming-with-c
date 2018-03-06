CHAT_PROG=chat

CFLAGS= -Wall -Werror -Wextra -fno-strict-aliasing -Iinterface -I. -g

all: $(CHAT_PROG)

clean:
	-rm *.o *.so *.so *.o $(CHAT_PROG) 
	-find . -name "*~" | xargs rm -f

$(CHAT_PROG):
	gcc $(CFLAGS) -ldl -lpthread chat_main.c -o $@ 

test:$(CHAT_PROG)
	LD_LIBRARY_PATH=. ./$(CHAT_PROG) ../chat-lib/libchat.so localhost 9999

mem:$(CHAT_PROG)
	LD_LIBRARY_PATH=. valgrind --leak-check=full --show-leak-kinds=all ./$(CHAT_PROG) ../chat-lib/libchat.so localhost 9999
