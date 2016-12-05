#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "print_array.h"

int
main(void)
{
  int ret ;
  int crap_ints[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

  printf ("Test NULL array: ");
  ret = print_int_array(NULL, 10);
  assert(ret!=0);
  printf (" OK\n");
  
  printf ("Test valid array: ");
  ret = print_int_array(crap_ints, 9);
  assert(ret==0);
  printf ("OK\n");

  return 0;
}
