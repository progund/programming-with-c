#include <stdio.h>
#include "lib/mean.h"
#include "lib/sum.h"


int main(void)
{
  int values[] = { 3, 1, 4 };
  double mean_result;
  int sum_result;

  if (mean(3, values, &mean_result)==0)
    {
      printf ("mean: %.20f\n", mean_result);
    }
  else
    {
      printf ("failed calculating mean value\n");
    }      

  if (sum(3, values, &sum_result)==0)
    {
      printf ("sum: %d\n", sum_result);
    }
  else
    {
      printf ("failed calculating sum\n");
    }      
  return 0;
}
