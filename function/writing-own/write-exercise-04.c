#include <stdio.h>
#include "mathematics.h"

int main()
{
  int ret = min(12, 13);
  if (ret != 12)
    {
      printf("Test failed\n");
    }
  
  ret = min(13, 12);
  if (ret != 12)
    {
      printf("Test failed\n");
    }
  printf ("All tests performed - if no error all passed\n");
}
