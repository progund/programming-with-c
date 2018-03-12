#include <stdio.h>
#include "webget.h"


int main(int argc, char **argv)
{
  int ret;
  int port;
  char *host;
  char *path;
  web_client wc;

  port = 8080;
  path = "/";
  if ( argc < 2 )
    {
      fprintf(stderr, "Missing host name\n");
        return 1;
    }
  if ( argc > 1 )
    {
      host = argv[1];
    }
  if ( argc > 2 )
    {
      ret = sscanf(argv[2], "%d", &port);
      if ( ret != 1 )
        {
          fprintf(stderr, "Bad port %s\n", argv[2]);
          return 1;
        }
    }
  if ( argc > 3 )
    {
      path = argv[3]; 
    }
  
  ret = web_init(&wc, host, port);
  if (ret != 0 )
    {
      fprintf(stderr, "Failed initialising\n");
      return 1;
    }

  web_get(&wc, path);

}
