#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../parser.h"

int fails  = 0;
int succs  = 0;

void check_args(char *msg, int argc, char **argv,
                sgrep_data *sdg,     int exp) {
  int ret;

  printf (" * %s:", msg);
  ret = parse(argc, argv, sdg);
  if (ret==exp) {
    printf(" ok (%d)\n", ret);
    succs++;
  } else {
    printf(" failed (%d)\n", ret);
    fails++;
  }
}


/*
 *
 * Supply valid args etc and make sure all is well
 *
 */
void check_sgd_regexp_good(char *msg, int argc, char **argv,
                      sgrep_data *sdg,
                      int exp_ret, char *exp) {
  int ret;

  printf (" * %s:", msg);
  ret = parse(argc, argv, sdg);
  if (ret==exp_ret &&
      (strcmp(sdg->reg_exp, exp)==0) &&
      strlen(sdg->reg_exp) == strlen(exp)) {
    printf(" ok (%d)\n", ret);
    succs++;
  } else {
    printf(" failed\n");
    fails++;
  }
}


int main() {
  sgrep_data sdg;

  char *zero = "sgrep";
  char *one  = "needle";

  char *args[] = {
    zero, one };

  char *args_small[] = {
    one };

  char *args_empty[] = {
    "" };

  check_args(" 10, NULL ", 10, NULL,      &sdg,  1);
  check_args(" 0, args ",  0, args,       &sdg,  1);
  check_args(" 2, args ",  2, args_empty, &sdg,  2); // Odd test

  check_sgd_regexp_good(" 1, needle ",  1, args_small, &sdg, 0, "needle");
  check_sgd_regexp_good(" 1, \"\" ",  1, args_empty, &sdg, 0, "");
  
  printf ("Tests:       %d\n", fails+succs);
  printf ("* Failures:  %d\n", fails);
  printf ("* successes: %d\n", succs);

  return fails;
}
