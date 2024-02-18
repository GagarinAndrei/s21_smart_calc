#ifndef STRING_PARCER_H
#define STRING_PARCER_H
#include "token_stack.h"
#include <ctype.h>
#include <string.h>
#include <math.h>


void parceString(char *string, Stack *operators, Stack *values);
int isHigherPriority(const Stack *operators, int priority);
long double valuesCalculation(Stack *values, Stack *operators);

#endif