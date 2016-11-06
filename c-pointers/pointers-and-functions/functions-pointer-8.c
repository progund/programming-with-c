#include <stdio.h>

#define swap_int(a,b) int tmp=a; a=b; b=tmp;


int main() {

  int girls = 12;
  int boys = 11;

  printf ("girls: %d  boys: %d\n",
          girls, boys);

  swap_int(girls, boys);

  printf ("girls: %d  boys: %d\n",
          girls, boys);
  
  return 0;
}
