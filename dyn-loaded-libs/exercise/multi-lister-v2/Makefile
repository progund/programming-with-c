OBJS=main.o plugin-loader.o
PROG=fls
CFLAGS= -Wall -Werror -Wextra -fno-strict-aliasing -g -fPIC

%.o:%.c
	gcc -c $(CFLAGS) $<

$(PROG):$(OBJS)
	gcc $(OBJS) -o $(PROG) -ldl

plugin:
	cd plugins && make all

clean:
	rm -f $(PROG) $(OBJS) *~

add:
	find . -name "*.c" -o -name "*.h" -o -name Makefile | xargs git add
