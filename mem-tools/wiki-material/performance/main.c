#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "simple-math.h"

#define ARRAY_SIZE 20000

int main(int argc, char **argv)
{
  int ints[ARRAY_SIZE];
  int cnt;
  int i;
  int r;
  int res;
  int ret;


  unset_math_debug();
  if (argc>1)
    {
      fprintf(stderr, "Using debug mode\n");
      set_math_debug();
    }
  
  srand(time(NULL));
  for (i=0; i<ARRAY_SIZE; i++)
    {
      r = rand()%100000;
      ints[i]=r;
    }

  for (cnt=0; cnt < 10 ; cnt ++)
    {
      // READ ERROR - don't go for 101
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
