#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "simple-math.h"

#define ARRAY_SIZE 200000

int main(void)
{
  int ints[ARRAY_SIZE];
  int cnt;
  int i;
  int r;
  int res;
  int ret;

  unset_math_debug();
  
  srand(time(NULL));
  for (i=0; i<ARRAY_SIZE; i++)
    {
      r = rand()%1000;
      ints[i]=r;
    }

  for (cnt=0; cnt < 100 ; cnt ++)
    {
      ret = mean(ints, ARRAY_SIZE, &res);
      if (ret != 0)
        {
      fprintf(stderr, "Failed calculating mean value (%d)\n", ret);
      return 1;
        }
    }
  fprintf(stdout, "Mean value: %d\n", res);
  return 0;
}
