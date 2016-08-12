#include <stdio.h>

int main() {

  int  students;
  int *studentsp;
  
  students = 12;

  studentsp = &students;

  *studentsp = 17;
  
  printf ("students:  %d\n", students);
  printf ("studentsp: %p\n", studentsp);

  return 0;
}
