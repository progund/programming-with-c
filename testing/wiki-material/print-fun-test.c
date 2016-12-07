#include <assert.h>
#include <stdio.h>
#include "print-fun.h"

int
main(void)
{
  printf ("Start test\n");
  assert (errprint("test")==5);
  printf ("Test finished\n");

  //errprint(NULL);
}

