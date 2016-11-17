#include  <stdio.h>
#include  <string.h>


/*
 * This is a program to be used as a basis for discussion
 *
 * We know that passwords are not stored this way.
 *
 *
 */

void print_entire(char *buffer, int size)
{
  int i;
  for (i=0;i<size;i++)
    {
      printf("%c", buffer[i]);
    }
  printf("\n");
}


void erase_entire(char *buffer, int size, char val)
{
  int i;
  for (i=0;i<size;i++)
    {
      buffer[i]=val;
    }
}

int main(void)
{
  char password[]="hi there";
  int length = (int)strlen(password);
  printf("First round\n");
  printf (" * password: %s\n", password);
  printf (" * password: ");
  print_entire(password, length);

  printf("Trying stupidly to erase password\n");
  strcpy(password, "");
  printf (" * password: %s\n", password);
  printf (" * password: ");
  print_entire(password, length);

  printf("Trying to erase password\n");
  erase_entire(password, length, 0);
  erase_entire(password, length, 1);
  erase_entire(password, length, 0);
  erase_entire(password, length, 1);
  printf (" * password: %s\n", password);
  printf (" * password: ");
  print_entire(password, length);
  
  return 0;
}
