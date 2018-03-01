PROG=fp
SOURCES=fp.c 
OBJS=fp.o
CFLAGS=-pedantic -Wconversion -Wall -Werror -Wextra -Wstrict-prototypes -g
CC=gcc

%.o:%.c
	$(CC) -c $(CFLAGS) $<

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS) $(PROG) *.o *~ a.out
