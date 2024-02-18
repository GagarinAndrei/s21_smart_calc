#ifndef STRING_PARCER_H
#define STRING_PARCER_H
#include "token_stack.h"
// #include "smart_calc.h"
#include <ctype.h>
#include <math.h>
// #include <stdio.h>
#include <string.h>

void parceString(char *string, Stack *operators, Stack *values);
int isHigherPriority(const Stack *operators, int priority);
long double valuesCalculation(Stack *values, Stack *operators);
// double stringToDouble(const char *string);

#endif