#include <stdio.h>
/*
 *
 * Small program to show how to get the address of a variable
 *
 */
int main()
{
  /* declare an int variable - no assignment */
  int x = 12;
  /* print the value */
  printf ("x value:     %d\n", x);
  /* print the address 
     we cast since "%p"expects a void* instead of the int* we supply
  */
  printf ("x address:   %p\n", (void*)&x);

  return 0;
}
