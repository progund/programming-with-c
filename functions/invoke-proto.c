#include <stdio.h>


int add(int a, int b) {
    return a+b;
}

int mult_and_print(int a, int b) {
    printf("%d * %d * = %d\n",
           a, b, mult(a,b));
}

int mult(int a, int b) {
    return a*b;
}

int main() {

    mult_and_print(12,34);


}





