PROG=prod
CFLAGS=-pedantic -Wconversion -Wall -Werror -Wextra -Wstrict-prototypes -g

files/products.csv:
	bin/download.sh

download: files/products.csv

prod:
	gcc $(CFLAGS) src/*.c -o $(PROG)

db:$(PROG)
	-rm files/products.db
	./$(PROG) files/small.csv | sqlite3 files/products.db
	@echo "SELECT COUNT(*) FROM product"     | sqlite3 files/products.db
	@echo "SELECT COUNT(*) FROM productGroup" | sqlite3 files/products.db

big-db:$(PROG)
	-rm files/products.db
	./$(PROG) files/products.csv | sqlite3 files/products.db
	@echo "SELECT COUNT(*) FROM product"     | sqlite3 files/products.db
	@echo "SELECT COUNT(*) FROM productGroup" | sqlite3 files/products.db

mem-check: $(PROG) 
	valgrind --leak-check=full --show-leak-kinds=all ./$(PROG) files/small.csv

big-mem-check: $(PROG) files/products.csv
	valgrind --leak-check=full --show-leak-kinds=all ./$(PROG) files/products.csv

clean:
	-rm */*~ *~ src/*.o $(PROG) 

cleanup:
	-rm */*~ *~ src/*.o $(PROG) files/*


run:
	./$(PROG)

all: $(PROG) run
