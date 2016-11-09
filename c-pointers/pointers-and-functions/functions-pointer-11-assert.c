#include <stdio.h>
#include <assert.h>

int doubler (int *x, int *result) {

  /* If x is NULL or result is NULL, return an error code */
  if (x==NULL || result==NULL) {
    return 1;
  }

  *result = *x * 2;
  return 0;
}


int main() {

  int ret_value ;
  int value = 13;
  int result;
  
  /* Test with both args NULL
   * Expected result: a return value != 0
   */
  ret_value = doubler(NULL, NULL);
  assert( ret_value != 0 );
  printf ("Test passed. Failed doubling NULL, NULL\n");
  
  /* Test with first arg NULL 
   * Expected result: a return value != 0
   */
  ret_value = doubler(NULL, &result);
  assert( ret_value!=0 );
  printf ("Test passed. Failed doubling NULL, &result\n");
  
  /* Test with second arg NULL 
   * Expected result: a return value != 0
   */
  ret_value = doubler(&value, NULL);
  assert( ret_value!=0 );
  printf ("Test passed. Failed doubling &value, NULL\n");

  /* Test with ok args 
   * Expected result: a return value 0 and the result value set to 26
   */
  ret_value = doubler(&value, &result);
  assert( ret_value == 0 );
  printf ("Test passed. doubler(&value, &result) where value was %d gave us: %d\n", value, result);
  
  return 0;
}
