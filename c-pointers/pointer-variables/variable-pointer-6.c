#include <stdio.h>

/*
 *
 * Program showing how to use pointer variables
 *
 */

int main() {

  int  students;
  int *studentsp;
  
  students = 12;

  studentsp = &students;

  *studentsp = 17;
  
  printf ("students:  %d\n", students);
  printf ("studentsp: %p\n", (void*)studentsp);

  return 0;
}
