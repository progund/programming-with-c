#include <stdio.h>
#include <string.h>

/*
 *
 * Small program to show how to manage the information passed to it
 * via the command line options
 *
 */

int main(int argc, char **argv)
{
  int i;
  printf ("Number of arguments from the user: %d\n", argc);

  for (i=0; i<argc; i++)
    {
      printf ("* Argument nr %d is '%s'\n", i, argv[i]);
      if (strncmp(argv[i], "--terminate", strlen("--terminate"))==0)
        {
          printf ("Really should quit here\n");
        }
    }
  
  return 0;
}
