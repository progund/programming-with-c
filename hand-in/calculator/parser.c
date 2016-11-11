#include <stdio.h>
#include "expression.h"
#include "parser.h"


int
parse_user_args(int argc, char **argv, expr *e)
{

  if ( (argc<4) || (e==NULL) )
    {
      return MISSING_ARGUMENTS;
    }
  
  if (args_to_expr(argv[1], argv[2], argv[3], e) != 0 )
    {
      return SYNTAX_ERROR;
    }

  return SUCCESS;
}

void
usage(FILE *f)
{
  fprintf (f, "calc\n");
  fprintf (f, "    a command line calculator\n");
  fprintf (f, "\n");
  fprintf (f, "SYNTAX\n");
  fprintf (f, "    calc operand operator operand\n");
  fprintf (f, "\n");
  fprintf (f, "  Where operators include\n");
  fprintf (f, "  + for addition\n");
  fprintf (f, "  - for subtraction\n");
  fprintf (f, "  / for division\n");
  fprintf (f, "  x for multiplication \n");
  fprintf (f, "  %% for remainder \n");
  fprintf (f, "\n");
  fprintf (f, "\n");
  fprintf (f, "\n");
  
}
