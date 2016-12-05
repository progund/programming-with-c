#include <stdio.h>

static void print_array(int *arr, int size); // fixed

int
main(void)
{
  int arr[] = { 1, 1, 2, 5, 8, 13};
  print_array(arr, 6); //fixed
}


static void
print_array(int *arr, int size)
{
  int i;
  printf ("[");
  for (i=0;i<size;i++) // fixed
    {
      printf("%d ", arr[i]);
    }
  printf ("]\n");
}
