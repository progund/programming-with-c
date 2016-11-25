#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "searcher.h"

#include "sgrep_data.h"


int search_string(char *indata, sgrep_data* sdg) {

  /*Note: You can use the GNU Libc function called strcasestr if you
    want to find a string in a string ignoring case.*/
  
  return SEARCHER_OK_MATCHES;
}


int
search_file(sgrep_data *sdg)  {
  return SEARCHER_OK_MATCHES;
}
