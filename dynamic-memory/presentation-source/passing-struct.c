#include <stdio.h>

typedef struct 
{
  int width;
  int heigth;
} dummy;

void
print_dummy(dummy d)
{
  printf ("dummy: %d x %d\n",
          d.width, d.heigth);
}

void
update_dummy(dummy d)
{
  d.width++;
  d.heigth++;
  printf ("updated to "); print_dummy(d);
}

void
update_dummyp(dummy *d)
{
  d->width+=100;
  d->heigth-=100;
}


int main(void)
{
  dummy d;
  d.width  = 12;
  d.heigth = 13;
  print_dummy(d);
  update_dummy(d);
  print_dummy(d);
  update_dummyp(&d);
  print_dummy(d);

  return 0;
}
        
