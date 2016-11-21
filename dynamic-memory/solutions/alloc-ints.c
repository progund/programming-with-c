#include <stdlib.h>

int * allocate_ints(size_t nr)
{
  return calloc(nr, sizeof(int));
}

int set_ints(int *ints, int nr)
{
  int i;
  if (ints==NULL)
    {
      return 1;
    }
  for (i=0;i<nr;i++)
    {
      ints[i] = i ;
    }
  return 0;
}

