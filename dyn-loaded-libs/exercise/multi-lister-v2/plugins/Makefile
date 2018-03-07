
PLUGINS=libc-files.so libo-files.so libo-files.so liblib-files.so
CFLAGS= -Wall -pedantic -Werror -Wextra -fno-strict-aliasing -g -fPIC -I../

%.o:%.c
	gcc -c $(CFLAGS) $<

libc-files.so: c-files.o
	gcc $< -shared -o libc-files.so

libo-files.so: o-files.o
	gcc $< -shared -o libo-files.so

liblib-files.so: lib-files.o
	gcc $< -shared -o liblib-files.so

all: $(PLUGINS)
