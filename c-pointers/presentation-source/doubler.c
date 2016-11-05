#include <stdio.h>

/*
 *
 * Simple program with a function returning the value of an integer
 * passed to it, multiplied by two
 *
 */ 
int doubler(int x) {
  // x is an int, with a value
  // multiply the value of x with two, and then return the product
  return x * 2;
}

int main() {
  int orig = 12;

  printf ("orig: %d\n", orig);
  // Pass the orig variable (with the value 12) to doubler Since
  // doubler does npt update the variable (try for yourself) we need
  // to store the value returned by doubler in the orig variable.
  orig  = doubler(orig);
  printf ("orig: %d\n", orig);

  return 0;
}
