#include <stdio.h>


void
print_int_array(int *array, int size)
{
  int i ;
  for (i=0;i<size;i++)
    {
      printf("array[%d]: %d\n", i, array[i]);
    }
}


int
main(void)
{
  int crap_ints[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

  print_int_array(crap_ints, 10);

  return 0;
}
