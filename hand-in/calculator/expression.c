#include <stdio.h>
#include <string.h>

#include "expression.h"


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

static char
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
      printf ("i: %d  %s '%s' \n", 
              i, op_strings[(int)i],str); 
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
  if (sscanf(op1, "%d",&e->op1)!=1)
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
  if (sscanf(op2, "%d", &e->op2)!=1)
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

  /* YOUR CODE GOES HERE */
  
  /*
   *
   * Add code to print out the "variables in the struct"
   *
   * A trick you can use to get a string represantation of the
   * operator is use the op_strings array. To print the string
   * represantation of DIVISION you simple do
   *     printf ("%s",op_strings[DIVISION]);
   *
   * Instead of using DIVISION all the time, we "suggest" using the
   * operator as found in the expression.
   *  
   * Note: indexing in an array using a char is something the compiler
   * does not like. You "may" need to typecast the operator (used as
   * index) to an int.
   *  
   *
   */

}


int
calc_expression(expr *e, int *result)
{
  if ( (e==NULL) || (result==NULL) )
    {
      return -1;
    }
  /* YOUR CODE GOES HERE */

  /*
   *
   * In this function you should do the calculation of the expr. This
   * means you need to use the expr (pointed to by e) and
   *
   * 1) see what operator is in the expr (compare e->op with MINUS,
   * PLUS, ....)
   *
   * 2) based on (1) you should calculate the result and store the
   *    result (e g e->op1 + e->op2 for PLUS) in the memory pointed to
   *    the result pointer: *result
   *
   * 3) if you could not find a valid operator, return -1
   *
   */

  return 0;
}
