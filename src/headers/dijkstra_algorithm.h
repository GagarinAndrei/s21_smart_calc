#ifndef STRING_PARCER_H
#define STRING_PARCER_H
#include <ctype.h>
#include <math.h>
#include <string.h>

// #include "token_stack.h"
// #include "rpn_calculation.h"

void dijkstraAlgorithm(char *string, Stack *operators, Stack *values);
char *parceOperator(char *ptrInputString, Stack *operators, Stack *values);
char *parceValue(char *ptrInputString, Stack *values);
// void calculationLogic(Stack *operators, Stack *values, char currentChar,
//                       int currentPriority);
// long double valuesCalculation(Stack *values, Stack *operators);
int isCurrentHigherOrEqualPriority(const Stack *operators, int priority);

#endif