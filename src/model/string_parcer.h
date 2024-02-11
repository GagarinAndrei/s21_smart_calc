#ifndef STRING_PARCER_H
#define STRING_PARCER_H
#include "token_stack.h"
#include <math.h>

void parceString(char *string, Stack *operators, Stack *output);
double stringToDouble(const char *string);

#endif