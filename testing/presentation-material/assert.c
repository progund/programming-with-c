#include <stdio.h>
#include <assert.h>

int
max(int a, int b)
{
  if (a>b)
    {
      return a;
    }
  return b;
}


void
test_max(void)
{
  printf ("Test max using assert:      ");
  assert (max(13,14)==14);
  printf (" OK\n");
}


int
main(void)
{
  test_max();
}
