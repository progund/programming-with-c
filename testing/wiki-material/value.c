#include <stdio.h>

int main(void)
{
  int nr = 12;
  const int* nrp = &nr;
  int* nrp2 = &nr;


  printf ("nr: %d    %d \n",nr, *nrp);

  *nrp2 = 17;
  
  printf ("nr: %d    %d \n",nr, *nrp);

  return 0;
}
