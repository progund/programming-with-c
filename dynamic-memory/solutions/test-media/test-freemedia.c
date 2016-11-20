#include <stdio.h>
#include <assert.h>
#include "../medialist.h"




int main(void)
{
  medialist list;
  int ret;

  printf ("Init medialist; ");
  ret = init_medialist(&list);
  assert(ret==MEDIALIST_OK);
  assert(list.size==0);
  assert(list.list==NULL);
  printf (" OK\n");

  printf ("Free medialist; ");
  ret = free_medialist(&list);
  assert(ret==MEDIALIST_OK);
  printf (" OK\n");

  printf ("Free bad medialist; ");
  ret = free_medialist(NULL);
  assert(ret==MEDIALIST_INVALID_ARGUMENTS);
  printf (" OK\n");

  return 0;
}
