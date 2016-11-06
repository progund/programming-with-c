#include <stdio.h>

void doubler (int *x) {
  int value = *x;
  value = 2 * value;
  *x = value;
}


int main() {

  doubler(NULL);
  return 0;
}
