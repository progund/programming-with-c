#include <stdio.h>
#include <string.h>

#include "expression.h"
#include "strtoint.h"
#include "interactive.h"

#define BUF_SIZE 100
#define INT_BUF_SIZE 20
#define OP_BUF_SIZE  1

static int read_expr_from_user(expr *e);
static int interactive_loop(void);


static void
welcome_message(void)
{
  fprintf(ERROR_STREAM, "Welcome to the calculator\n");
}

static void
leave_message(void)
{
  fprintf(ERROR_STREAM, "bye bye\n");
}

static int interactive_loop(void)
{
  int keep_reading=1;
  int ret;
  int res;
  expr e;
  while (keep_reading)
    {
      ret = read_expr_from_user(&e);
      if (ret==-1) /* -1 means user type "quit" */
        {
          return 0;
        }
      else if (ret!=0) 
        {
          return 1;
        }
      
      ret = calc_expression(&e, &res);
      if (ret)
        {
          fprintf(ERROR_STREAM, "Input invalid\n");
          return 2;
        }
      printf ("%d\n", res);
    }
  return 0;
}

static int read_expr_from_user(expr *e)
{
  char buff[BUF_SIZE]; /* the size really is overkill */

  char op_buff[OP_BUF_SIZE];
  char op1_buff[INT_BUF_SIZE];
  char op2_buff[INT_BUF_SIZE];
  char *str;
  
  str = fgets(buff, BUF_SIZE, stdin);

  if (str==NULL)
    {
      fprintf(ERROR_STREAM, "Input stream seems to be invalid\n");
      return 1;
    }

  if (strncmp (str, QUIT_STRING, strlen(QUIT_STRING))==0)
    {
      leave_message();
      return -1; /* -1 means user type "quit" */
    }

  /* scan in the three strings */
  int ret = sscanf(buff,
                   "%s %s %s",
                   op1_buff,
                   op_buff,
                   op2_buff);
  if (ret!=3)
    {
      return 2;
    }
  
  if (args_to_expr(op1_buff, op_buff, op2_buff, e) != 0 )
    {
      return 3;
    }
  
  return 0;
}


int interactive_calculator(void)
{
  welcome_message();
  
  return interactive_loop();
}
