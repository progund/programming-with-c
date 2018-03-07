#include <stdlib.h>
#include "mean.h"

int mean(int size, int *values, double *result)
{
  int i;
  int sum;
  if ( (values == NULL) || (result == NULL) || (size<0) )
    {
      return 1;
    }

  sum=0;
  for (i=0; i<size; i++)
    {
      sum += values[i];
    }
  
  *result = ((double)sum)/size;

  return 0;
}

