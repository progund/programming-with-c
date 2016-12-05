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

      /* read from user */
      ret = read_expr_from_user(&e);
      /* handle error (if any) */
      
      /* calculate */
      ret = calc_expression(&e, &res);
      /* handle error (if any) */

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

  /* Add code to handle str == NULL */

  /* Add code to handle str contains "quit" */

  /* scan in the three strings from buf to
                   op1_buff,
                   op_buff,
                   op2_buff
  */ 
  
  
  /* use args_to_expr to fill the expression */
  /* handle error */
  
  return 0;
}


int interactive_calculator(void)
{
  welcome_message();
  
  return interactive_loop();
}
