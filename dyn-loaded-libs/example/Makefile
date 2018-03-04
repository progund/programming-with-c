ARCHIVE=libcode.a
SHARED=libcode.so
OBJS=code.o
MAIN_FILE=classic-main.c
DYN_MAIN_FILE=dyndl-main.c
CFLAGS= -Wall -Werror -Wextra -fno-strict-aliasing -g -fPIC

%.o:%.c
	gcc -c $(CFLAGS) $<

$(ARCHIVE): $(OBJS)
	ar rcv $(ARCHIVE) $(OBJS)

$(SHARED): $(OBJS)
	gcc -fPIC -shared $(OBJS) -o $(SHARED)

static-main: $(ARCHIVE)
	gcc $(MAIN_FILE) -L. -lcode -o $@ 

shared-main: $(SHARED)
	gcc $(MAIN_FILE) -L. -lcode -o $@ 

dyn-main: 
	gcc $(CFLAGS) $(DYN_MAIN_FILE) -o $@ -ldl

clean:
	rm -f $(OBJS) *.a *.so *.o *~ dyn-main classic-main
