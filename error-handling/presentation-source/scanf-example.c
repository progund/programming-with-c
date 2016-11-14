#include <stdio.h>
#include <string.h>

/*
 * 
 * Simple program to read user input (from stdin)
 * 
 * You can fake a scanf failure by defining FAKED_SCANF_FAILURE, like this:
 *
 *    -D FAKED_SCANF_FAILURE
 * 
 * This means that the gcc comand line will look like:
 *
 *   gcc  -pedantic -Wconversion -Wall -Werror  -Wextra -Wstrict-prototypes  -D FAKED_SCANF_FAILURE scanf-example.c -o scanf-example 
 *
 * Compile (with and without the faked scanf) and execute the program
 * and try pressing ctrl-d when requested to input a name
 *
 */



/*
 * read_from_user reads a string from the user
 * and returns the same as scanf
 */
int
read_from_user(char *prompt, char *buffer)
{
  int ret;
  printf("%s", prompt);
  ret = scanf("%10s",buffer);
#ifdef FAKED_SCANF_FAILURE
  ret--;
#endif
  return ret;
}

int main(void)
{
  char user_name [256];
  int ret = read_from_user("Enter your name: ", user_name);
  
  if (ret > 0 )
    {
      printf("Your name: %s\n",user_name);
    }
  else if ( ret == 0 )
    {
      fprintf(stderr, "Failed reading string\n");
      return 2;
    }
  else if ( ret == EOF )
    {
      fprintf(stderr, "Could not read string... EOF (%d) returned\n", EOF);
      return 1;
    }

  return 0;
}
