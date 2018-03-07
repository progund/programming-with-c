#include <stdio.h>
#include <string.h>
#include "interface/file-lister.h"

#define SAME_STR(a,b) (strcmp(a,b)==0)

int present(char *name)
{
  //  int len;
  char *suffix;
  if (name==NULL)
    {
      return FILE_LISTER_BAD_ARG;
    }

  /* length of the name */
  //  len = strlen(name);
  
  /* last occurance of . in name */
  suffix = strrchr(name, '.');
  if (  SAME_STR(name, "Makefile") ||
        SAME_STR(name, "makefile") ||
        ( ( suffix != NULL ) &&
          (SAME_STR(suffix, ".mk") ||
           SAME_STR(suffix, ".grade") ||
           SAME_STR(suffix, ".ant") 
           )))
    {
      fprintf(stdout, "[build] %s\n", name);
      return FILE_LISTER_OK;
    }
  return FILE_LISTER_SUFFIX_UNKNOWN;
}

int info(void)
{
  printf("A plugin (for build files) to the file lister. Written by Juneday\n");
  return FILE_LISTER_OK;
}
