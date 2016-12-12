#include <stdio.h>
#include <stdlib.h>


int main(void)
{
  int *values = calloc(100, sizeof(int));

  if (values==NULL)
    {
      fprintf(stderr, "Failed allocating memory\n");
    }

  values[123]=123;
  printf ("val %d\n", values[178]);

  return 0;
}
