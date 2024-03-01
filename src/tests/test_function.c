#include <check.h>

#include "tests.h"

START_TEST(sin_0) {
  // printf("\033[44msin_0\033[0m\n");
  char *string = "sin(5)";
  long double reference = sin(5);
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(sin_1) {
  // printf("\033[44msin_1\033[0m\n");
  char *string = "10-sin(5-(2*3)*10)";
  long double reference = 10 - sin(5 - (2 * 3) * 10);
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(sin_2) {
  // printf("\033[44msin_2\033[0m\n");
  char *string = "10-sin(10)";
  long double reference = 10 - sin(10);
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(cos_0) {
  // printf("\033[44mcos_0\033[0m\n");
  char *string = "10-cos(5-(2*3)*10)";
  long double reference = 10 - cos(5 - (2 * 3) * 10);
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(cos_1) {
  // printf("\033[44mcos_1\033[0m\n");
  char *string = "10-cos(10)";
  long double reference = 10 - cos(10);
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(tan_0) {
  // printf("\033[44mtan_0\033[0m\n");
  char *string = "10-tan(5-(2*3)*10)";
  long double reference = 10 - tan(5 - (2 * 3) * 10);
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(tan_1) {
  // printf("\033[44mtan_1\033[0m\n");
  char *string = "10-tan(10)";
  long double reference = 10 - tan(10);
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(asin_0) {
  // printf("\033[44masin_0\033[0m\n");
  char *string = "10-asin(5-(2*3)*10)";
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_nan(result);
}

START_TEST(asin_1) {
  // printf("\033[44masin_1\033[0m\n");
  char *string = "10-asin(0.5)";
  long double reference = 10 - asin(0.5);
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(acos_0) {
  // printf("\033[44macos_0\033[0m\n");
  char *string = "10-acos(1-1/245*10)";
  long double reference = 10.0 - acos(1.0 - 1.0 / 245.0 * 10.0);
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(acos_1) {
  // printf("\033[44macos_1\033[0m\n");

  char *string = "10-acos(0.34)";
  long double reference = 10 - acos(0.34);
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(atan_0) {
  // printf("\033[44matan_0\033[0m\n");

  char *string = "10-atan(5-(2*3)*10)";
  long double reference = 10 - atan(5 - (2 * 3) * 10);
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(atan_1) {
  // printf("\033[44matan_1\033[0m\n");

  char *string = "10-atan(10)";
  long double reference = 10 - atan(10);
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(sqrt_0) {
  // printf("\033[44msqrt_0\033[0m\n");
  char *string = "10-sqrt(5-(2*3)*10)";
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_nan(result);
}

START_TEST(sqrt_1) {
  // printf("\033[44msqrt_1\033[0m\n");
  char *string = "10-sqrt(10)";
  long double reference = 10 - sqrt(10);
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(ln_0) {
  // printf("\033[44mlog_0\033[0m\n");
  char *string = "10-ln(5-(2*3)*10)";
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_nan(result);
}

START_TEST(ln_1) {
  // printf("\033[44mlog_1\033[0m\n");
  char *string = "10-ln(10)";
  long double reference = 10 - log(10);
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

START_TEST(log_0) {
  // printf("\033[44mlog10_0\033[0m\n");
  char *string = "10-log(5-(2*3)*10)";
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_nan(result);
}

START_TEST(log_1) {
  // printf("\033[44mlog10_1\033[0m\n");
  char *string = "10-log(10)";
  long double reference = 10 - log10(10);
  long double result;
  result = dijkstraAlgorithm(string, 0);
  ck_assert_ldouble_eq_tol(reference, result, ACCURACY);
}

Suite *testFunctions(void) {
  Suite *suite = suite_create("\033[45m-=FUNCTIONS=-\033[0m");
  TCase *test_case = tcase_create("function_test_case");

  tcase_add_test(test_case, sin_0);
  tcase_add_test(test_case, sin_1);
  tcase_add_test(test_case, sin_2);
  tcase_add_test(test_case, cos_0);
  tcase_add_test(test_case, cos_1);
  tcase_add_test(test_case, tan_0);
  tcase_add_test(test_case, tan_1);
  tcase_add_test(test_case, asin_0);
  tcase_add_test(test_case, asin_1);
  tcase_add_test(test_case, acos_0);
  tcase_add_test(test_case, acos_1);
  tcase_add_test(test_case, atan_0);
  tcase_add_test(test_case, atan_1);
  tcase_add_test(test_case, sqrt_0);
  tcase_add_test(test_case, sqrt_1);
  tcase_add_test(test_case, ln_0);
  tcase_add_test(test_case, ln_1);
  tcase_add_test(test_case, log_0);
  tcase_add_test(test_case, log_1);

  suite_add_tcase(suite, test_case);
  return suite;
}