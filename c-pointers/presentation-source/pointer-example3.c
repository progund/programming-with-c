#include <stdio.h>


int main()
{
  int  x  = 12;
  int *xp = &x;
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





