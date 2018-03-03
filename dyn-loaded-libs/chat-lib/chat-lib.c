#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "chat.h"


#define BUF_SIZE 1000 // buffer size for read


static void* chat_loop_impl(void *arg);

/*
 *
 * Built in function for printing chat client info
 *
 */
void print_chat_client_info(chat_client *cc)
{
  fprintf(stderr, "\n\nChat client\n");
  fprintf(stderr, "* cc:        %p\n", (void*)cc);
  fprintf(stderr, "* host name: %s\n", cc->host_name);
  fprintf(stderr, "* port:      %d\n", cc->port);
}

/*
 *
 * Built in function for used feedback
 *
 */
static int print_msg(char *msg, chat_client *cc)
{
  if (cc==NULL)
    {
      return -1;
    }
  return fprintf(stdout, "%s\n", msg);
}

/*
 *
 * See API
 *
 */
void chat_set_feedback_fun(chat_client *cc, input_handler fun)
{
  cc->feedback = fun;
}

/*
 *
 * See API
 *
 */
void*
chat_init(char *hostname, int port)
{
  chat_client* cc =
    calloc(sizeof(chat_client), 1);

  if (cc==NULL || hostname==NULL)
    {
      return NULL;
    }

  
  fprintf(stderr, "Setting host: %s:%d\n",
          hostname, port);

  cc->host_name = strdup("localhost"); //strdup(hostname);
  cc->port = 1066 ; //port;

  chat_set_feedback_fun(cc, (input_handler)print_msg);
  
  return cc;
}

/*
 *
 * internal function. opens and sets up a socket
 *
 */
static int open_socket(chat_client* cc)
{
  if (cc==NULL)
    {
      return CHAT_CLIENT_SETUP_FAILED;
    }
  
  /* Create the socket (store in cc) */
  cc->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (cc->sockfd < 0)
    {
      fprintf(stderr, "Could not open socket");
      print_chat_client_info(cc);
      return CHAT_CLIENT_COULD_NOT_OPEN_SOCKET;
    }
  
  /* Find DNS entry for server */
  cc->server = gethostbyname(cc->host_name);
  if (cc->server == NULL)
    {
      fprintf(stderr, "Could not find host as %s\n", cc->host_name);
      print_chat_client_info(cc);
      return CHAT_CLIENT_COULD_NOT_OPEN_SOCKET;
    }
    
  /* build address */
  bzero((char *) &cc->serveraddr, sizeof(cc->serveraddr));
  cc->serveraddr.sin_family = AF_INET;
  bcopy((char *)cc->server->h_addr, 
        (char *)&(cc->serveraddr.sin_addr.s_addr),
        (size_t)cc->server->h_length);
  cc->serveraddr.sin_port = htons((short unsigned int)cc->port);

  /* connect to server */
  if (connect(cc->sockfd,
              (struct sockaddr *)&(cc->serveraddr),
              sizeof(cc->serveraddr)) < 0)
    {
      fprintf(stderr, "Could not connect to server\n");
      print_chat_client_info(cc);
      return CHAT_CLIENT_COULD_NOT_OPEN_SOCKET;
    }

  FD_ZERO(&(cc->read_fds));
    
  cc->nfds = (unsigned int)cc->sockfd +2;
    
  return CHAT_CLIENT_OK;
}

int
chat_loop(chat_client *cc)
{
  int ret;
  
  ret = pthread_create(&cc->chat_thread,
                       NULL,
                       chat_loop_impl,
                       (void*)cc);
  cc->running = 1;
  return ret;
}

/*
 *
 * See API
 *
 */
static void*
chat_loop_impl(void *arg)
{
  int bytes;
  char buf[BUF_SIZE];
  int ret;

  chat_client *cc = (chat_client *) arg;
  
  if (cc==NULL)
    {
      return NULL;
    }

  ret = open_socket(cc);
  if (ret!=CHAT_CLIENT_OK)
    {
      fprintf(stderr, "Failed opening socket: %d\n", ret);
      return NULL;
    }

  while (cc->running)
    {
      printf("type>");
      fflush(stdout);

      FD_SET(STDIN_FILENO,&(cc->read_fds));
      FD_SET(cc->sockfd,&(cc->read_fds)); 

      if (select((int)cc->nfds,&(cc->read_fds),NULL,NULL,NULL) == -1){
        fprintf(stderr, "select failed....");
        return NULL;
      }

      if (FD_ISSET(cc->sockfd, &(cc->read_fds)))
        {
          /* read from server */
          bzero(buf, BUF_SIZE);
          bytes = (int)read(cc->sockfd, buf, BUF_SIZE);
          if (bytes < 0)
            {
              fprintf(stderr, "ERROR reading from socket");
            }
          if (bytes == 0)
            {
              /* inform listener */
              cc->feedback("Leaving since user typed 'bye'", cc);
              return NULL ;
            }
          printf("feedbacking on %p\n", (unsigned char *)((void*)cc->feedback));
          printf("feedbacking on %p\n", (void*)cc->feedback);
          cc->feedback(buf, cc);
        }
      else
        {
          /* read from stdin */
          bzero(buf, BUF_SIZE);
          fgets(buf, BUF_SIZE, stdin);
          
          ret = chat_handle_input(cc, buf);
          if (ret==CHAT_CLIENT_LEAVE)
            {
              return NULL;
            }
        }
      
    }
  return NULL;
}

/*
 * internal macro for checking strings
 */
#define COMP_STR(a,b) strncmp(a, b, strlen(a))

/*
 *
 * See API
 *
 */
int chat_handle_input(chat_client *cc, char *msg)
{
  int written;
  
  if (cc==NULL || msg==NULL)
    {
      return CHAT_CLIENT_BAD_ARG;
    }

  if (COMP_STR(".quit", msg)==0)
    {
      return CHAT_CLIENT_LEAVE;
    }

  written = (int)write(cc->sockfd, msg, strlen(msg));
  if (written < 0)
    {
      fprintf(stderr,
              "Failed writing to socket: '%s'\n",
              msg);
      return CHAT_CLIENT_ERROR;
    }
  return CHAT_CLIENT_OK;  
}

/*
 *
 * See API
 *
 */
void chat_close(chat_client *cc)
{
  cc->running=0;
  pthread_cancel(cc->chat_thread);
  
  close(cc->sockfd);
}

