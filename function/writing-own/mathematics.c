#include <stdio.h>

int max(int first, int second)
{
  if (first>second)
    {
      return first;
    }
  return second;
}


int min(int first, int second)
{
  if (first<second)
    {
      return first;
    }
  return second;
}

void print_max(int first, int second)
{
  // Using >
  /*
  if (first>second) {
    printf ("%d\n", first);
  } else {
    printf ("%d\n", second);
  }
  */
  // Using our own max function
  printf ("%d\n", max(first, second));
}

void print_min(int first, int second)
{
  printf ("%d\n", min(first, second));
}

                 
