#include <stdio.h>

char *gets(char *s);

int main(void)
{
  char buf[10];

  gets(buf);
  printf ("buff: %s\n", buf);

  return 0;
}
