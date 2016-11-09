#include "parser.h"
#include <stdio.h>
#include <string.h>

#define PARSER_OK   0
#define PARSER_NULL 1

void print_args(int argc, char **argv)
{
  int i;

  // Skip the first arg (the program itself), so start at 1
  for (i=1; i<argc; i++)
    {
      printf(" * argv[%d]: '%s'\n",
             i, argv[i]);
    }
  
}

static int equal(char * option, char *user_arg)
{
  if (option==NULL || user_arg==NULL)
    {
      return 0;
    }
  if (strlen(option)!=strlen(user_arg))
    {
      return 0;
    }
  return strncmp(option, user_arg, strlen(user_arg))==0;
}

int parse_args(int argc, char **argv)
{
  int i;

  // Skip the first arg (the program itself), so start at 1
  for (i=1; i<argc; i++)
    {
      if ( equal(argv[i], "--long") )
        {
          fprintf (stderr, "Found --long .... take some action\n");
        }
      else if ( equal(argv[i], "--short") )
        {
          fprintf (stderr, "Found --short .... take some action\n");
        }
      else
        {
          return -1;
        }
    }
  return PARSER_OK;
}
