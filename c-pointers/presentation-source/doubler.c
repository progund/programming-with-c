#include <stdio.h>

int doubler(int x) {
  return x * 2;
}

int main() {
  int orig = 12;

  printf ("orig: %d\n", orig);
  orig  = doubler(12);
  printf ("orig: %d\n", orig);

  return 0;
}
