#include <stdio.h>

void swap (int *x, int *y) {
     int tmp = *x;
     *x = *y;
     *y = tmp;
}


int main() {

  int girls = 12;
  int boys = 11;

  swap(girls, boys);

  printf ("girls: %d  boys: %d\n",
          girls, boys);
  
  return 0;
}
