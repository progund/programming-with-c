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
  if ( ( suffix != NULL ) &&
       (
        SAME_STR(suffix, ".c")   ||
        SAME_STR(suffix, ".h")   ||
        SAME_STR(suffix, ".C")   ||
        SAME_STR(suffix, ".H")   ||
        SAME_STR(suffix, ".cpp") ||
        SAME_STR(suffix, ".c++") ) )
    {
      fprintf(stdout, "[C/C++] %s\n", name);
      return FILE_LISTER_OK;
    }
  return FILE_LISTER_SUFFIX_UNKNOWN;
}

int info(void)
{
  printf("A plugin (for C/C++ files) to the file lister. Written by Juneday\n");
  return FILE_LISTER_OK;
}
