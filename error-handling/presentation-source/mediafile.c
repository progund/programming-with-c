#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "mediafile.h"

void
print_media(mediafile *list, int nr_of_media)
{
  int i;
  printf ("---------------------\n");
  for (i=0; i<nr_of_media; i++)
    {
      printf ("media: '%s'", list[i].artist);
      printf (" '%s' ",      list[i].album);
      printf (" '%s'\n",     list[i].name);
    }
}

#define CHECK_VAR(a) a!=NULL && strlen(a)>0

int 
set_mediafile(mediafile* list, char* artist, char* album, char* song)
{
  if ( list == NULL )
    {
      return -1;
    }

  if (CHECK_VAR(artist) && CHECK_VAR(album) && CHECK_VAR(song))
    {
      strcpy(list->artist, artist);
      strcpy(list->album,  album);
      strcpy(list->name,   song);
    }
  else
    {
      fprintf(stderr,"Invalid media: '%s' '%s' '%s'\n",
              artist, album, song);
      return 1;
    }
  return 0;
}



