UNAME := $(shell uname -s)

MK_FILE=missing
ifeq ($(UNAME), Linux)
  MK_FILE=mk/linux.mk
endif
ifeq ($(UNAME), Darwin)
  MK_FILE=mk/macos.mk
endif
ifeq ($(UNAME), CYGWIN_NT_5.1)
  MK_FILE=mk/linux.cygwin
endif
ifeq ($(MK_FILE), missing)
  $(error OS "$(UNAME)" not supported, we are sorry)
else
  include $(MK_FILE)
endif

CLASSES=se/juneday/Stupid.class
PROG=main

%.class:%.java
	@echo "Compile " $<
	@javac $<

all: $(CLASSES) $(PROG)



main.o: main.c
	@echo "Compile main.c"
	@gcc -c $(JNI_INCS) $< -o main.o

$(PROG): main.o
	@echo "Link main.o"
	@gcc $(JNI_LD_FLAGS) $< -o $(PROG)

run:
	@echo 
	@echo "Running program" 
	@LD_LIBRARY_PATH=$(LD_LIBRARY) ./$(PROG) 

clean:
	@echo "Cleaning up"
	@-rm -f *.o *.so c/*.so c/*.o $(CLASSES) $(PROG) hs_err* a.out
	@-find . -name "*~" | xargs rm -f
	@-find . -name "*.class" | xargs rm -f 
	@-find . -name "*.o" | xargs rm -f
	@echo " * all cleaned up  :)"
	@echo 
