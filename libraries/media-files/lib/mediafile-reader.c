#include <stdio.h>
#include <string.h>
#include "medialist.h"
#include "mediafile-reader.h"


static int
read_from_user(char *prompt, char* storage, int max_size)
{
  char *tmp;
  printf("%s ", prompt);
  tmp = fgets(storage,max_size,stdin);
  /* If NULL, return */
  if (tmp==NULL)
    {
      return -1;
    }

  /* Ok, NOT NULL*/
  
  /* trim trailing newline */
  if (storage[strlen(storage)-1]=='\n')
    {
      storage[strlen(storage)-1]='\0';
    }
  else
    {
      while (getc(stdin)!='\n')
        {
          printf(".");
        }
      return 2;
    }
  
  return 0;
}


int
read_media_user(medialist *ml)
{
  char artist_buffer[ARTIST_SIZE];
  char album_buffer[ALBUM_SIZE];
  char song_buffer[SONG_SIZE];
  int ret;
  ret = read_from_user("Artist: ", artist_buffer, ARTIST_SIZE);
  if (ret != 0 )
    {
      return ret;
    }
  ret = read_from_user("Album: ", album_buffer, ALBUM_SIZE);
  if (ret != 0 )
    {
      return ret;
    }
  ret = read_from_user("Song: ", song_buffer, SONG_SIZE);
  if (ret != 0 )
    {
      return ret;
    }
  
  return add_mediafile(ml,
                       artist_buffer,
                       album_buffer,
                       song_buffer);
}

