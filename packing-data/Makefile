C_FILES=main.c vehicle/bus.c pack/pack.c
H_FILES=vehicle/bus.h log/log.h pack/pack.h

OBJS=$(C_FILES:%.c=%.o)

DEBUG_FLAGS=-DDEBUG 
LOG_FLAGS=-DLOG_TO_FILE 
CFLAGS=-pedantic -Wall -Werror  -DFAKE_BUS_IMPLEMENTATION -I.
LDFLAGS=
CC=gcc
PROG=magic-bus

all: $(PROG)

$(PROG): $(OBJS)
	@echo Creating program $@
	gcc $(OBJS) -o $@

$(OBJS): $(H_FILES) Makefile

debug: CFLAGS+=$(LOG_FLAGS) $(DEBUG_FLAGS) 
debug: $(PROG) 

log: CFLAGS+=$(LOG_FLAGS) 
log: $(PROG) 

%.o:%.c
	@echo Compiling $<
	$(CC) $(CFLAGS) -c -o $@ $<

files:
	@echo H files: $(H_FILES)
	@echo C files: $(C_FILES)
	@echo Objects: $(OBJS)

clean:
	-rm -f *.o */*.o *~ */*~  $(OBJS) $(PROG) 


