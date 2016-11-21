#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "medialist.h"


int 
set_mediafile(medialist* mlist, unsigned int pos, char* artist, char* album, char* song)
{
  if ( mlist == NULL )
    {
      fprintf(stderr, "Can't set media in medialist that is NULL\n");
      return MEDIALIST_INVALID_ARGUMENTS;
    }

  if (pos >= mlist->size)
    {
      fprintf(stderr, "Can't set media at pos %d\n", pos);
      return MEDIALIST_INVALID_ARGUMENTS;
    }
  
  if (CHECK_VAR(artist) && CHECK_VAR(album) && CHECK_VAR(song))
    {
      mediafile *media = mlist->list;
      strncpy((media+pos)->artist, artist, ARTIST_SIZE);
      strncpy((media+pos)->album, album, ALBUM_SIZE);
      strncpy((media+pos)->name, song, SONG_SIZE);
    }
  else
    {
      fprintf(stderr,"Invalid media: '%s' '%s' '%s'\n",
              artist, album, song);
      return MEDIALIST_INVALID_ARGUMENTS;
    }
  return MEDIALIST_OK;
}


static int
realloc_mediafile(medialist *ml, unsigned int newsize)
{
  mediafile *list = ml->list;
  mediafile *tmp;

  tmp = realloc(list, sizeof(mediafile)*newsize);
  if (tmp==NULL)
    {
      return 1;
    }

  ml->list = tmp;
  return 0;
}

int
add_mediafile(medialist* mlist, 
              char* artist, char* album, char* song)
{
  int ret;

  if (mlist==NULL)
    {
      fprintf(stderr, "Media list NULL\n");
      return 1;
    }
  if (!(CHECK_VAR(artist) && CHECK_VAR(album) && CHECK_VAR(song)))
    {
      return 2;
    }

  ret = realloc_mediafile(mlist, mlist->size+1);
  if (ret!=0)
    {
      return 1;
    }
      
  mlist->size = mlist->size + 1;
  ret = set_mediafile(mlist, mlist->size-1, artist, album, song);
  if (ret!=0)
    {
      mlist->size = mlist->size - 1;
      return 2;
    }
  return 0;
}


int
init_medialist(medialist *mlist)
{
  if (mlist==NULL)
    {
      return MEDIALIST_INVALID_ARGUMENTS;
    }
  mlist->size=0;
  mlist->list=NULL;
  return MEDIALIST_OK;
}

int
free_medialist(medialist *mlist)
{
  if (mlist==NULL)
    {
      return MEDIALIST_INVALID_ARGUMENTS;
    }
  free(mlist->list);
  mlist->list=NULL;
  return MEDIALIST_OK;
}


