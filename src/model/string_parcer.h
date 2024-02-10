#ifndef STRING_PARCER_H
#define STRING_PARCER_H
#include "token_stack.h"
#include <math.h>


void parceString(char *string, token **operators, token **operands);
int isDigit(char c);
double stringToDouble(const char *string);

#endif