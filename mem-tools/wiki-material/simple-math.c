#include <stdio.h>
#include <limits.h>
#include <math.h>

#include "simple-math.h"

#ifdef MATH_DEBUG
#define PRINT_INT_VAR(a) { print_int_var(#a, a); }
#else
#define PRINT_INT_VAR(a)
#endif

static int math_debug_mode = 0;

void set_math_debug(void)
{
  math_debug_mode=1; 
}

void unset_math_debug(void)
{
  math_debug_mode=0; 
}

void print_int_var(char *str, int val)
{
  if (math_debug_mode)
    {
      fprintf(stderr, "%s=%d\n", str, val);
    }
}

int
max(int a, int b)
{
  if (a>b)
    {
      return a;
    }
  return b;
}


int
mean(int *array, int size, int *result)
{
  int i ;
  // Store the sum in a long long instead
  long long sum;
  
  if ( (array==NULL) || (result==NULL) )
    {
      return 1;
    }

  if (size<0)
    {
      return 2;
    }
  
  // initialise sum to 0
  sum = 0 ;
  for (i=0; i<size; i++)
    {
      int val = array[i];
      PRINT_INT_VAR(val);
      // add the value to sum
      sum = sum + val;

      // Check if the sum fits in an int
      if ((sum>INT_MAX) || (sum<INT_MIN) )
        {
          return 3;
        }
      PRINT_INT_VAR(sum);
    }

  *result = (int)round(((double)sum/(double)size));
  return 0;
}
