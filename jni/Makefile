CLASSES=se/juneday/FromCWithLove.class se/juneday/JNIDemo.class

%.class:%.java
	javac $<

all: $(CLASSES)

run:
	java -Djava.library.path=c se.juneday.JNIDemo

gen-header:
	javah -d c/ se.juneday.FromCWithLove


JNI_PATH=/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.151-1.b12.fc27.x86_64

lib:
	g++ -shared -fPIC -I$(JNI_PATH)/include -I$(JNI_PATH)/include/linux c/lovin_c.c -o c/liblove.so

clean:
	-rm *.o *.so c/*.so c/*.o $(CLASSES)
	-find . -name "*~" | xargs rm
