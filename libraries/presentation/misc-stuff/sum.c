#include <stdlib.h>

#include "sum.h"

int sum(int size, int *values, int *result)
{
  int i;
  if ( (values == NULL) || (result == NULL) || (size<0) )
    {
      return 1;
    }
  
  *result=0;
  for (i=0; i<size; i++)
    {
      *result += values[i];
    }
  
  return 0;
}

