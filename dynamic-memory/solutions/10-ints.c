#include <stdio.h>

int main(void)
{
  int *ints = allocate_ints(10);
  if (ints==NULL)
    {
      exit(1);
    }

  set_ints(ints, 10);

  free(ints);
  
  return 0;
}
