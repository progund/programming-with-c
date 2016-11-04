#include <stdio.h>

#define PRINT_SIZE(a)   printf ("Size of %.12s:  %lu\n", #a, sizeof(a))

int main() {

  PRINT_SIZE(char);
  PRINT_SIZE(char*);

  PRINT_SIZE(int);
  PRINT_SIZE(int*);
  
  PRINT_SIZE(long);
  PRINT_SIZE(long*);
  
  PRINT_SIZE(long long);
  PRINT_SIZE(long long*);
    
  return 0;
}

