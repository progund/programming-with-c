#include <stdio.h>

#include "code.h"

void fancy_printing(char *str)
{
  fprintf(stdout,
          "%s %s():%d | %s\n",
          __FILE__, __func__, __LINE__,
          str);
}
