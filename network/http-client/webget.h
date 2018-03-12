#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

/**
 * @file webget.h
 * @author Henrik Sandklef, Rikard Fröberg
 * @date 12 march 2018
 */

/**
 * @brief Return values
 *
 * Return values used by the web API.
 */
enum
  {
    WEB_CLIENT_OK,
    WEB_CLIENT_BAD_ARG,
    WEB_CLIENT_SETUP_FAILED,
    WEB_CLIENT_COULD_NOT_OPEN_SOCKET,
    WEB_CLIENT_ERROR,
    WEB_CLIENT_LEAVE
  };


/**
 * @brief Data structure for web client
 *
 * This structure contains everything needed for networking and giving
 * feedback to the user.
 */
typedef struct web_client_
{
  int sockfd;
  int port;
  struct sockaddr_in serveraddr;
  struct hostent *server;
  char *host_name;
} web_client ;


/** 
 * @brief Initialise the struct with hostname and port number.
 *
 * This function sets up the struct, using hostname and port number. 
 *
 * @param cc - a pointer to web_client
 * @param hostname - name of the server to connect to
 * @param port - port number of the server to tonnect to
 * @return an integer idicating success (WEB_CLIENT_OK e(0)) or error
 */
int web_init(web_client* cc, char *hostname, int port);

/** 
 * @brief Closes the web session pointed to by the struct.
 *
 * This function closes the web associated with the struct.
 *
 * @param cc - a pointer to web_client
 * @return void
 */
void web_close(web_client *cc);

/** 
 * @brief Start the web
 *
 * This function starts up the web client. It will listen for input
 * from user on stdin and provide feedback to the user via stdout.
 *
 * @param cc - a pointer to web_client
 * @return an integer idicating success (WEB_CLIENT_OK e(0)) or error
 */
int web_get(web_client *cc, char *path);
