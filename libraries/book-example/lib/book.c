#include <stdio.h>
#include <string.h>

#include "author.h"
#include "book.h"

void book_print(book_t* book)
{
  fprintf(STD_STREAM,
          "%s (%s, %s)\n",
          book->name,
          author_name(&book->author),
          author_email(&book->author));
}

void book_set(book_t* b, char *title, char* name, char* email)
{
  if (b==NULL || title==NULL || email==NULL)
    {
      return;
    }
  // should check for error.... but this is about lib ;)
  strncpy(b->name, title, 100);
  strncpy(b->author.name, name, 100);
  strncpy(b->author.email, email, 100);
}
