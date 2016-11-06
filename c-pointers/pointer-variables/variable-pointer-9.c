#include <stdio.h>

int main() {

  long salary;
  long *salary_ptr;

  salary = 50000; /*dream on*/
  salary_ptr = &salary;

  printf("salary: %lu\n", salary);

  *salary_ptr = 60000;

  printf("salary: %lu\n", salary);
  
  return 0;
}
