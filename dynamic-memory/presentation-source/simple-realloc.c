#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *
 * Program to show a simple allocation, usage, realloc, usage, free of
 * memory.
 *
 * Academic (in the sense that this program does not exist anywhere in
 * the world) program.
 *
 *
 */

int main(void)
{
  /* Create memory for 4 characters plus ending \0 */
  char * name = calloc(sizeof(char), 5);

  /* Check if it all went well */
  if (name == NULL)
    {
      /* Uh oh, we did not get any memory */
      exit (1);
    }

  /* Use the memory - in this case copy a name to it and print it */
  strcpy (name, "Adam");
  fprintf(stdout, "name: %s\n", name);

  /* increase the memory */
  char * tmp = realloc(name, sizeof(char)*17);
  
  /* Check if it all went well */
  if (tmp == NULL)
    {
      /* Uh oh, we did not get any memory. Free the old mem and exit */
      free(name);
      exit (1);
    }

  /* Ok, so we did get some memory. Make name point to the new memory
     location (could be the same, could be a new address */
  name = tmp;
  
  /* Use the memory - in this case copy a name to it and print it*/
  strcpy (name, "Kenny McCormick");
  fprintf(stdout, "name: %s\n", name);

  /* Free the memory */
  free(name);

  return 0;
}
