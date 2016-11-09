#include <stdio.h>
#include <assert.h>

int max(int first, int second)
{
  if (first>second)
    {
      return first;
    }
  return second;
}

int main()
{
  int value;
  
  /* Test max function
     Not using assert */
  printf ("Test max using if statement:");
  value = max(13,14);
  if (value!=14) 
    {
      printf (" FAILED\n");
      fprintf(stderr, "max(13,14) failed)");
      fprintf(stderr, "  result   %d\n", value);
      fprintf(stderr, "  expected %d\n", 14);
      /* typically return an error, exit .... */
    }
  printf (" OK\n");
        
  printf ("Test max using assert:      ");
  assert (max(13,14)==14);
  printf (" OK\n");

  /* The code below is really stupid ..... if it wasn't for the fact
     that we want to see what happens on a failed assert */
  printf ("Make assert fail:          ");
  assert (max(13,14)==1);
  printf (" OK\n");

  return 0;
}
