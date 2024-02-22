#include "../headers/rpn_calculation.h"
#include "../headers/dijkstra_algorithm.h"
#include <math.h>

void calculationLogic(Stack *operators, Stack *values, int currentOperator,
                      int currentPriority, int *numberCounter) {
  int isValueInBrackets = peak(values).isValueInBrackets;
  while (operators->stackSize != 0 &&
         !isCurrentHigherOrEqualPriority(operators, currentPriority)) {
    long double calcResult =
        valuesCalculation(values, operators, numberCounter);
    push(0, 0, calcResult, isValueInBrackets, values);
  }
  isValueInBrackets = *numberCounter > 0;
  push(currentPriority, currentOperator, 0, isValueInBrackets, operators);
}

long double valuesCalculation(Stack *values, Stack *operators,
                              int *numberCounter) {
  long double result, a, b;
  int isInBrackets = peak(values).isValueInBrackets;
  int valuesNumber;
  b = popValue(values);
  if (peak(values).isValueInBrackets && *numberCounter >= 1)
    a = popValue(values);
  switch (popOperator(operators)) {
  case PLUS:
    result = a + b;
    valuesNumber = 1;
    break;
  case MINUS:
    result = a - b;
    valuesNumber = 1;
    break;
  case MULT:
    result = a * b;
    valuesNumber = 1;
    break;
  case DIV:
    result = a / b;
    valuesNumber = 1;
    break;
  case POW:
    result = pow(a, b);
    valuesNumber = 1;
    break;
  case SIN:
    result = sin(b);
    valuesNumber = 0;
  }

  if (isInBrackets)
    *numberCounter -= valuesNumber;
  return result;
}