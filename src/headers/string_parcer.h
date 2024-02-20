#ifndef STRING_PARCER_H
#define STRING_PARCER_H
#include <ctype.h>
#include <math.h>
#include <string.h>

#include "token_stack.h"

void parceString(char *string, Stack *operators, Stack *values);
int isCurrentHigherOrEqualPriority(const Stack *operators, int priority);
long double valuesCalculation(Stack *values, Stack *operators);
void calculationLogic(Stack *operators, Stack *values, char currentChar,
                      int currentPriority);

#endif