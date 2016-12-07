#include <stdio.h>
#include <check.h>
#include <limits.h>

int
max(int a, int b)
{
  if (a>b)
    {
      return a;
    }
  return b;
}



START_TEST (test_max)
{
  printf ("Test max using assert:      ");
  ck_assert_int_eq(max(13,14),14);
  ck_assert_int_eq(max(INT_MAX,-1),INT_MAX);
  printf (" OK\n");
}
END_TEST


Suite * max_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Max");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_max);
    suite_add_tcase(s, tc_core);

    return s;
}

int
main(void)
{
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = max_suite();
  sr = srunner_create(s);
  
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;
}

