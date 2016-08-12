#include <stdio.h>

#define PRINT_SIZE(a)   printf ("Size of %12s:  %lu\n", #a, sizeof(a))
#define PRINT_SIZES(a)   PRINT_SIZE(a) ; PRINT_SIZE(a*) ;

int main() {

  PRINT_SIZES(char);

  PRINT_SIZES(int);
  
  PRINT_SIZES(long);
  
  PRINT_SIZES(long long);
  
  return 0;
}

