#include <stdio.h>
#include <stdlib.h>


int main(void)
{
  int *values = calloc(100, sizeof(int));

  if (values==NULL)
    {
      fprintf(stderr, "Failed allocating memory\n");
      return 1;
    }

  values[123]=123;
  printf ("val %d\n", values[178000]);

  return 0;
}
