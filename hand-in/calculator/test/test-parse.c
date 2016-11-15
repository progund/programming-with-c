#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "expression.h"
#include "parser.h"


static int
check_parser(char *op1, char *op, char *op2, int exp)
{
  char *argv[4];
  expr e;
  argv[0] = "calc";
  argv[1] = op1;
  argv[2] = op;
  argv[3] = op2;

  int ret = parse_user_args(4, argv, &e);

  printf ("[%s %s %s]:", op1, op, op2);
  assert(ret==exp);
  printf (" OK\n");
  return 0;
}

static int
check_parser_int(int op1, char *op, int op2, int exp)
{
  char op1_buf[100];
  char op2_buf[100];

  sprintf(op1_buf, "%d", op1);
  sprintf(op2_buf, "%d", op2);

  return check_parser(op1_buf, op, op2_buf, exp);
}

static void
check_parser_int_ops(int op1, int op2, int exp)
{
  check_parser_int(op1, "+", op2, exp);
  check_parser_int(op1, "-", op2, exp);
  check_parser_int(op1, "/", op2, exp);
  check_parser_int(op1, "x", op2, exp);
  check_parser_int(op1, "%", op2, exp);
}

static void
check_invalid_args(void)
{
  /* Valid first arg, rest crap */
  check_parser("1", "+" , "a", 1);
  check_parser("1", "a" , "1", 1);
  check_parser("1", "a" , "a", 1);
  check_parser("1", "++" , "1", 1);
  check_parser("1", "ö" , "a", 1);

  /* Valid second arg, rest crap */
  check_parser("1", "+" , "a", 1);
  check_parser("a", "+" , "1", 1);
  check_parser("a", "+" , "a", 1);

  /* Valid third arg, rest crap */
  check_parser("1", "a" , "1", 1);
  check_parser("a", "+" , "1", 1);
  check_parser("a", "a" , "1", 1);  
}

int main(void)
{
  int i ;
  for (i=0; i<100; i++)
    {
      check_parser_int_ops(i*i, i*i, 0);
    }
  check_invalid_args();
}
