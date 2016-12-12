#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*
str_dup(char* str)
{
  char *new = (char*) calloc(strlen(str)+1, sizeof(char));
  if (new==NULL)
    {
      return NULL;
    }
  return strncpy(new,str, strlen(str));
}

int
main(void)
{
  char *name = str_dup("Henrik");

  printf("name: %s\n", name);

  /* free(name); */
  return 0;
}
