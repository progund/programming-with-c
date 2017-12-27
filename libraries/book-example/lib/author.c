#include <stdio.h>
#include <string.h>
#include "author.h"

const char *EMPTY_STRING = "" ;

void author_print(author_t *author)
{
  if (author!=NULL)
    {
      fprintf(STD_STREAM, "%s",
              EMPTY_STRING_IF_NULL(author->name));
      if (author->email!=NULL &&
          strncmp(author->email, EMPTY_STRING, strlen(EMPTY_STRING))!=0)
        {
          fprintf(STD_STREAM, "<%s>",author->email);
        } 
      fprintf(STD_STREAM, "\n");
    }
}

char* author_name(author_t* author)
{
  if (author!=NULL)
    {
      return author->name;
    }
  return (char*) EMPTY_STRING;
}

char* author_email(author_t* author)
{
  if (author!=NULL)
    {
      return author->email;
    }
  return (char*) EMPTY_STRING;
}







