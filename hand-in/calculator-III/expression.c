#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <errno.h>

#include "expression.h"
#include "strtoint.h"


/* must be the same order as the enum (operator) in the header file*/
static char * op_strings[] =
  {
    "+",
    "-",
    "/",
    "x",
    "%",
    NULL
  };

static int
comp_str(char* a, char* b)
{
  if(a==NULL || b==NULL)
    {
      return 0;
    }

  /* Perhaps a bit overly optimised, but we like to make you think about this one
   * If two strings are of different length they can't be "equal"
   */
  if (strlen(a)!=strlen(b))
    {
      return 0;
    }
  return strcmp(a,b)==0;
}

char
string_to_op(char *str)
{
  char i=-1;
  /* Loop through the operatings (as strings) and see if we can find
     the operator If found we return the index. This code will not
     work if the operators in the enum (operator) are in different
     order compared to the string array (op_strings)
  */
  while (op_strings[(int)++i]!=NULL)
    {
      /* printf ("i: %d  %s '%s' \n",  */
      /*         i, op_strings[(int)i],str);  */
      if (comp_str(op_strings[(int)i],str))
        {
          return i;
        }
    }
  return -1;
 }
                  
int args_to_expr(char *op1,
                 char *op,
                 char *op2,
                 expr *e)
{
  /* from the string op1, we (try to) scan an integer (%d) and store
   * it in op1 in the expr (e). 
   * 
   * How do reach op1 in e? Let's Start be dereferencing e
   *   *e ... or (*e)
   * and from that use op1
   *   (*e).op1  ... or ((*e).op1)
   * ok, we have the op1 "variable in our hand"... let's pass a ref to it
   *   &((*e).op1)
   * We can pass &((*e).op1)
   * 
   * ..... or we can use the -> to "get to" op1
   *   e->op1 
   * and a ref to that: &e->op1
   * 
   */
  int ret;
  ret = strtoint(op1, &e->op1);
  if (ret != STRTOINT_OK)
    {
      return -1;
    }
  
  /* Use the function to turn a string into an operator */
  e->op = string_to_op(op);
  if (e->op==-1)
    {
      /* failed turning the str into an op */
      return -1;
    }

  /* see above */
  ret = strtoint(op2, &e->op2);
  if (ret != STRTOINT_OK)
    {
      return -1;
    }
  return 0;
}


void
print_expr(expr *e)
{
  if (e==NULL)
    {
      return ;
    }

  printf ("%d %s %d ",
          e->op1, 
          op_strings[(int)e->op], 
          e->op2);
}


int
calc_expression(expr *e, int *result)
{
  if ( (e==NULL) || (result==NULL) )
    {
      return -1;
    }
  long long temp_result;
  switch (e->op)
    {
    case PLUS:
      temp_result = (long long)e->op1 + (long long)e->op2;
      break;
    case SUBTRACTION:
      temp_result = (long long)e->op1 - (long long)e->op2;
      break;
    case DIVISION:
      if (e->op2==0)
        {
          return DIV_ZER0;
        }
      temp_result = (long long)e->op1 / (long long)e->op2;
      break;
    case MULTIPLICATION:
      temp_result = (long long)e->op1 * (long long)e->op2;
      break;
    case REMAINDER:
      if (e->op2==0)
        {
          return DIV_ZER0;
        }
      temp_result = (long long)e->op1 % (long long)e->op2;
      break;
    default:
      return UNKNOWN_OPERATOR;
    }
  
  if  (temp_result>INT_MAX)
    {
      fprintf (stderr, "result %lld too big\n", temp_result);
      return RESULT_TOO_BIG;
    }
  if  (temp_result<INT_MIN)
    {
      fprintf (stderr, "result %lld too small\n", temp_result);
      return RESULT_TOO_SMALL;
    }
  *result = (int)temp_result;
  return 0;
}
