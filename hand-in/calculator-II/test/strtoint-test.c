#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <errno.h>

#include "strtoint.h"


int main(int argc, char **argv)
{
  int value;
  int i ;
  int ret;


  if (argc>1)
    {
      for (i=1;i<argc;i++)
        {
          ret = strtoint(argv[i], &value);
          printf ("arg: %s =>  ret: %d   value: %d\n",
                  argv[i], ret, value);
        }
    }
  else
    {
#define TEST_STR(a)  {  char buf[100]; strcpy(buf, a); ret = strtoint(buf, &value);     printf ("arg: '%s' =>  ret: %d   value: %d\n", buf, ret, value); }
      TEST_STR("-2147483649");
      TEST_STR("-2147483648");
      TEST_STR("-2147483647");
      TEST_STR("-2147483646");
      TEST_STR("-2147483645");

      TEST_STR("-123");
      TEST_STR("0");
      TEST_STR("-123");

      TEST_STR("2147483646");
      TEST_STR("2147483647");
      TEST_STR("2147483648");
      TEST_STR("2147483649");

      TEST_STR("");
      TEST_STR(" ");
      TEST_STR("1a");
      TEST_STR("aaa");
      TEST_STR("aaalllllllllllllllllllllllllllllllllllllllllllllllllll");
      TEST_STR("-1a");
      TEST_STR("-");
      TEST_STR("-a");
      TEST_STR("-aaaa");

}
  return 0;
}
