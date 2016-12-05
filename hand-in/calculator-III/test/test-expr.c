#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "expression.h"


static int
test_expr(char op, int op1, int op2, int expected)
{
  int ret;
  int res;
  expr e;
  
  /* set up expr */
  e.op=op;
  e.op1=op1;
  e.op2=op2;

  ret = calc_expression(&e, &res);
  printf ("[");
  print_expr(&e);
  assert (ret==0);
  assert (res==expected);
  printf(" = %d]:   ok\n", res);
  
  return ret;
}

#define TEST_PLUS(a,b)  test_expr(PLUS, a, b, a+b);
#define TEST_SUBTR(a,b) test_expr(SUBTRACTION, a, b, a-b);
#define TEST_MULT(a,b)  test_expr(MULTIPLICATION, a, b, a*b);
#define TEST_DIV(a,b)   test_expr(DIVISION, a, b, a/b);
#define TEST_REM(a,b)   test_expr(REMAINDER, a, b, a%b);

#define TEST_ALL(a,b) \
  TEST_PLUS(a,b);     \
  TEST_SUBTR(a,b);    \
  TEST_MULT(a,b);     \
  TEST_DIV(a,b);      \
  TEST_REM(a,b); 

int main(void)
{
  int i;

  for (i=1;  i<10000; i++)
    {
      TEST_ALL(i, i);
    }
  printf ("%d tests passed\n", i);
}
