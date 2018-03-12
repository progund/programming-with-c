#include <stdio.h>
#include "webget.h"


int main(int argc, char **argv)
{
  int ret;
  int port;
  char *host;
  web_client wc;

  port = 8080;
  if ( argc < 2 )
    {
      fprintf(stderr, "Missing host name\n");
      return 1;
    }
  else if ( argc == 2 )
    {
      host = argv[1];
    }
  else
    {
      host = argv[1];
      ret = sscanf(argv[2], "%d", &port);
      if ( ret != 1 )
        {
          fprintf(stderr, "Bad port %s\n", argv[2]);
          return 1;
        }
    }
  
  ret = web_init(&wc, host, port);
  if (ret != 0 )
    {
      fprintf(stderr, "Failed initialising\n");
      return 1;
    }

  web_get(&wc);

}
