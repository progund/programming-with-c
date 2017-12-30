#
#
#

PROG=main/media-manager
MAIN_OBJS=main/media-manager.o
LIB_A=lib/libmedia.a
LIB_S=lib/libmedia.so
LIB_SRC=lib/mediafile-reader.c lib/medialist.c lib/media-printer.c
OBJS=$(LIB_SRC:%.c=%.o)
CFLAGS=-pedantic -Wconversion -Wall -Werror -Wextra -Wstrict-prototypes -Ilib -Imain

info:
	@echo "OBJS: $(OBJS)"
	@echo "SRC:  $(LIB_SRC)"

%.o:%.c
	gcc -c -fPIC $(CFLAGS) $< -o $@

$(LIB_A): $(OBJS)
	ar rcu $@ $(OBJS)

$(LIB_S): $(OBJS)
	gcc -shared $(OBJS) -o $(LIB_S)

prog-o:clean $(MAIN_OBJS) $(OBJS)
	@echo "---- Linking program from object files ---- "
	gcc  $(MAIN_OBJS) lib/*.o -o $(PROG)
	@echo "---- Examine program from object files ---- "
	@echo "* sizes:"
	du -sb lib/*.o
	du -sb $(PROG)

prog-shared: clean $(LIB_S) $(MAIN_OBJS)
	@echo "---- Linking program from shared library ---- "
	gcc  $(MAIN_OBJS) -Llib -lmedia -o $(PROG)
	@echo "---- Examine program from shared library ---- "
	@echo "* sizes:"
	du -sb lib/*.o
	du -sb $(LIB_S)
	du -sb $(PROG)
	@echo "* prog and lib size:"
	du -bc $(PROG) $(LIB_S)

prog-archive: clean $(LIB_A) main/media-manager.o
	@echo "----  Linking program from archive ---- "
	gcc  $(MAIN_OBJS) -Llib -lmedia -o $(PROG)
	@echo "---- Examine program from archive ---- "
	@echo "* sizes:"
	du -sb lib/*.o
	du -sb $(LIB_A)
	du -sb $(PROG)

clean:
	-rm $(OBJS) *~ $(LIB_A) $(LIB_S) $(PROG) a.out $(MAIN_OBJS)

