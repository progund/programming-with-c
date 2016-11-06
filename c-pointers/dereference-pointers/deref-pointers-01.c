#include <stdio.h>

/*
 *
 * Small program to show how to dereference a pointer
 *
 */

int main()
{
  int  x  = 12;
  int *xp = &x;
  
  printf ("x value:     %d\n", x);
  printf ("x address:   %p\n", (void*)&x);
  printf ("xp:          %p\n", (void*)xp);


  return 0;
}
