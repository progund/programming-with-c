
CFLAGS=-pedantic -Wconversion -Wall -Werror  -Wextra -Wstrict-prototypes -g 


cunit:
	gcc cu-max.c simple-math.c -lcunit -lm -o cu-max
	./cu-max

check:
	gcc check-max.c simple-math.c -lm  -lcheck -lrt  -pthread -lsubunit -o check-max && ./check-max

assert:
	gcc assert.c simple-math.c -lm  -lcheck -lrt  -pthread -lsubunit -o assert && ./assert


gcov:
	gcc $(CFLAGS) --coverage -fprofile-arcs -ftest-coverage assert.c simple-math.c -o assert -lm
	./assert
	gcov -b simple-math.c

lcov: gcov 
	lcov --directory .  --capture --output-file  simple-math.info && genhtml -o coverage simple-math.info 

all: cunit check gcov lcov

clean:
	rm -fr *.xml *~ *.gcda *.o *.gcno *.info cu-max check-max assert coverage
