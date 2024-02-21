#ifndef STRING_PARCER_H
#define STRING_PARCER_H
#include <ctype.h>
#include <math.h>
#include <string.h>

#include "token_stack.h"
#include "rpn_calculation.h"
#include <stdlib.h>


long double dijkstraAlgorithm(char *string);
char *parceOperator(char *ptrInputString, Stack *operators, Stack *values);
char *parceValue(char *ptrInputString, Stack *values);
char *parceFunction(char *ptrInputString, Stack *operators);
int isCurrentHigherOrEqualPriority(const Stack *operators, int priority);

#endif