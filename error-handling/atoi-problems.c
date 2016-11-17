#include <stdio.h>
#include <stdlib.h>

static void
print_str_and_int(char *str)
{
  printf ("%20s as an int: %d\n",
          str, atoi(str)); 

}

int
main(void)
{
  print_str_and_int("Hello");
  print_str_and_int("3");
  print_str_and_int("0");

  return 0;
}
