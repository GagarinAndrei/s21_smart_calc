#include "../headers/rpn_calculation.h"

void calculationLogic(Stack *operators, Stack *values, char currentChar,
                      int currentPriority) {
  while (operators->stackSize != 0 &&
         !isCurrentHigherOrEqualPriority(operators, currentPriority)) {
    long double calcResult = valuesCalculation(values, operators);
    push(0, 0, calcResult, values);
  }
  push(currentPriority, currentChar, 0, operators);
}

long double valuesCalculation(Stack *values, Stack *operators) {
  long double result, a, b;
  a = popValue(values);
  b = popValue(values);
  switch (popOperator(operators)) {
    case '+':
      result = a + b;
      break;
    case '-':
      result = b - a;
      break;
    case '*':
      result = a * b;
      break;
    case '/':
      result = b / a;
      break;
    case '^':
      result = pow(b, a);
      break;
  }
  return result;
}