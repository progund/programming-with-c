#include <stdio.h>
#include "print_array.h"


int
main(void)
{
  int crap_ints[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

  print_int_array(crap_ints, 10);

  return 0;
}
