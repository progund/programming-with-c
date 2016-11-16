#include <stdio.h>
#include <stdlib.h>

void
print_atoi(char *s)
{
  int scanned_value;
  printf("%10s  %4d  [", s==NULL?"NULL":s, atoi(s));
  if (sscanf(s, "%d", &scanned_value)!=1)
    {
      printf("fail");
    }
  else
    {
      printf ("%d", scanned_value);
    }
  printf("]\n");
}

int
main(void)
{
  printf ("     string  atoi sscanf\n");
  printf ("-----------------------------\n");
  print_atoi("-123");
  print_atoi("0");
  print_atoi("123");
  print_atoi("AS Roma");
  print_atoi(NULL);
  
  return 0;
}
