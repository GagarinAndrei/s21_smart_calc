#include "../headers/string_parcer.h"

void parceString(char *inputString, Stack *operators, Stack *values) {
  double tmp_number;
  char *ptrInputString = inputString;
  while (*ptrInputString != '\0') {
    if (isdigit(*ptrInputString)) {
      tmp_number = atof(ptrInputString);
      do {
        ptrInputString++;
      } while (isdigit(*ptrInputString) || *ptrInputString == '.');
      push(0, 0, tmp_number, values);
    } else {
      switch (*ptrInputString) {
        case 'x':
        case '(':
          push(OPEN_PARENTHESIS, *ptrInputString, 0, operators);
          ptrInputString++;
          break;
        case ')':
          while (peak(operators).operation != '(' &&
                 operators->stackSize != 0) {
            push(0, 0, valuesCalculation(values, operators), values);
          }
          popOperator(operators);
          ptrInputString++;
          break;
        case '+':
        case '-':
          calculationLogic(operators, values, *ptrInputString, PLUS_MINUS);
          ptrInputString++;
          break;
        case '*':
        case '/':
          calculationLogic(operators, values, *ptrInputString, MULT_DIV);
          ptrInputString++;
          break;
        case '^':
          calculationLogic(operators, values, *ptrInputString, POW);
          ptrInputString++;
          break;
        default:
          ptrInputString++;
      }
    }
  }
  while (operators->stackSize != 0) {
    long double calcResult = valuesCalculation(values, operators);
    push(0, 0, calcResult, values);
  }
}

int isCurrentHigherOrEqualPriority(const Stack *operators,
                                   int currentPriority) {
  int result = 0;
  if (operators->stackSize > 0) {
    int inStackOperatorPriority = peak(operators).priority;
    result = inStackOperatorPriority <= currentPriority;
  }
  return result;
}

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
