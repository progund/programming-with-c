MAIN=main

OBJS=parser.o main.o

CFLAGS=-pedantic -Wall -Wconversion -Werror

%.o:%.c
	gcc $(CFLAGS) -c $< -o $@

$(MAIN): $(OBJS)
	gcc $(OBJS) -o $(MAIN)

all: $(OBJS) $(MAIN)

clean:
	rm $(OBJS) *~

run: $(MAIN)
	./$(MAIN) one 
	./$(MAIN) one two 
	./$(MAIN) one two three
	./$(MAIN) --long --short --long --short --long --short
	./$(MAIN) --long --short --long --short --long --short34
