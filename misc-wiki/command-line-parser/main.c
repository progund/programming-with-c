#include <stdio.h>
#include "parser.h"

int main(int argc, char **argv)
{
  int ret;

  print_args(argc, argv);
  ret = parse_args(argc, argv);
  printf ("Parse function returned: %d\n", ret);
}
