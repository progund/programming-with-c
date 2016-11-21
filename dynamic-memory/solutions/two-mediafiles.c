#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * WARNING: this program contains some code samples on how to allocate
 * nad use dynamic memory. There are no programs as the below.
 *
 * DO NOT USE THIS PROGRAM AS BASIS FOR ANYTHING :)
 *
 *
 */


#define SONG_SIZE    24
#define ARTIST_SIZE  24
#define ALBUM_SIZE   24

typedef struct mediafile_
{
  char name[SONG_SIZE];
  char artist[ARTIST_SIZE];
  char album[ALBUM_SIZE];
} mediafile;


/**
 *
 * Function to set a mediafile struct
 *
 *
 */
int
set_mediafile(mediafile *mf, char *artist, char *album, char *name)
{
  char *tmp;
  
  tmp = strncpy(mf->name, name, SONG_SIZE);
  if (tmp==NULL)
    {
      return 1;
    }
  tmp = strncpy(mf->artist, artist, ARTIST_SIZE);
  if (tmp==NULL)
    {
      return 1;
    }
      
  tmp = strncpy(mf->album, album, ALBUM_SIZE);
  if (tmp==NULL)
    {
      return 1;
    }
  return 0;
}

/**
 *
 * Function to print a mediafile struct
 *
 *
 */
void print_mediafile(mediafile *mf)
{
  printf ("%s | %s | %s\n",
          mf->artist, mf->album, mf->name);
}

int
main(void)
{
  mediafile* mf;
  mediafile *tmp;
  int ret;
  
  /*
   * Allocate memory for 1 mediafile
   *
   */
  mf = calloc(1, sizeof(mediafile));
  if (mf == NULL)
    {
      exit(1);
    }

  /*
   * Set the newly allocated memory to some values
   */
  ret = set_mediafile (mf, "Bonnie 'Prince' Billy",
                 "Ease down the road",                 
                 "May it always be");
  /* Check if it went ok */
  if (ret!=0)
    {
      /* We failed... too bad. Time to exit
       * free the memory first */
      free(mf);
      exit(1);
    }

  print_mediafile(mf);
  
  /*
   * Reallocate memory for 1 mediafile
   *
   * Store the resulting memory in tmp in case we fail (re)allocating 
   */
  tmp = realloc(mf, sizeof(mediafile)*2);
  /* Check if we failed (re)allocating new memory */
  if (tmp==NULL)
    {
      /* We failed... too bad. Time to exit
       * free the memory first */
      free(mf);
      exit(1);
    }
  mf = tmp;

  /*
   * Set the newly allocated (extra) memory to some values
   */
  ret = set_mediafile ((mf+1), "Bonnie 'Prince' Billy",
                 "Joy and Jubilee",                 
                 "Master and Everyone");
  /* Check if it went ok */
  if (ret!=0)
    {
      /* We failed... too bad. Time to exit
       * free the memory first */
      free(mf);
      exit(1);
    }

  /* ...and print */
  print_mediafile(mf);
  print_mediafile(mf+1);
  
  /* free the mem */
  free(mf);
  return 0;
}
