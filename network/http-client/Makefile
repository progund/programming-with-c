OBJS=webget.o main.o

PROG=webget

CFLAGS=-pedantic -Wconversion -Wall -Werror -Wextra -g

%.o:%.c
	gcc -c $(CFLAGS) $<

all: $(PROG)

$(PROG): $(OBJS)

clean:
	rm -f $(PROG) $(OBJS) *~
