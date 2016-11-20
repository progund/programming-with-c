#include <stdio.h>
#include <assert.h>
#include "../medialist.h"


void
test_add_mediafile(medialist *ml)
{
  unsigned int i ;
  unsigned int limit = 100  ;
  int ret  ;
  
  printf ("Adding first:");
  ret = add_mediafile(ml, "Arty", "Alby", "Songy");
  assert(ret==0);
  assert(ml->size==1);
  assert(ml->list!=NULL);
  printf (" OK\n");

  printf ("Adding second:");
  ret = add_mediafile(ml, "Arty2", "Alby2", "Songy2");
  assert(ret==0);
  assert(ml->size==2);
  assert(ml->list!=NULL);
  printf (" OK\n");

  printf ("Adding bad artist:");
  ret = add_mediafile(ml, NULL, "Alby2", "Songy2");
  assert(ret==2);
  assert(ml->size==2);
  assert(ml->list!=NULL);
  printf (" OK\n");

  printf ("Adding bad album:");
  ret = add_mediafile(ml, "Artr2", NULL, "Songy2");
  assert(ret==2);
  assert(ml->size==2);
  assert(ml->list!=NULL);
  printf (" OK\n");

  printf ("Adding bad song:");
  ret = add_mediafile(ml, "arti", "Alby2", NULL);
  assert(ret==2);
  assert(ml->size==2);
  assert(ml->list!=NULL);
  printf (" OK\n");

  printf ("Adding with bad medialist:");
  ret = add_mediafile(NULL, "arti", "Alby2", "sldkj");
  assert(ret==1);
  assert(ml->size==2);
  assert(ml->list!=NULL);
  printf (" OK\n");
  

  for (i=0; i<limit; i++)
    {
      printf ("Adding %d of %d:", i, limit);
      ret = add_mediafile(ml, "Arty2", "Alby2", "Songy2");
      assert(ret==0);
      assert(ml->size==(2+i+1));
      assert(ml->list!=NULL);
      printf (" OK\n");
    }
  
}


int main(void)
{
  medialist list;
  init_medialist(&list);
  assert(list.size==0);
  assert(list.list==NULL);

  test_add_mediafile(&list);

  return 0;
}
