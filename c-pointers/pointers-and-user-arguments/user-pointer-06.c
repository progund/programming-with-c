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
      /* Compare the length of the string AND if the arguments have
         the same content (up to the length of "--terminate"
      */
      if (strlen(argv[i])==strlen)("--terminate" &&
          strncmp(argv[i], "--terminate", strlen("--terminate"))==0)
        {
          break;
        }
    }
  
  return 0;
}
