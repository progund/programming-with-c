#include <stdio.h>
#include "time-date.h"

int main ()
{
  printf("Current month: %s\n", current_month_name());

  /* alt.
     char *month = current_month_name();
     printf("Current month: %s\n", month);
   */
  return(0);
}
