#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


/* Every line should contain "int;int" with a max length of 5 + \n + \0, so 7*/
#define READ_BUF_SIZE 7

enum
  {
    OK,
    FAILED_OPEN_FILE,
    SCANF_FAILURE,
    CLOSE_FAILURE
  } return_values;


int
read_print_file(char * file_name)
{
  char buf[READ_BUF_SIZE];
  FILE* fp;
  int ret;
  int x;
  int y;
  
  fp = fopen (file_name,"r");
  if (fgfp == NULL)
    {
      return FAILED_OPEN_FILE;
    }

  while (fgets(buf, READ_BUF_SIZE, fp))
    {
      /* printf ("line: '%s'   strlen:%lu \n", */
      /*         buf, strlen(buf)); */

      ret = sscanf(buf, "%d;%d", &x, &y);
      /* Every line should contain "int;int" with a max length of
       * 5+1+1.  This means we should always be able to scan 2
       * integers.... so check that we succeeded scanning two
       * integers*/
      if (ret != 2 )
        {
          /* Uh oh, we failed scanning two integers. This means the
             line is corrupt. Could be that the line was longer than 7
             characters, contains non "digits" .... so let's leave
             with a SCANF_FAILURE */
          fprintf(stderr, "Corrupt line: '%s'\n", buf);
          return SCANF_FAILURE;
        }
      printf ("x:%d  y:%d\n", x, y);
      
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
  int ret;
  
  /* Make sure we have enough arguments */
  if (argc<2)
    {
      fprintf(stderr, "Missing file argument\n");
      return 1;
    }

  file_name = argv[1];
  ret = read_print_file(file_name);
  if (ret)
    {
      if (ret==FAILED_OPEN_FILE)
        {
          printf( "Failed reading file '%s'\n * %s\n",
                  file_name, strerror(errno) );
        }
      else if (ret==SCANF_FAILURE)
        {
          printf( "Failed scanning data in file '%s'\n",
                  file_name );
        }
      return ret;
    }
  
  return 0;
}
