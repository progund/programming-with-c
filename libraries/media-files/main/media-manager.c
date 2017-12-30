#include <stdio.h>
#include "medialist.h"
#include "media-printer.h"
#include "mediafile-reader.h"


#define NR_OF_FAKED_MEDIA 10
int main(void)
{
  int ret;
  medialist list;
  list.list=NULL;
  list.size=0;

  while (1)
    {
      ret = read_media_user(&list);
      if (ret==-1)
        {
          break;
        }
    }

  print_medialist(&list, stdout);

  free_medialist(&list);
  return 0;
}

