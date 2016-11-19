#include <stdlib.h>

int * allocate_ints(int nr)
{
  return calloc(sizeof(int), nr);
}

int set_ints(int *ints, int nr)
{
  int i;
  if (ints==NULL)
    {
      return 1;
    }
  for (i=0;i<10;i++)
    {
      ints[i] = i ;
    }
  return 0;
}

