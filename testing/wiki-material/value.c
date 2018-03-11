#include <stdio.h>
#include "value-enemy.h"

int nr = 12 ;

int main(void)
{
  int* nrp = &nr;
  
  PRINT_INT(nr);
  PRINT_INT(*nrp);
  PRINT_INT(nr);

  return 0;
}
