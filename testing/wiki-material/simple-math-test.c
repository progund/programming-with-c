#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "simple-math.h"

#define PRINT_INT_VAR(a) fprintf(stderr, "%s=%d\n", #a, a);

void
test_mean(void)
{
  int arr[] = {2, 2, 1, 4, 100, -100};

  int ret;
  int res;

  /* 2 2 1 => 5 / 3 => 2 (1.666666....)*/
  ret = mean(arr, 3, &res);
  assert(ret==0);
  assert(res==2);

  /* 2 2 1 4 => 9 / 4 => 2 (2.25)*/
  ret = mean(arr, 4, &res);
  assert(ret==0);
  assert(res==2);

  /* 2 2 1 4 100 => 109 / 5 => 22 (21.8...)*/
  ret = mean(arr, 5, &res);
  assert(ret==0);
  assert(res==22);

  /* 2 2 1 4 100 -100 => 9 / 6 => 2 (1.5)*/
  ret = mean(arr, 6, &res);
  assert(ret==0);
  assert(res==2);
}

void
test_null_array(void)
{
  int res;

  assert( (mean(NULL, 1, &res)==1));
}


void
test_negative_size(void)
{
  int arr[] = {2, 2, 1};
  int res;

  assert( (mean(arr, -1, &res)==2));
}

void
test_null_result(void)
{
  int arr[] = {2, 2, 1};

  assert( (mean(arr, 1, NULL)==1));
}


void
test_too_big_sum(void)
{
  int res;
  int arr[] = {INT_MAX, INT_MAX};

  assert( (mean(arr, 2, &res)==3));
}

void
test_too_small_sum(void)
{
  int res;
  int arr[] = {INT_MAX, INT_MAX};

  assert( (mean(arr, 2, &res)==3));
}



int main(void)
{
  DEBUG_INFO();

  test_null_array();

  test_negative_size();
  
  test_null_result();

  test_too_big_sum();

  test_too_small_sum();

  test_mean();

  
}
