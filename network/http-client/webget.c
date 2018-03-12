#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <pthread.h>
#include "webget.h"


#define BUF_SIZE 1000 // buffer size for read

#define DEBUG_LOG() fprintf(stderr, "[%s:%s():%d]\n", __FILE__, __func__, __LINE__);


int
web_init(web_client* cc, char *hostname, int port)
{
  if (cc==NULL || hostname==NULL)
    {
      return WEB_CLIENT_BAD_ARG;
    }
  DEBUG_LOG();
  fprintf(stderr, "host info: %s:%d\n",
          hostname,port);
  cc->host_name = hostname; //strdup(hostname);
  cc->port = port ; //port;

  return WEB_CLIENT_OK;
}

/*
 *
 * internal function. opens and sets up a socket
 *
 */
static int open_socket(web_client* cc)
{
  if (cc==NULL)
    {
      return WEB_CLIENT_SETUP_FAILED;
    }
  
  DEBUG_LOG();
  /* Create the socket (store in cc) */
  cc->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (cc->sockfd < 0)
    {
      fprintf(stderr, "Could not open socket");
      return WEB_CLIENT_COULD_NOT_OPEN_SOCKET;
    }
  
  /* Find DNS entry for server */
  cc->server = gethostbyname(cc->host_name);
  if (cc->server == NULL)
    {
      fprintf(stderr, "Could not find host as %s\n", cc->host_name);
      return WEB_CLIENT_COULD_NOT_OPEN_SOCKET;
    }
    
  DEBUG_LOG();
  /* build address */
  bzero((char *) &cc->serveraddr, sizeof(cc->serveraddr));
  cc->serveraddr.sin_family = AF_INET;
  bcopy((char *)cc->server->h_addr, 
        (char *)&(cc->serveraddr.sin_addr.s_addr),
        (size_t)cc->server->h_length);
  cc->serveraddr.sin_port = htons((short unsigned int)cc->port);

  DEBUG_LOG();
  /* connect to server */
  if (connect(cc->sockfd,
              (struct sockaddr *)&(cc->serveraddr),
              sizeof(cc->serveraddr)) < 0)
    {
      fprintf(stderr, "Could not connect to server\n");
      return WEB_CLIENT_COULD_NOT_OPEN_SOCKET;
    }

  DEBUG_LOG();
  return WEB_CLIENT_OK;
}

/*
 *
 * See API
 *
 */
int
web_get(web_client *cc)
{
  int bytes;
  char buf[BUF_SIZE];
  int ret;
  char *get = "GET /database-servlet HTTP 1.0\n\n";
  
  if (cc==NULL)
    {
      return WEB_CLIENT_BAD_ARG;
    }

  DEBUG_LOG();
  ret = open_socket(cc);
  if (ret!=WEB_CLIENT_OK)
    {
      fprintf(stderr, "Failed opening socket: %d\n", ret);
      return WEB_CLIENT_SETUP_FAILED;
    }

  DEBUG_LOG();
  
  ret = (int)write(cc->sockfd, get, strlen(get));
  fprintf(stderr, "Wrote %d bytes.  ret=%d\n",
          (int)strlen(get), ret);
  while (1)
    {
      bzero(buf, BUF_SIZE);
      bytes = (int)read(cc->sockfd, buf, BUF_SIZE);
      if (bytes < 0)
        {
          fprintf(stderr, "ERROR reading from socket");
        }
      if (bytes == 0)
        {
          /* inform listener */
          fprintf(stderr, "Leaving since no data");
          return WEB_CLIENT_ERROR;
        }
      fprintf(stdout, "%s", buf);
    }
  
}


/*
 *
 * See API
 *
 */
void web_close(web_client *cc)
{
  close(cc->sockfd);
}

