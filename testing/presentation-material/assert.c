#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "simple-math.h"



void
test_max(void)
{
  printf ("Test max using assert:      ");
  assert (max(13,14)==14);
  assert (max(14,13)==14);
  /* assert (max(INT_MAX,14)==INT_MAX); */
  /* assert (max(INT_MAX,INT_MIN)==INT_MAX); */
  /* assert (max(-23000,INT_MIN)==-23000); */
  printf (" OK\n");
}

void
test_mean(void)
{
  int res;
  int ints[] = { 12, 13, 14 };
  printf ("Test mean using assert:      ");
  int ret = mean(ints, 3, NULL);
  assert(ret != 0);
  ret = mean(NULL, 3, &res);
  assert(ret != 0);
  printf (" OK\n");
}

void
test_mean2(void)
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
