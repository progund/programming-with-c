#include <stdio.h>
#include <assert.h>
#include "simple-math.h"



void
test_max(void)
{
  printf ("Test max using assert:      ");
  assert (max(13,14)==14);
  printf (" OK\n");
}

void
test_mean(void)
{
  int test_arr_1[] = { 1, 2, 3, 4 };
  int ret;
  int res;
  
  printf ("Test mean using assert:      ");
  ret = mean(test_arr_1, 4, &res);
  assert(ret == 0);
  assert(res == 3);
  printf (" OK\n");
}


int
main(void)
{
  test_max();

  test_mean();
}
