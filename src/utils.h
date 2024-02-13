#ifndef UTILS_H
#define UTILS_H
#include "model/token_stack.h"
#include <stdio.h>



double stringToDouble(const char *string);
void printStack(const Stack *stack);
char selectOperator(Token *token);

#endif