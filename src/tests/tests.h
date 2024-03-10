#ifndef TESTS_H
#define TESTS_H
#define ACCURACY 1e-07
#include <check.h>
#include <stdio.h>

#include "../headers/credits.h"
#include "../headers/dijkstra_algorithm.h"
#include "../headers/rpn_calculation.h"
#include "../headers/token_stack.h"

Suite *testArithmetics(void);
Suite *testFunctions(void);
Suite *testCredits(void);

#endif