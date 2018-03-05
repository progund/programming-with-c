#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>

/* dlsym, etc */
#include <dlfcn.h>

#include "chat.h"
#include "chat-internal.h"


int feedback(const char *msg, void *cc)
{
  if (cc==NULL)
    {
      return -1;
    }
  return fprintf(stdout, "\r[CHAT] %s\n", msg);
}

static void * load_chat_lib(char *name, chat_functions *cf)
{
  void *handle;
  
  handle = dlopen (name, RTLD_LAZY);
  char *error;
  if (!handle) {
    fputs (dlerror(), stderr);
    return NULL;
  }
  fprintf(stderr, "handle: %p\n", handle);

  cf->chat_init = dlsym(handle, "chat_init");
  if ((error = dlerror()) != NULL)  {
    fputs(error, stderr);
    fprintf(stderr, "could not load chat_init from lib\n");
    return NULL;
  }
  
  cf->chat_close = dlsym(handle, "chat_close");
  if ((error = dlerror()) != NULL)  {
    fputs(error, stderr);
    fprintf(stderr, "could not load chat_close from lib\n");
    return NULL;
  }
  
  cf->chat_loop = dlsym(handle, "chat_loop");
  if ((error = dlerror()) != NULL)  {
    fputs(error, stderr);
    fprintf(stderr, "could not load chat_loop from lib\n");
    return NULL;
  }
  
  cf->chat_set_feedback_fun = dlsym(handle, "chat_set_feedback_fun");
  if ((error = dlerror()) != NULL)  {
    fputs(error, stderr);
    fprintf(stderr, "could not load chat_set_feedback_fun from lib\n");
    return NULL;
  }
  
  fprintf(stderr, "chat_functions: %p\n", cf);
  
  return handle;
}

static int start_chat(char *host, int port, char *lib)
{
  void *handle;
  chat_functions c_funs;
  void *chat_lib_data;

  fprintf(stderr, "lib:  '%s'\n", lib);
  fprintf(stderr, "host: '%s'\n", host);

  fprintf(stderr, "Loading the chat lib '%s'\n", lib);
  handle = load_chat_lib(lib, &c_funs);
  if (handle == NULL)
    {
      fprintf(stderr, "Failed loading the chat lib '%s'\n", lib);
      return 1;
    }

  fprintf(stderr, "Init chat (%s,%d)'%s'\n", host, port, lib);
  chat_lib_data = c_funs.chat_init(host, port);
  if (chat_lib_data == NULL)
    {
      fprintf(stderr, "Failed initialising the client\n");
      return 1;
    }
  fprintf(stderr, "Init chat => %p \n", chat_lib_data);

  fprintf(stderr, "  -------------------- \n");
  /*
   * Use our own feedback function
   */
  c_funs.chat_set_feedback_fun(chat_lib_data, feedback);
  
  fprintf(stderr, "  -------------------- \n");
  /*
   * Enter chat - loop until bye or quit
   */
  c_funs.chat_loop(chat_lib_data);

  fprintf(stderr, "  -------------------- \n");

  /*
   * Close the chat client
   */
  c_funs.chat_close(chat_lib_data);

  fprintf(stderr, "Closing handle %p\n", handle);
  dlclose(handle);

  return CHAT_CLIENT_OK;
}

int main(int argc, char **argv)
{
  int port;
  char *host;
  char *lib;
  
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
  if (sscanf(argv[3], "%ud", &port)!=1)
    {
      fprintf(stderr,"invalid port: %s\n", argv[3]);
      return 2;
    }

  host = argv[2];
  lib = argv[1];

  start_chat(host, port, lib);
   
  return 0;
}
