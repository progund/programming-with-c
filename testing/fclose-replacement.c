#include <stdio.h>
#include <errno.h>

/*
 * Example program that reads and prints a text file
 *
 *
 */

#define READ_BUFF_SIZE 100

#ifdef ENABLE_FCLOSE_FAILURE
int fclose(FILE *fd)
{
  return EBADF;
}
#endif

int
main(int argc, char **argv) 
{
  char buff[READ_BUFF_SIZE];
  char *default_file_name = "fclose-wrapper.c";
  char *file_name = default_file_name;
  FILE *fd;
  int ret;
  
  if (argc>1)
    {
      file_name = argv[1];
    }
  
  fd=fopen(file_name, "r");
  if (fd==NULL)
    {
      fprintf(stderr, "Failed opening file: '%s'\n", file_name);
      return 1;
    }
  
  while (fgets(buff, READ_BUFF_SIZE, fd)!=NULL)
    {
      printf ("%s",buff);
    }
  
  ret = fclose(fd);
  if (ret!=0)
    {
      fprintf(stderr, "Failed closing file: '%s'\n", file_name);
      return 1;
    }

  return 0;
}
