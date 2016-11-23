#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

/*
 * Simple program to catch signals and handle accordingly
 *
 * If you want to send a signal using bash, use the script in the same folder as this c file.
 *
 * To send a SIGINT signal:
 *
 *   ./sendsig SIGINT
 *
 * To send a SIGUSR1 signal:
 *
 *   ./sendsig SIGUSR1
 *
 * To send a SIGUSR2 signal:
 *
 *   ./sendsig SIGUSR2
 *
 */

static struct tm *get_current_time(void) {
   time_t rawtime;
   struct tm *current_time;

   time(&rawtime);
   current_time = localtime( &rawtime );
   return current_time;
}  


static void print_current_date(void) {
  struct tm *ct = get_current_time();
  printf ("%.4d-%.2d-%.2d %.2d:%.2d:%.2d\n",
          1900+ct->tm_year,
          ct->tm_mon+1,
          ct->tm_mday,
          ct->tm_hour,
          ct->tm_min,
          ct->tm_sec);
}


#define SEC_TO_USEC(a) (1000000*a)

static int global_ctr;

void handle_usr(int sigid)
{
  if (sigid==SIGUSR1)
    {
      printf ("signal received... %d\n", sigid);
      global_ctr = 0;
    }
  else if (sigid==SIGUSR2)
    {
      printf ("signal received... %d\n", sigid);
      global_ctr -= 10  ;
    }
  else if (sigid==SIGINT)
    {
      printf ("interrupt signal received... %d\n", sigid);
    }
}

int main(void)
{
  signal(SIGUSR1, handle_usr);

  /* remove this if you want to "catch" SIGUSR2 */ 
  signal(SIGUSR2, handle_usr);

  /* remove this if you want to "catch" SIGINT (caused by ctrl-c)*/
  /* signal(SIGINT, handle_usr); */
  
  while (1)
    {
      printf ("tick nr: %d  ", global_ctr);
      print_current_date();
      usleep(SEC_TO_USEC(1));
      global_ctr++;
    }

}


