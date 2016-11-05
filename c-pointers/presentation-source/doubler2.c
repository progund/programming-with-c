/*
 *
 * Simple program showing a function taking a pointer to int as
 * argument and doubles the value of the int.
 *
 */

#include <stdio.h>

void doubler(int *xp) {
  // xp points to an int

  
  *xp = *xp * 2;
  // *xp      think of this as, "go to where xp points"
  // =        it's an ordinary assignment
  // *xp * 2  the value where xp points to, multiplied by two
}

int main() {
  int orig = 12;

  printf ("orig: %d\n", orig);
  // Don't pass the value of x. Rather pass the address of x. TO do
  // that we use the address of operator (&).
  doubler(&orig);
  printf ("orig: %d\n", orig);

  return 0;
}
