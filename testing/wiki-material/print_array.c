#include <stdio.h>

int
print_int_array(int *array, int size)
{
  int i ;

  if (array==NULL)
    {
      return 1;
    }
  
  for (i=0;i<size;i++)
    {
      printf("array[%d]: %d\n", i, array[i]);
    }

  return 0;
}



