#ifndef RPN_CALCULATION_H
#define RPN_CALCULATION_H
#include "token_stack.h"

void calculationLogic(Stack *operators, Stack *values, int currentOperator,
                      int currentPriority, int *numberCounter);
long double valuesCalculation(Stack *values, Stack *operators, int *numberCounter);

#endif
