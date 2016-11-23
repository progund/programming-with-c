#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *
 * Program to show a simple allocation, usage, free of memory.
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


  /* Free the memory */
  free(name);

  return 0;
}
