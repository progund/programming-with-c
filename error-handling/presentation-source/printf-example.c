#include <stdio.h>
#include <string.h>


int
inform_user(char *msg)
{
  int ret;
  ret = printf("%s", msg);
#ifdef FAKED_PRINTF_FAILURE
  ret = ret - 2;
#endif
  return ret;
}

int main(void)
{
  int ret;
  char msg[] = "Hi there\n";


  ret = inform_user (msg);

  if ( ret < 0 )
    {
      fprintf(stderr, "Uh oh, output error is encountered\n");
    }
  /* we now know that ret is positive */
  else if ( (unsigned int)ret != strlen(msg) )
    {
      /*
       *
       * In this example we will not show you a nice solution to the
       * problem of failed printf. One solution would be to loop (a
       * limited amount) and print the remaining characters... but for
       * now, this will do fine.
       *
       */
      fprintf (stderr, "Message was only partly printed\n");
      fprintf (stderr, " * Characters printed:     %d\n", ret);
      fprintf (stderr, " * Message length:         %lu\n", strlen(msg));
      fprintf (stderr, " * Remaining characters:   %lu\n", strlen(msg)-(unsigned int)ret);
    }
  
  return 0;
}
