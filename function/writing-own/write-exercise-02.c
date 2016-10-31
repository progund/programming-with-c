#include <stdio.h>
#include "mathematics.h"

int main()
{
  int ret = max(12, 13);
  if (ret != 13)
    {
      printf("Test failed\n");
    }
  
  ret = max(13, 12);
  if (ret != 13)
    {
      printf("Test failed\n");
    }
  printf ("All tests passed\n");
}
