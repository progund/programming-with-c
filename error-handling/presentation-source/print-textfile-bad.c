#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


/*
 *
 * This program is intended to show how to print the content of a file
 * but doing it in a "rather" careless way.
 *
 * This program is an example of what we (the authors of this book)
 * refer to as academic programming - a program which only works under
 * certain circumstances.
 *
 * The plot (which has thickened while reading this text) is to see
 * that we need to create a better program, which does not crash, and
 * a more flexible program, which can print several files. A better
 * solution to the task of printing a file can be found in the file:
 * print-textfile.c
 *
 */
 
#define READ_BUF_SIZE 100


int
main (int argc, char** argv)
{
  char buf[READ_BUF_SIZE];
  FILE* fp;
  char* file_name;
  
  /* Make sure we have enough arguments */
  if (argc<2)
    {
      fprintf(stderr, "Missing file argument\n");
      return 1;
    }

  /* Ok, let's use the first arg (after the program itself) as filename */
  file_name = argv[1];
  fp = fopen (file_name,"r");
  while (fgets(buf, READ_BUF_SIZE, fp))
    {
      fprintf(stdout, "%s", buf);
    }
  return 0;
}
