#include <stdio.h>
#include "time-date.h"

int main ()
{
  int month = current_month();
  printf("current month: %d\n", month);
  return(0);
}
