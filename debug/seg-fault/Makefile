PROG=store
OBJS=store.o

# If using proper flags, gcc will detect the stupidities
#CFLAGS=	-pedantic -Wconversion -Wall -Werror -Wextra -Wstrict-prototypes


all: $(PROG)

$(PROG): $(OBJS)
	gcc $(OBJS) -o $(PROG)

%.o:%.c
	gcc -g -c $(CFLAGS) $< 

clean:
	-rm -f $(OBJS) $(PROG) *~ 
