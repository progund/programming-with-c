#include <stdio.h>

int main() {

  int  students;
  int *studentsp;
  
  students = 12;

  studentsp = &students;
  
  printf ("students: %d\n", students);

  return 0;
}
