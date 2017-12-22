PROG=prod
CFLAGS=-pedantic -Wconversion -Wall -Werror -Wextra -Wstrict-prototypes -g


prod:
	gcc $(CFLAGS) src/*.c -o $(PROG)

mem-check: $(PROG)
	valgrind --leak-check=full --show-leak-kinds=all ./$(PROG) files/products.csv

clean:
	-rm */*~ *~ src/*.o $(PROG) 

run:
	./$(PROG)

all: $(PROG) run
