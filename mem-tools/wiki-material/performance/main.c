#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "simple-math.h"

/* #define ARRAY_SIZE 200000 */

int main(void)
{
  int ints[100];
  int cnt;
  int i;
  int r;
  int res;
  int ret;

  unset_math_debug();
  
  srand(time(NULL));
  for (i=0; i<100; i++)
    {
      r = rand()%1000;
      ints[i]=r;
    }

  for (cnt=0; cnt < 100 ; cnt ++)
    {
      // READ ERROR - don't go for 101
      ret = mean(ints, 101, &res);
      if (ret != 0)
        {
      fprintf(stderr, "Failed calculating mean value (%d)\n", ret);
      return 1;
        }
    }
  
  fprintf(stdout, "Mean value: %d\n", res);
  return 0;
}
