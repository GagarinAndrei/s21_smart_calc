#ifndef RPN_CALCULATION_H
#define RPN_CALCULATION_H

// #include "token_stack.h"
// #include "dijkstra_algorithm.h"

void calculationLogic(Stack *operators, Stack *values, char currentChar,
                      int currentPriority);
long double valuesCalculation(Stack *values, Stack *operators);

#endif
