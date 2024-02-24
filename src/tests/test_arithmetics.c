#include <check.h>

#include "tests.h"

START_TEST(arithmetics_0) {
  char *string = "(1+2-3)*4";
  long double reference = (1 + 2 - 3) * 4;
  long double result;
  result = dijkstraAlgorithm(string);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(arithmetics_1) {
  char *string = "(1+2)*3^2^2-6/(7+8/9)";
  long double reference = (1 + 2) * pow(3, pow(2, 2)) - 6.0 / (7 + 8.0 / 9);
  long double result;
  result = dijkstraAlgorithm(string);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(arithmetics_2) {
  char *string = "5/2-(1+3.5)*3^4";
  long double reference = 5.0 / 2 - (1 + 3.5) * pow(3, 4);
  long double result;
  result = dijkstraAlgorithm(string);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(arithmetics_3) {
  char *string = "2*(3+5/2)";
  long double reference = 2 * (3 + 5.0 / 2);
  long double result;
  result = dijkstraAlgorithm(string);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(arithmetics_4) {
  char *string = "4^3^2-1";
  long double reference = pow(4, pow(3, 2)) - 1;
  long double result;
  result = dijkstraAlgorithm(string);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(arithmetics_5) {
  char *string = "2*(3+5/(2-4))";
  long double reference = 2 * (3 + 5.0 / (2 - 4));
  long double result;
  result = dijkstraAlgorithm(string);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(arithmetics_6) {
  char *string = "2mod4";
  long double reference = fmod(2, 4);
  long double result;
  result = dijkstraAlgorithm(string);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(arithmetics_7) {
  char *string = "3*2mod5+345/3";
  long double reference = 3 * fmod(2, 5) + 345.0 / 3;
  long double result;
  result = dijkstraAlgorithm(string);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(arithmetics_8) {
  char *string = "-2 * 23";
  long double reference = -2 * 23;
  long double result;
  result = dijkstraAlgorithm(string);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(arithmetics_9) {
  char *string = "2*-(4+4)";
  long double reference = 2 * -(4 + 4);
  long double result;
  result = dijkstraAlgorithm(string);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(arithmetics_10) {
  char *string = "2*-sin(4+4)";
  long double reference = 2 * -sin(4 + 4);
  long double result;
  result = dijkstraAlgorithm(string);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

Suite *testArithmetics(void) {
  Suite *suite = suite_create("\033[45m-=ARITHMETICS=-\033[0m");
  TCase *test_case = tcase_create("arithmetics_test_case");

  tcase_add_test(test_case, arithmetics_0);
  tcase_add_test(test_case, arithmetics_1);
  tcase_add_test(test_case, arithmetics_2);
  tcase_add_test(test_case, arithmetics_3);
  tcase_add_test(test_case, arithmetics_4);
  tcase_add_test(test_case, arithmetics_5);
  tcase_add_test(test_case, arithmetics_6);
  tcase_add_test(test_case, arithmetics_7);
  tcase_add_test(test_case, arithmetics_8);
  tcase_add_test(test_case, arithmetics_9);
  tcase_add_test(test_case, arithmetics_10);

  suite_add_tcase(suite, test_case);
  return suite;
}