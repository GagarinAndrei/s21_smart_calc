#include "../headers/dijkstra_algorithm.h"

long double dijkstraAlgorithm(char *inputString) {
  long double result;
  Stack operators, values;
  init(&operators);
  init(&values);
  char *ptrInputString = inputString;
  while (*ptrInputString != '\0') {
    if (isdigit(*ptrInputString)) {
      ptrInputString = parceValue(ptrInputString, &values);
    } else {
      ptrInputString = parceOperator(ptrInputString, &operators, &values);
    }
  }
  while (operators.stackSize != 0) {
    long double calcResult = valuesCalculation(&values, &operators);
    push(0, 0, calcResult, &values);
  }
  result = popValue(&values);
  destroy(&operators);
  destroy(&values);
  return result;
}

char *parceOperator(char *ptrInputString, Stack *operators, Stack *values) {
  switch (*ptrInputString) {
  case 'x':
  case '(':
    push(CHUSHPAN, OPEN_PARENTHESIS, 0, operators);
    break;
  case ')':
    while (peak(operators).operation != OPEN_PARENTHESIS &&
           operators->stackSize != 0) {
      push(CHUSHPAN, 0, valuesCalculation(values, operators), values);
    }
    popOperator(operators);
    break;
  case '+':
    calculationLogic(operators, values, PLUS, SKORLUPA);
    break;
  case '-':
    calculationLogic(operators, values, MINUS, SKORLUPA);
    break;
  case '*':
    calculationLogic(operators, values, MULT, SUPERA);
    break;
  case '/':
    calculationLogic(operators, values, DIV, SUPERA);
    break;
  case '^':
    calculationLogic(operators, values, POW, STARSHAK);
    break;
  }
  ptrInputString++;

  return ptrInputString;
}

char *parceValue(char *ptrInputString, Stack *values) {
  long double tmp_number = atof(ptrInputString);
  do {
    ptrInputString++;
  } while (isdigit(*ptrInputString) || *ptrInputString == '.');
  push(0, 0, tmp_number, values);
  return ptrInputString;
}

char *parceFunction(char *ptrInputString, Stack *operators) {
  if (isMod(char *ptrInputString))

    // if (ptrInputString[0] == 'm' && ptrInputString[1] == 'o' &&
    //     ptrInputString[2] == 'd') {
    //   push(SUPERA, MOD, 0, &operators);
    //   ptrInputString += 3;
    // } else if (ptrInputString[0] == 'c' && ptrInputString[1] == 'o' &&
    //            ptrInputString[2] == 's') {
    //   push(SUPERA, COS, 0, &operators);
    //   ptrInputString += 3;
    // } else if (ptrInputString[0] == 's' && ptrInputString[1] == 'i' &&
    //            ptrInputString[2] == 'n') {
    //   push(SUPERA, SIN, 0, &operators);
    //   ptrInputString += 3;
    // } else if (ptrInputString[0] == 't' && ptrInputString[1] == 'a' &&
    //            ptrInputString[2] == 'n') {
    //   push(SUPERA, TAN, 0, &operators);
    //   ptrInputString += 3;
    // } else if (ptrInputString[0] == 'a' && ptrInputString[1] == 'c' &&
    //            ptrInputString[2] == 'o' && ptrInputString[2] == 's') {
    //   push(SUPERA, ACOS, 0, &operators);
    //   ptrInputString += 4;
    // } else if (ptrInputString[0] == 'a' && ptrInputString[1] == 's' &&
    //            ptrInputString[2] == 'i' && ptrInputString[2] == 'n') {
    //   push(SUPERA, ASIN, 0, &operators);
    //   ptrInputString += 4;
    // } else if (ptrInputString[0] == 'a' && ptrInputString[1] == 't' &&
    //            ptrInputString[2] == 'a' && ptrInputString[2] == 'n') {
    //   push(SUPERA, ATAN, 0, &operators);
    //   ptrInputString += 4;
    // } else if (ptrInputString[0] == 's' && ptrInputString[1] == 'q' &&
    //            ptrInputString[2] == 'r' && ptrInputString[2] == 't') {
    //   push(SUPERA, SQRT, 0, &operators);
    //   ptrInputString += 4;
    // } else if (ptrInputString[0] == 'l' && ptrInputString[1] == 'n') {
    //   push(SUPERA, LN, 0, &operators);
    //   ptrInputString += 2;
    // } else if (ptrInputString[0] == 'l' && ptrInputString[1] == 'o' &&
    //            ptrInputString[2] == 'g') {
    //   push(SUPERA, LOG, 0, &operators);
    //   ptrInputString += 3;
    // }
    return ptrInputString;
}

int isCurrentHigherOrEqualPriority(const Stack *operators,
                                   int currentPriority) {
  int result = 0;
  if (operators->stackSize > 0) {
    result = currentPriority >= peak(operators).priority;
  }
  return result;
}
