#include <stdio.h>

void doubler(int *xp) {
  *xp = *xp * 2;
}

int main() {
  int orig = 12;

  printf ("orig: %d\n", orig);
  doubler(&orig);
  printf ("orig: %d\n", orig);


  return 0;
}
