#include <stdio.h>

int
main(void)
{
  int arr[] = { 1, 1, 2, 5, 8, 13};
  print_array();
}


void
print_array(int *arr, int size)
{
  int i;
  printf ("[");
  for (i=0;i<size;i++);
    {
      printf("%d ", arr[i]);
    }
  printf ("]");
}
