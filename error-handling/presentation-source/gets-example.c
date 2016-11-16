#include <stdio.h>


char *gets(char *s);

int
main(void)
{
  char buff[10];
  
  if (gets(buff)!=NULL)
    {
      printf ("Just read: '%s'\n", buff);
    }
  return 0;
}
