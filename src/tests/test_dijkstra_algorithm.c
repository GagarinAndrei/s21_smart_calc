#include <check.h>
#include <stdio.h>

#include "tests.h"

START_TEST(dijkstra_0) {
  char *string = "(1+2-3)*4";
  long double reference = (1 + 2 - 3) * 4;
  long double result;
  printf("\033[44m%s\033[0m\n", string);
  result = dijkstraAlgorithm(string);
  printf("\033[44mREFERENCE: %Lf\033[0m\n", reference);
  printf("\033[44mRESULT:    %Lf\033[0m\n", result);
  ck_assert_double_eq_tol(reference, result, ACCURACY);
}

START_TEST(dijkstra_1) {
  char *string = "(1+2)*3^2^2-6/(7+8/9)";
  long double reference = (1 + 2) * pow(3, pow(2, 2)) - 6.0 / (7 + 8.0 / 9);
  long double result;
  result = dijkstraAlgorithm(string);
  ck_assert_double_eq_tol(reference, result, ACCURACY);
}

START_TEST(dijkstra_2) {
  char *string = "5/2 - (1 + 3.5) * 3^4";
  long double reference = 5.0 / 2 - (1 + 3.5) * pow(3, 4);
  long double result;
  printf("\033[44m%s\033[0m\n", string);
  result = dijkstraAlgorithm(string);
  printf("\033[44mREFERENCE: %Lf\033[0m\n", reference);
  printf("\033[44mRESULT:    %Lf\033[0m\n", result);
  ck_assert_double_eq_tol(reference, result, ACCURACY);
}

// START_TEST(dijkstra_3) {
//   char *string = "2*(3+5/2)";
//   long double reference = 2 * (3 + 5.0 / 2);
//   long double result;
//   result = dijkstraAlgorithm(string);
//   ck_assert_double_eq_tol(reference, result, ACCURACY);
// }

// START_TEST(dijkstra_4) {
//   char *string = "4^3^2-1";
//   long double reference = pow(4, pow(3, 2)) - 1;
//   long double result;
//   result = dijkstraAlgorithm(string);
//   ck_assert_double_eq_tol(reference, result, ACCURACY);
// }

// START_TEST(dijkstra_5) {
//   char *string = "2*(3+5/2-4)";
//   long double reference = 2 * (3 + 5.0 / 2 - 4);
//   long double result;
//   result = dijkstraAlgorithm(string);
//   ck_assert_double_eq_tol(reference, result, ACCURACY);
// }

// START_TEST(dijkstra_6) {
//   char *string = "sin(5)";
//   long double reference = sin(5);
//   long double result;
//   printf("\033[44m%s\033[0m\n", string);
//   result = dijkstraAlgorithm(string);
//   printf("\033[44mREFERENCE%Lf\033[0m\n", reference);
//   printf("\033[44mRESULT%Lf\033[0m\n", result);
//   ck_assert_double_eq_tol(reference, result, ACCURACY);
// }

// START_TEST(dijkstra_7) {
//   char *string = "10-sin(5-(2*3)*10)";
//   long double reference = 10 - sin(5 - (2 * 3) * 10);
//   long double result;
//   printf("\033[44m%s\033[0m\n", string);
//   result = dijkstraAlgorithm(string);
//   printf("\033[44mREFERENCE: %Lf\033[0m\n", reference);
//   printf("\033[44mRESULT:    %Lf\033[0m\n", result);
//   ck_assert_double_eq_tol(reference, result, ACCURACY);
// }

// START_TEST(dijkstra_8) {
//   char *string = "10-sin(10)";
//   long double reference = 10 - sin(10);
//   long double result;
//   printf("\033[44m%s\033[0m\n", string);
//   result = dijkstraAlgorithm(string);
//   printf("\033[44mREFERENCE: %Lf\033[0m\n", reference);
//   printf("\033[44mRESULT:    %Lf\033[0m\n", result);
//   ck_assert_double_eq_tol(reference, result, ACCURACY);
// }

// START_TEST(dijkstra_9) {
//   char *string = "1mod3-7*9mod(-10)-1038";
//   long double reference = 1 % 3 - 7 * 9 % -10 - 1038;
//   long double result;
//   result = dijkstraAlgorithm(string);
//   ck_assert_double_eq_tol(reference, result, ACCURACY);
// }

Suite *testDijkstraAlgorithm(void) {
  Suite *suite = suite_create("\033[45m-=S21_DIJKSTRA=-\033[0m");
  TCase *test_case = tcase_create("dijkstra_test_case");

  tcase_add_test(test_case, dijkstra_0);
  tcase_add_test(test_case, dijkstra_1);
  tcase_add_test(test_case, dijkstra_2);
  // tcase_add_test(test_case, dijkstra_3);
  // tcase_add_test(test_case, dijkstra_4);
  // tcase_add_test(test_case, dijkstra_5);
  // tcase_add_test(test_case, dijkstra_6);
  // tcase_add_test(test_case, dijkstra_7);
  // tcase_add_test(test_case, dijkstra_8);
  // tcase_add_test(test_case, dijkstra_9);

  suite_add_tcase(suite, test_case);
  return suite;
}