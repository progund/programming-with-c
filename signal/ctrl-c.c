#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void sighandler(int sig)
{
  printf ("SIGINT (%d) cuaght, will print this and continue afterwards\n", sig);
}

int
main(void)
{

  signal(SIGINT, sighandler); 
  
  while (1)
    {
      printf (".");
      fflush(stdout);
      usleep (100000);
    }

  return 0;
}
