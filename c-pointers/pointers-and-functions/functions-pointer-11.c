#include <stdio.h>

int doubler (int *x, int *result) {
  /* If x is NULL, return 1 directly */
  if (x==NULL || result==NULL)
    {
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
     Expected result: a return value != 0  */
  ret_value = doubler(NULL, NULL);
  if (ret_value!=0)
    {
      printf ("Test passed. Failed doubling NULL, NULL\n");
    }
  else
    {
      printf ("Uh-oh, doubler(NULL, NULL) set result to: %d\n", result);
    }

  /* Test with first arg NULL 
     Expected result: a return value != 0  */
  ret_value = doubler(NULL, &result);
  if (ret_value!=0)
    {
      printf ("Test passed. Failed doubling NULL, &result\n");
    }
  else
    {
      printf ("Uh-oh, doubler(NULL, &result) set result to: %d\n", result);
    }

  /* Test with second arg NULL 
     Expected result: a return value != 0  */
  ret_value = doubler(&value, NULL);
  if (ret_value!=0)
    {
      printf ("Test passed. Failed doubling &value, NULL\n");
    }
  else
    {
      printf ("Uh-oh, doubler(&value, NULL) set result to: %d\n", result);
    }

  /* Test with ok args 
     Expected result: a return value 0 and the result value set to 26  */
  ret_value = doubler(&value, &result);
  if (ret_value!=0)
    {
      printf ("Uh-oh, doubler(&value, &result) returned error code.\n");
    }
  else
    {
      printf ("Test passed. doubler(&value, &result) where value was %d gave us: %d\n", value, result);
    }
  
  return 0;
}
}
