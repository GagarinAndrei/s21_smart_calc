#ifndef STRING_PARCER_H
#define STRING_PARCER_H
#define MAX_SIZE 255
#define TRUE 1
#define FALSE 0
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "function_type_determinant.h"
#include "rpn_calculation.h"
#include "token_stack.h"

long double dijkstraAlgorithm(char *string, double x);
char *parceOperator(char *ptrInputString, Stack *operators, Stack *values,
                    int *isValueInBrackets, int *numberOfBrackets,
                    int *isPrevOperator);
char *parceValue(char *ptrInputString, Stack *values, int *isValueInBrackets,
                 int *numberCounter);
char *parceFunction(char *ptrInputString, Stack *operators);
int isCurrentHigherPriority(const Stack *operators, int priority);

#endif