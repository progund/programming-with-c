#ifndef BOOK_H
#define BOOK_H

#include "author.h"

typedef struct book_
{
  // for this example we find it nice to have fixed size "strings"
  char name[100]; 
  author_t  author; 
} book_t;

void book_print(book_t* book);
void book_set(book_t* b, char *title, char* name, char* email);

#endif /* BOOK_H */
