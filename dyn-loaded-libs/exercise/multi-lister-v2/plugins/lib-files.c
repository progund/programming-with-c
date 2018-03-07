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

  /* last occurance of . in name */
  suffix = strrchr(name, '.');
  if ( ( suffix != NULL ) &&
       (
        SAME_STR(suffix, ".a")   ||
        SAME_STR(suffix, ".so")  ))
    {
      fprintf(stdout, "[library] %s\n", name);
      return FILE_LISTER_OK;
    }
  return FILE_LISTER_SUFFIX_UNKNOWN;
}

int info(void)
{
  printf("A plugin (for C/C++ files) to the file lister. Written by Juneday\n");
  return FILE_LISTER_OK;
}
