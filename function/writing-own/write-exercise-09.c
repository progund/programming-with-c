#include <stdio.h>
#include "time-date.h"


int get_int(int argc, char **argv)
{
  if (argc<2)
    {
      return -1;
    }
  int ret;
  if (sscanf(argv[1], "%d", &ret) == 1 )
  {
    return ret;
  }
  return -1;
}

int main(int argc, char **argv)
{
  int month = get_int(argc, argv);
  if (month<0)
    {
      printf ("Invalid month\n"); 
    }
  else
    {
      // Any of two below:
      //printf ("%s\n", month_name(month));
      print_month_name(month);
    }
}
