#include <stdio.h>

void doubler (int *x) {
  /* store the value pointed to by x, in value */
  int value = *x;

  /* double value */
  value = 2 * value;

  /* write the value of value (hmmm?) to the mem pointed to by x */ 
  *x = value;

  
  // This is how I would have written it:
  // *x = *x * 2;

  // perhaps the solution above was easier to understand?
}

int main() {

  int salary = 20000;
  
  printf ("SalarY: %d\n",
          salary);

  doubler(&salary);
  
  printf ("SalarY: %d\n",
          salary);
  
  return 0;
}

