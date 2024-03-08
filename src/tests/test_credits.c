#include <check.h>

#include "tests.h"

START_TEST(annuity_01) {
  double creditAmount = 2000000;
  double interestRate = 15;
  int creditTerm = 60;
  double reference = 47579.9;
  double result = annuity(creditAmount, interestRate, creditTerm);
  ck_assert_double_eq_tol(reference, result, 1e-01);
}

START_TEST(differentiated_01) {
  double creditAmount = 300000;
  double interestRate = 20;
  int creditTerm = 6;
  double result[creditTerm];
  double reference = 54931.506849;
  differentiated(creditAmount, interestRate, creditTerm, result);
  ck_assert_double_eq_tol(reference, result[0], 1e-01);
}

Suite *testCredits(void) {
  Suite *suite = suite_create("\033[45m-=CREDITS=-\033[0m");
  TCase *test_case = tcase_create("credits_test_case");

  tcase_add_test(test_case, annuity_01);
  tcase_add_test(test_case, differentiated_01);

  suite_add_tcase(suite, test_case);
  return suite;
}