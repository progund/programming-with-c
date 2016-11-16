#include <stdio.h>
#include "mediafile.h"
#include "mediafile-reader.h"


#define NR_OF_FAKED_MEDIA 10
int main(void)
{
  static mediafile list[NR_OF_FAKED_MEDIA];
  int i;
  /*  add_fake_media ((mediafile*)&list, NR_OF_FAKED_MEDIA);*/
  for (i=0;i<NR_OF_FAKED_MEDIA; i++)
    {
      int ret = read_media_user(&list[i]);
      printf ("reading to %d ret: %d\n", i, ret);
      /*      if (ret==0)
        {
          i++;
        }
      
        else */ if (ret == -1 )
        {
          fprintf(stderr, "No more data to read\n");
          break;
        }
    }
  printf ("\n");

  print_media((mediafile*)&list, i);
  return 0;
}

