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
  long double result, a = 0, b = 0;
  int isInBrackets = peak(values).isValueInBrackets;
  int valuesNumber;
  // b = popValue(values);
  // if (values->stackSize > 0) {
  //   if ((peak(values).isValueInBrackets && *numberCounter > 1) ||
  //       !peak(values).isValueInBrackets) {
  //     a = popValue(values);
  //   }
  // }

  switch (popOperator(operators)) {
  case PLUS:
    b = popValue(values);
    a = popValue(values);
    result = a + b;
    valuesNumber = 1;
    break;
  case MINUS:
    b = popValue(values);
    a = popValue(values);
    result = a - b;
    valuesNumber = 1;
    break;
  case MULT:
    b = popValue(values);
    a = popValue(values);
    result = a * b;
    valuesNumber = 1;
    break;
  case DIV:
    b = popValue(values);
    a = popValue(values);
    result = a / b;
    valuesNumber = 1;
    break;
  case POW:
    b = popValue(values);
    a = popValue(values);
    result = pow(a, b);
    valuesNumber = 1;
    break;
  case SIN:
    b = popValue(values);
    // a = popValue(values);
    result = sin(b);
    valuesNumber = 0;
  }

  if (isInBrackets)
    *numberCounter -= valuesNumber;
  return result;
}