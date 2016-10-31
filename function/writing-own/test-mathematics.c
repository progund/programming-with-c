#include <stdio.h>
#include <unistd.h>
#include "mathematics.h"

static char spin[]  = { '|', '/', '-', '\\'};
static int   spindex ;
#define NEXT_SPIN fprintf(stdout, "\b%c", spin[spindex++%4]);
#define TEST_MIN_MAX(a,b) { fprintf(stdout, "Error, your function falsely returned of %d and %d is %d\n", a, b, max(a,b)) ; } else { usleep(5*1000); fflush(stdout);}

#define TEST_MAX(a,b) NEXT_SPIN; if(max(a,b)!=(a>b?a:b)) TEST_MIN_MAX(a,b)
#define TEST_MIN(a,b) NEXT_SPIN; if(min(a,b)!=(a<b?a:b)) TEST_MIN_MAX)a,b)




int main()
{
  int i;
  int j;
  int ctr=0;
  printf ("Testing max:  ");
  for (i=0;i<10;i++)
    {
      for (j=0;j<10;j++)
        {
            TEST_MAX(i, j);
            ctr++;
        }
    }
  printf("\bAll %d tests passed\n", ctr);

  ctr=0;
  printf ("Testing min:  ");
  for (i=-5;i<5;i++)
    {
      for (j=-5;j<5;j++)
        {
            TEST_MAX(i, j);
            ctr++;
        }
    }
  printf("\bAll %d tests passed\n", ctr);
}
