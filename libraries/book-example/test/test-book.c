#include <stdio.h>
#include <string.h>

#include "book.h"

int main(void)
{
  book_t b;
  book_set(&b, "Pendulum", "Umberto Eco", "umberto@thegreatone.com");

  book_print(&b);

  return 0;
}
