#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "expression.h"
#include "interactive.h"

static void handle_error(int ret)
{
  if (ret == SYNTAX_ERROR)
    {
      fprintf(stderr, "Syntax error\n");
    }
  else if (ret == MISSING_ARGUMENTS)
    {
      fprintf(stderr, "Missing arguments\n");
    }
  else
    {
      fprintf(stderr, "Unknown error\n");
    }
  usage(stderr);
  exit(ret);
}

int main(int argc, char** argv)
{
  expr e;
  int ret;
  int res;

  if (argc<2)
    {
      return interactive_calculator();
    }
  else
    {
      ret = parse_user_args(argc, argv, &e);
      if (ret)
        {
          handle_error(ret);
        }
      ret = calc_expression(&e, &res);
      if (ret)
        {
          handle_error(SYNTAX_ERROR);
        }
      /*
        print_expr(&e);
        printf ("= %d\n", res);
      */
      printf ("%d\n", res);
      return 0;
    }
}
