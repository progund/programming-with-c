#include <stdio.h>

/*
 *
 * Small program to show how to dereference a pointer
 *
 */

int main()
{
  int  x  = 1234;
  int *xp = &x;
  
  printf ("x value:     %d\n", x);
  printf ("x address:   %p\n", (void*)&x);
  printf ("xp:          %p\n", (void*)xp);

  /* Update the mem where xp points to*/
  *xp = 4321;
  printf ("x value:     %d\n", x);

  return 0;
}
