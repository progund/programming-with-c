#include <stdio.h>


int
errprint(char *str)
{
  return fprintf(stderr, "%s\n", str);
}
