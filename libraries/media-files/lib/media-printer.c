#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "medialist.h"

int
print_mediafile(mediafile *mf, FILE* stream)
{
  if ( mf==NULL || stream==NULL )
    {
      return 1;
    }
  if ( CHECK_VAR(mf->artist) &&
       CHECK_VAR(mf->album)  &&
       CHECK_VAR(mf->name) )
    {
      fprintf (stream, "media: '%s'", mf->artist);
      fprintf (stream, " '%s' ",      mf->album);
      fprintf (stream, " '%s'\n",     mf->name);
    }
  else
    {
      return 1;
    }
  
  return 0;
}

int
print_medialist(medialist *mlist, FILE* stream)
{
  unsigned int i;
  int ret;
  if (mlist==NULL || stream==NULL )
    {
      return 1;
    }
  fprintf (stream, "--------------------- list -------------- \n");
  for (i=0; i<mlist->size; i++)
    {
      ret = print_mediafile(mlist->list+i, stream);
      if (ret!=0)
        {
          return 1;
        }
    }
  return 0;
}

