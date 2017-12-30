#ifndef MEDIALIST_H
#define MEDIALIST_H

#define SONG_SIZE    24
#define ARTIST_SIZE  24
#define ALBUM_SIZE   24

#define CHECK_VAR(a) (a!=NULL && strlen(a)>0)

enum
  {
    MEDIALIST_OK,
    MEDIALIST_INVALID_ARGUMENTS,
    MEDIALIST_ALLOC_FAILED
  } return_codes;

typedef struct mediafile_
{
  char name[SONG_SIZE];
  char artist[ARTIST_SIZE];
  char album[ALBUM_SIZE];
} mediafile;

typedef struct medialist_
{
  mediafile *  list;
  unsigned int size;
} medialist;




int
init_medialist(medialist *list);

int 
set_mediafile(medialist* mlist, unsigned int pos, char* artist, char* album, char* song);

int
add_mediafile(medialist* mlist, 
              char* artist, char* album, char* song);

int
free_medialist(medialist *mlist);

#endif /* MEDIALIST_H */
