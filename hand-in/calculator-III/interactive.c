#include <stdio.h>
#include <string.h>

#include "expression.h"
#include "strtoint.h"
#include "interactive.h"

#define BUF_SIZE 100

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
  /* int res; */
  expr e;
  while (keep_reading)
    {

      /* read from user */
      ret = read_expr_from_user(&e);
      printf ("expr read from user  (ret:%d) - remove this printout later on\n", ret);
      /* handle error (if any) */
      
      /* calculate */
      /* ret = calc_expression(&e, &res); */
      /* handle error (if any) */

      printf ("faked reading...remove this when working with the assignment\n");
      /* printf ("%d\n", res); */
      keep_reading = 0 ;
    }
  leave_message();
  return 0;
}

static int read_expr_from_user(expr *e)
{
  char buff[BUF_SIZE]; /* the size really is overkill */

  char *str;
  
  str = fgets(buff, BUF_SIZE, stdin);

  printf ("User typed: %s (%s) - remove this printout later on\n", buff, str);
  printf ("Expression e is at address: %p - remove this printout later on \n", (void*)&e);
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
