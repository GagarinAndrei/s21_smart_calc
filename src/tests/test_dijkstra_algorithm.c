#include <check.h>

#include "tests.h"

START_TEST(dijkstra_0) {
  char *string = "(1+2-3)*4";
  long double reference = (1 + 2 - 3) * 4;
  Stack operators, values;
  init(&operators);
  init(&values);
  dijkstraAlgorithm(string, &operators, &values);
  ck_assert_double_eq_tol(reference, peak(&values).value, ACCURACY);
  destroy(&operators);
  destroy(&values);
}

START_TEST(dijkstra_1) {
  char *string = "(1+2)*3^2^2-6/(7+8/9)";
  long double reference = (1 + 2) * pow(3, pow(2, 2)) - 6.0 / (7 + 8.0 / 9);
  Stack operators, values;
  init(&operators);
  init(&values);
  dijkstraAlgorithm(string, &operators, &values);
  ck_assert_double_eq_tol(reference, peak(&values).value, ACCURACY);
  destroy(&operators);
  destroy(&values);
}

START_TEST(dijkstra_2) {
  char *string = "5/2 - (1 + 3.5) * 3^4";
  long double reference = 5.0 / 2 - (1 + 3.5) * pow(3, 4);
  Stack operators, values;
  init(&operators);
  init(&values);
  dijkstraAlgorithm(string, &operators, &values);
  ck_assert_double_eq_tol(reference, peak(&values).value, ACCURACY);
  destroy(&operators);
  destroy(&values);
}

START_TEST(dijkstra_3) {
  char *string = "2*(3+5/2)";
  long double reference = 2 * (3 + 5.0 / 2);
  Stack operators, values;
  init(&operators);
  init(&values);
  dijkstraAlgorithm(string, &operators, &values);
  ck_assert_double_eq_tol(reference, peak(&values).value, ACCURACY);
  destroy(&operators);
  destroy(&values);
}

START_TEST(dijkstra_4) {
  char *string = "4^3^2-1";
  long double reference = pow(4, pow(3, 2)) - 1;
  Stack operators, values;
  init(&operators);
  init(&values);
  dijkstraAlgorithm(string, &operators, &values);
  ck_assert_double_eq_tol(reference, peak(&values).value, ACCURACY);
  destroy(&operators);
  destroy(&values);
}

START_TEST(dijkstra_5) {
  char *string = "2*(3+5/2-4)";
  long double reference = 2 * (3 + 5.0 / 2 - 4);
  Stack operators, values;
  init(&operators);
  init(&values);
  // printf("\033[44mINPUT_STRING: %s\033[0m\n", string);
  // printf("\033[44mREFERENCE: %Lf\033[0m\n", reference);
  dijkstraAlgorithm(string, &operators, &values);
  ck_assert_double_eq_tol(reference, peak(&values).value, ACCURACY);
  destroy(&operators);
  destroy(&values);
}

Suite *testDijkstraAlgorithm(void) {
  Suite *suite = suite_create("\033[45m-=S21_DIJKSTRA=-\033[0m");
  TCase *test_case = tcase_create("dijkstra_test_case");

  tcase_add_test(test_case, dijkstra_0);
  tcase_add_test(test_case, dijkstra_1);
  tcase_add_test(test_case, dijkstra_2);
  tcase_add_test(test_case, dijkstra_3);
  tcase_add_test(test_case, dijkstra_4);
  tcase_add_test(test_case, dijkstra_5);

  suite_add_tcase(suite, test_case);
  return suite;
}