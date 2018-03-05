#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "chat.h"
#include "chat-lib.h"

int feedback(const char *msg, void *cc)
{
  if (cc==NULL)
    {
      return -1;
    }
  return fprintf(stdout, "\r[CHAT] %s\n", msg);
}

int main(int argc, char **argv) {
  chat_client *cc;
  int port;
  int ret;

  /*
   * 
   * Rudimentary parser
   *
   */ 
  if (argc < 3)
    {
      fprintf(stderr,"Usage:\n");
      fprintf(stderr,"  %s <hostname> <port>\n", argv[0]);
      return 1;
    }
  /* turn port number into an (unsigned) int */
  if (sscanf(argv[2], "%d", &port)!=1)
    {
      fprintf(stderr,"invalid port: %s\n", argv[2]);
      return 2;
    }

  /*
   * Init chat client values
   */
  cc = (chat_client*) chat_init(argv[1], port);
  if (cc==NULL)
    {
      fprintf(stderr, "Failed initialising the client\n");
      return 1;
    }
  
  /*
   * Use our own feedback function
   */
  chat_set_feedback_fun(cc, feedback);
  
  /*
   * Enter chat - loop until bye or quit
   */
  ret = chat_loop(cc);
  if ( (ret!=CHAT_CLIENT_OK) && (ret!=CHAT_CLIENT_LEAVE) )
    {
      fprintf(stderr, "Failed initialising the client\n");
      return 1;
    }

  /*
   * Close the chat client
   */
  chat_close(cc);
  
  return 0;
}
