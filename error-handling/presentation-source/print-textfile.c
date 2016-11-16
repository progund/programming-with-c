#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


/*
 * This program is intended to show how to print the content of a file
 * a bit better than we did in the previous example: print-textfile-bad.c
 *
 * What makes it better is:
 *  + can print all files given on command line (one by one, interactively)
 *  + checks return values on open, close, read, write and acts accordingly 
 *
 */

#define READ_BUF_SIZE 100

enum
  {
    OK,
    FAILED_OPEN_FILE,
    PRINT_FAILURE,
    CLOSE_FAILURE
  } return_values;

int
print_file(char * file_name)
{
  char buf[READ_BUF_SIZE];
  FILE* fp;
  int ret;
  
  fp = fopen (file_name,"r");
  if (fp == NULL)
    {
      return FAILED_OPEN_FILE;
    }

  while (fgets(buf, READ_BUF_SIZE, fp))
    {
      ret = fprintf(stdout, "%s", buf);
      if ( ret < 0 || (unsigned int)ret!=strlen(buf) )
        {
          return PRINT_FAILURE;
        }
    }
  if (fclose (fp))
    {
      return CLOSE_FAILURE;
    }

  return OK;
}

int
main (int argc, char** argv)
{
  char* file_name;
  int i;
  int ret;
  
  /* Make sure we have enough arguments */
  if (argc<2)
    {
      fprintf(stderr, "Missing file argument\n");
      return 1;
    }

  /* Ok, let's use the remaining args (after the program itself) as filenames */
  for (i=1; i<argc; i++)
    {
      file_name = argv[i];
      if (argc>2)
        {
          fprintf(stdout, ":: Press a key to show file: %s ::\n", file_name);
          ret = getchar();
          if (ret == EOF)
            {
              fprintf(stderr, "Failed reading command from user, bailing out\n");
              return 2;
            }
        }
      ret = print_file(file_name);
      if (ret)
        {
          if (ret==FAILED_OPEN_FILE)
            {
              printf( "Failed reading file '%s'\n * %s\n",
                      file_name, strerror(errno) );
            }
          else if (ret==FAILED_OPEN_FILE)
            {
              printf( "Failed closing file '%s'\n * %s\n",
                      file_name, strerror(errno) );
            }
          return ret;
        }
    }
  
  return 0;
}
