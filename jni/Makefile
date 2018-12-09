UNAME := $(shell uname -s)
CC=gcc

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
ifeq ($(UNAME), CYGWIN_NT-10.0)
  MK_FILE=mk/cygwin.mk
endif
ifeq ($(MK_FILE), missing)
  $(error OS "$(UNAME)" not supported, we are sorry)
else
  include $(MK_FILE)
endif

CLASSES=se/juneday/FromCWithLove.class se/juneday/JNIDemo.class se/juneday/Stupid.class

%.class:%.java
	javac $<

all: $(CLASSES)

run:
	java -Djava.library.path=c se.juneday.JNIDemo

gen-header:
	javah -d c/ se.juneday.FromCWithLove


lib:
	$(CC) $(JNI_LD_FLAGS) $(JNI_INCS) c/lovin_c.c -o c/$(JNI_LIB_NAME)

clean:
	-rm *.o *.so c/*.so c/*.o $(CLASSES)
	-find . -name "*~" | xargs rm
