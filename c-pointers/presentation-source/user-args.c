/*

  Small c file to show how one coud write a parser - without external
  help (such as getopt etc)


 */ 

#include <stdio.h>
#include <string.h>

#define OK           0
#define SYNTAX_ERROR 1

/*
 * Parses the suplied arguments 
 *
 *    argc - the number of arguments supplied
 *    argv - the user arguments (including the program namne)
 *
 * Using a loop we can "traverse" the arguments passed by the user and
 * take action on valid or invalid input
 *
 */
int
parse_args(int argc, char **argv)
{
  int i ;

  // We start from 1, since 0 is the program itself
  for (i=1;i<argc;i++)
  {
    // If use supplied "--list", it shall be recognised as a valid
    // option
    if (strncmp(argv[i], "--list", strlen("--list"))==0)
      {
        printf (" * Using long listing\n");
      }
    // all other options are invalid
    else
      {
        fprintf(stderr, " * unknown option: '%s'\n", argv[i]);
        return SYNTAX_ERROR;
      }
  }
  return OK;
}


int main(int argc, char **argv)
{

  /* List user args, including the program name itself */
  int i;
  printf ("Listing user args:\n");
  printf ("------------------\n");
  for (i=0;i<argc;i++)
  {
    printf (" * args[%d]: %s\n", i, argv[i]);
  }


  /* Parse (using a rather crappy parser) */
  printf ("\n\n");
  printf ("Parsing user args:\n");
  printf ("------------------\n");
  int ret = parse_args(argc, argv);
  printf (" * Parse went: %d\n", ret);

  // If parse went bad, return it
  return ret;
}
