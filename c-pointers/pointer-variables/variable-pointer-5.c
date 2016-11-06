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
  
  printf ("students:  %d\n", students);
  printf ("studentsp: %p\n", (void*) studentsp);

  return 0;
}
