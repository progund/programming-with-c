#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef FAKED_ALLOC_FAILURE
#define malloc(n) NULL
#endif

char *read_input(void) {
  char temp[1000];
  int c,  n=0;
  while (( c=getchar()) != '\n') 
    temp[n++] = c ;
  temp[n]='\0';
  char * res = malloc(n+1);
  strcpy(res, temp);
  return res;
}

int main(void)
{
  char *str = read_input();
  if (str==NULL) {
    printf ("Error, nothing read.\n");
    exit(1);
  }
  printf ("%s\n", str);
  free(str);
  exit(0);
}
