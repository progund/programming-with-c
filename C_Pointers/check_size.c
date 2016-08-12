#include <stdio.h>

int main() {

  printf ("Size of char:  %lu\n", sizeof(char));
  printf ("Size of char*: %lu\n", sizeof(char*));

  printf ("Size of int:   %lu\n", sizeof(int*));
  printf ("Size of int*:  %lu\n", sizeof(int*));
  
  printf ("Size of long:  %lu\n", sizeof(long*));
  printf ("Size of long*: %lu\n", sizeof(long*));

  printf ("Size of long long:  %lu\n", sizeof(long long*));
  printf ("Size of long long*: %lu\n", sizeof(long long*));
  
  return 0;
}

