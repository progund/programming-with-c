#include <stdio.h>

/*
 *
 * Simple program:
 *  * printing the value of an int variable 
 *  * print the address of the same variable
 *  * storing and printing a pointer to in variable
 *
 */


int main()
{
  int x   = 12;
  // declare xp as a pointer to int
  // assign it the address of x
  int *xp = &x;
  // xp now points to the address of x
  
  printf ("value:   %d \n", x);
  printf ("address: %p \n", &x);
  printf ("address: %p \n", xp);
}





