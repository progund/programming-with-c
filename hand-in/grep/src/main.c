#include <stdio.h>

#include "parser.h"
#include "searcher.h"

int main(int argc, char **argv) {
  sgrep_data sgd;


  /* Call parse */
  parse(argc-1, ++argv, &sgd);
  /* check return values ...*/
  
  /* Call search_file */
  search_file(&sgd);
  /* check return values ...*/

  /*
   * make sure to return according to specification
   */
}
