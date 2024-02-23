#ifndef TESTS_H
#define TESTS_H
#define ACCURACY 1e-07
#include <check.h>
#include <stdio.h>

#include "../headers/dijkstra_algorithm.h"
#include "../headers/token_stack.h"
#include "../headers/rpn_calculation.h"

Suite *testArithmetics(void);
Suite *testFunctions(void);

#endif