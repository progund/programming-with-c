#include <stdio.h>

/*
 *
 * Program showing how chaning the value of a an int variable via a
 * pointer to its memory works
 *
 */


int main()
{
  int  x  = 12;
  // declare xp as a pointer to int
  // assign it the address of x
  int *xp = &x;
  // xp now points to the address of x

  // declare an int variable y
  // assign it the value of where xp points to
  // *xp means roughly "go to where xp points"
  int  y  = *xp; 

  printf ("x value:   %d \n", x);
  printf ("x address: %p \n", &x);
  printf ("xp:        %p \n", xp);
  printf ("y value:   %d \n", y);
  printf ("y address: %p \n", &y);


  printf ("\n -- extended -- \n");
  printf ("Changing the value of x using xp (which points to x)");
  // dereference xp (which points to x)
  // assign it 24 (y * 2 => 12*2 => 24)
  *xp = y * 2;
  printf ("x value:   %d \n", x);
  printf ("x address: %p \n", &x);
  printf ("xp:        %p \n", xp);
  printf ("y value:   %d \n", y);
  printf ("y address: %p \n", &y);
  
}





