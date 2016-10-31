#include <stdio.h>
#include <math.h>

#define GRADE_TO_RAD(a) a*3.1415926/180

int main()
{
  fprintf (stdout, "abs %d\n",abs(-12));
  fprintf (stdout, "max: %lf %lf\n",
           cos(GRADE_TO_RAD(45)),
           sin(GRADE_TO_RAD(45)));
          
  return(0);
}
