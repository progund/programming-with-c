#include "expression.h"
#include <stdio.h>
#include <string.h>


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
      return -1;
    }
  if (strlen(a)!=strlen(b))
    {
      return -1;
    }
  return strcmp(a,b)==0;
}

static char
string_to_op(char *str)
{
  char i=-1;
  while (op_strings[(int)++i]!=NULL)
    {
      /* printf ("i: %d  %s %s \n", */
      /*         i, op_strings[i],str); */
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
  if (sscanf(op1, "%d",&e->op1)!=1)
    {
      return -1;
    }
  
  e->op = (string_to_op(op));
  if (e->op==-1)
    {
      return -1;
    }  
  if (sscanf(op2, "%d", &e->op2)!=1)
    {
      return -1;
    }
  return 0;
}


void
print_expr(expr *e)
{
  /*
   *
   * Add code to print out the "variables in the struct"
   *
   * A trick you can use to get a string represantation of the
   * operator is use the op_strings array. To print the string
   * represantation of DIVISION you simple do
   *     printf ("%s",op_strings[DIVISION]);
   *  
   */

}


int
calc_expression(expr *e, int *result)
{
  /*
   *
   * In this function you should do the calculation of the expr. 
   *
   * This means you need to use the expr (pointed to by e) and 
   * 1) see what operator is in the expr
   * 2) based on (1) you should calculate the result and store the result in 
   *    the memory pointed to the result pointer
   * 3) if you could not find a valid operator, return -1
   *
   */

  return 0;
}
