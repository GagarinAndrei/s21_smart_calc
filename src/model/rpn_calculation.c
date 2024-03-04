#include "../headers/rpn_calculation.h"

#include <math.h>

#include "../headers/dijkstra_algorithm.h"

void calculationLogic(Stack *operators, Stack *values, int currentOperator,
                      int currentPriority, int *numberCounter) {
  int isValueInBrackets = peak(values).isValueInBrackets;
  while (operators->stackSize != 0 &&
         !isCurrentHigherPriority(operators, currentPriority)) {
    long double calcResult =
        valuesCalculation(values, operators, numberCounter);
    push(0, 0, calcResult, isValueInBrackets, values);
  }
  isValueInBrackets = *numberCounter > 0;
  push(currentPriority, currentOperator, 0, isValueInBrackets, operators);
}

long double valuesCalculation(Stack *values, Stack *operators,
                              int *numberCounter) {
  long double result = NAN;
  int isInBrackets = peak(values).isValueInBrackets;
  int operation = popOperator(operators);
  int valuesNumber = (operation < COS)
                         ? operationWithTwoValues(values, operation, &result)
                         : operationWithOneValue(values, operation, &result);
  if (isInBrackets) *numberCounter -= valuesNumber;
  return result;
}

int operationWithTwoValues(Stack *values, int operation, long double *result) {
  long double a = 0, b = 0;
  b = popValue(values);
  a = popValue(values);

  switch (operation) {
    case PLUS:
      *result = a + b;
      break;
    case MINUS:
      *result = a - b;
      break;
    case MULT:
      *result = a * b;
      break;
    case DIV:
      *result = a / b;
      break;
    case POW:
      *result = pow(a, b);
      break;
    case MOD:
      *result = fmod(a, b);
  }
  return 1;
}

int operationWithOneValue(Stack *values, int operation, long double *result) {
  long double a = popValue(values);

  switch (operation) {
    case SIN:
      *result = sin(a);
      break;
    case COS:
      *result = cos(a);
      break;
    case TAN:
      *result = tan(a);
      break;
    case ASIN:
      *result = asin(a);
      break;
    case ACOS:
      *result = acos(a);
      break;
    case ATAN:
      *result = atan(a);
      break;
    case SQRT:
      *result = sqrt(a);
      break;
    case LN:
      *result = log(a);
      break;
    case LOG:
      *result = log10(a);
      break;
    case UNAR_MINUS:
      *result = -a;
      break;
  }
  return 0;
}
