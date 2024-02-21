#include "../headers/rpn_calculation.h"
#include "../headers/dijkstra_algorithm.h"

void calculationLogic(Stack *operators, Stack *values, int currentOperator,
                      int currentPriority) {
  while (operators->stackSize != 0 && !isCurrentHigherOrEqualPriority(operators, currentPriority)) {
    long double calcResult = valuesCalculation(values, operators);
    push(0, 0, calcResult, values);
  }
  push(currentPriority, currentOperator, 0, operators);
}

long double valuesCalculation(Stack *values, Stack *operators) {
  long double result, a, b;
  b = popValue(values);
  a = popValue(values);
  switch (popOperator(operators)) {
    case PLUS:
      result = a + b;
      break;
    case MINUS:
      result = a - b;
      break;
    case MULT:
      result = a * b;
      break;
    case DIV:
      result = a / b;
      break;
    case POW:
      result = pow(a, b);
      break;
  }
  return result;
}