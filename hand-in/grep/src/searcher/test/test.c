#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../searcher.h"

int fails  = 0;
int succs  = 0;

void check_args(char *msg, sgrep_data *sdg) {
  int ret;
  printf (" * %s:", msg);
  ret = search_file(sdg);
  if (ret==2) {
    printf(" ok\n");
    succs++;
  } else {
    printf(" failed (%d)\n", ret);
    fails++;
  }
}


void check_search_string_args(char *msg, char *indata, sgrep_data *sdg)  {
  int ret;
  printf (" * %s:", msg);
  ret = search_string(indata, sdg);
  if (ret==2) {
    printf(" ok\n");
    succs++;
  } else {
    printf(" failed (%d)\n", ret);
    fails++;
  }
  
}

void check_search_string(char *indata,
                         sgrep_data *sdg, int exp)  {
  int ret;

  printf (" * is '%.20s' in '%.20s' ? :", sdg->reg_exp?sdg->reg_exp:"NULL", indata?indata:"NULL" );
  ret = search_string(indata, sdg);
  if (ret==exp) {
    printf(" ok (%d)\n", ret);
    succs++;
  } else {
    printf(" failed (%d)\n", ret);
    fails++;
  }
  
}

int main() {
  sgrep_data sdg;
  sdg.case_sense=0;
  sdg.reg_exp=NULL;
  char *test_data = "liverpool";
  
  printf ("Check search_file()\n");
  check_args(" (NULL) " , NULL);
  check_args(" (sdg) "  , &sdg);

  printf ("Check search_string()\n");
  check_search_string_args(" (NULL, NULL)      " , NULL,  NULL);
  check_search_string_args(" (NULL, sdg)       " , NULL,   &sdg);
  check_search_string_args(" (hej,  sdg->NULL) " , "hej",  &sdg);
  sdg.reg_exp = test_data;
  check_search_string("hej",  &sdg, 1);
  check_search_string("liver",  &sdg, 1);
  check_search_string("liverpool",  &sdg, 0);
  check_search_string("fcliverpool",  &sdg, 0);
  check_search_string("fcliverpoolasrome",  &sdg, 0);
  check_search_string("fcliverpoolasrome",  &sdg, 0);
  
  printf ("Tests:       %d\n", fails+succs);
  printf ("* Failures:  %d\n", fails);
  printf ("* successes: %d\n", succs);

  return fails;
}
