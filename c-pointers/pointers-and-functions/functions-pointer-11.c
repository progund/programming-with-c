#include <stdio.h>

int doubler (int *x, int *result) {
  // If x is NULL, return 1 directly
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
  
  /* Test with both args NULL */
  ret_value = doubler(NULL, NULL);
  if (ret_value!=0) {
    printf ("Failed doubling NULL\n");
  } else {
    printf ("Doubling NULL gave us: %d\n", result);
  }

  /* Test with first arg NULL */
  ret_value = doubler(NULL, &result);
  if (ret_value!=0) {
    printf ("Failed doubling NULL\n");
  } else {
    printf ("Doubling NULL gave us: %d\n", result);
  }

  /* Test with second arg NULL */
  ret_value = doubler(&value, NULL);
  if (ret_value!=0) {
    printf ("Failed doubling NULL\n");
  } else {
    printf ("Doubling %d gave us: %d\n", value, result);
  }

  /* Test with ok args */
  ret_value = doubler(&value, &result);
  if (ret_value!=0) {
    printf ("Failed doubling NULL\n");
  } else {
    printf ("Doubling %d gave us: %d\n", value, result);
  }

  
  return 0;
}
