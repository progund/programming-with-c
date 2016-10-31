#include <stdio.h>
#include "time-date.h"

int month_left() 
{
  return 12 - current_month();
  /*
   * Alt. solution:
    
   int this_month =  current_month(); 
   return 12 - this_month;
  */
}

int max(int first, int second) {
  if (first>second)
    {
      return first;
    }
  return second;
}


/*
 *
 * Test program 
 *
 */
int main ()
{
  printf("Current year: %d\n", current_year());
  printf("Months left:  %d\n", month_left());
  printf("max:          %d\n", max(12, 13));

  print_current_date();
  
  return(0);
}
