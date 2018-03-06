OBJS=main.o
PROG=fls
CFLAGS= -Wall -pedantic -Werror -Wextra -fno-strict-aliasing -g -fPIC

%.o:%.c
	gcc -c $(CFLAGS) $<

$(PROG):$(OBJS)
	gcc $(OBJS) -o $(PROG)

clean:
	rm -f $(PROG) $(OBJS) *~

add:
	find . -name "*.c" -o -name "*.h" -o -name Makefile | xargs git add
