#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>

/* dlsym, etc */
#include <dlfcn.h>

#include "chat.h"

int feedback(const char *msg, void *cc)
{
  if (cc==NULL)
    {
      return -1;
    }
  return fprintf(stdout, "\r[CHAT] %s\n", msg);
}

static int load_chat_lib(char *name, chat_functions *cf)
{
  void * handle = dlopen (name, RTLD_LAZY);
  char *error;
  if (!handle) {
    fputs (dlerror(), stderr);
    return 1;
  }
  fprintf(stderr, "handle: %p\n", handle);

  cf->chat_init = dlsym(handle, "chat_init");
  if ((error = dlerror()) != NULL)  {
    fputs(error, stderr);
    fprintf(stderr, "could not load chat_init from lib\n");
    exit(1);
  }
  
  fprintf(stderr, "chat_functions: %p\n", cf);
  
  return 0;
}

int main(int argc, char **argv) {
  int port;
  char *host;
  char *lib;
  void *chat_lib_data;
  chat_functions c_funs;
  
  /*
   * 
   * Rudimentary parser
   *
   */ 
  if (argc < 4)
    {
      fprintf(stderr,"Usage:\n");
      fprintf(stderr,"  %s chat-library <hostname> <port>\n", argv[0]);
      return 1;
    }
  /* turn port number into an (unsigned) int */
  if (sscanf(argv[3], "%d", &port)!=1)
    {
      fprintf(stderr,"invalid port: %s\n", argv[3]);
      return 2;
    }

  host = argv[2];
  lib = argv[1];

  fprintf(stderr, "Loading the chat lib '%s'\n", lib);
  int loaded = load_chat_lib(lib, &c_funs);
  if (loaded != 0)
    {
      fprintf(stderr, "Failed loading the chat lib '%s'\n", lib);
      return 1;
    }

  fprintf(stderr, "Init chat '%s'\n", lib);
  chat_lib_data = c_funs.chat_init(host, port);
  if (chat_lib_data == NULL)
    {
      fprintf(stderr, "Failed initialising the client\n");
      return 1;
    }

  fprintf(stderr, "  -------------------- \n");
  /*
   * Use our own feedback function
   */
  c_funs.chat_set_feedback_fun(chat_lib_data, feedback);
  
  /*
   * Enter chat - loop until bye or quit
   */
  c_funs.chat_loop(chat_lib_data);

  printf ("sleeping\n");
  usleep(1000*1000*10);
  
  /*
   * Close the chat client
   */
  c_funs.chat_close(chat_lib_data);
  
  return 0;
}
