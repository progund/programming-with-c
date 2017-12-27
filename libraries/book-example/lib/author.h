#ifndef AUTHOR_H
#define AUTHOR_H

#define STD_STREAM stdout

typedef struct author_
{
  // for this example we find it nice to have fixed size "strings"
  char name[100];
  char email[100];
} author_t;

extern const char *EMPTY_STRING;
#define EMPTY_STRING_NAME(ap) strcpy(ap->name, EMPTY_STRING)
#define EMPTY_STRING_EMAIL(ap) strcpy(ap->email, EMPTY_STRING)
#define EMPTY_STRING_AUTHOR(ap) EMPTY_STRING_NAME(ap); EMPTY_STRING_EMAIL(ap)
#define EMPTY_STRING_IF_NULL(a) ( (a==NULL)?EMPTY_STRING:a )

void author_print(author_t *author);
char* author_name(author_t *author);
char* author_email(author_t *author);

#endif /* AUTHOR_H */
