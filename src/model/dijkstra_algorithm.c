#include "../headers/dijkstra_algorithm.h"

#include <stdbool.h>
#include <stdio.h>

long double dijkstraAlgorithm(char *inputString) {
  long double result;
  int numberCounter = 0;
  int isValueInBrackets = FALSE;
  int isPrevOperator = FALSE;
  Stack operators, values;
  init(&operators);
  init(&values);
  char *ptrInputString = inputString;
  while (*ptrInputString != '\0') {
    // printf("==========================================\n");
    // printf("%s\n", ptrInputString);
    if (isdigit(*ptrInputString)) {
      ptrInputString = parceValue(ptrInputString, &values, &isValueInBrackets,
                                  &numberCounter);
      isPrevOperator = FALSE;
      // printf("==========================================\n");
      // printStack(&operators, OPERATOR);
      // printStack(&values, VALUE);
    } else {
      ptrInputString =
          parceOperator(ptrInputString, &operators, &values, &isValueInBrackets,
                        &numberCounter, &isPrevOperator);
      // printf("==========================================\n");
      // printf("%s\n", ptrInputString);
      // printf("==========================================\n");
      // printStack(&operators, OPERATOR);
      // printStack(&values, VALUE);
      ptrInputString = parceFunction(ptrInputString, &operators);
      // printf("==========================================\n");
      // printf("%s\n", ptrInputString);
      // printf("==========================================\n");
      // printStack(&operators, OPERATOR);
      // printStack(&values, VALUE);
      isPrevOperator = TRUE;
    }
  }
  while (operators.stackSize != 0) {
    long double calcResult =
        valuesCalculation(&values, &operators, &numberCounter);
    push(0, 0, calcResult, isValueInBrackets, &values);
    // calculationLogic(&operators, &values, peak(&operators).operation,
    //                  peak(&operators).priority, &numberCounter);
    // printf("==========================================\n");
    // printStack(&operators, OPERATOR);
    // printStack(&values, VALUE);
  }
  result = popValue(&values);
  destroy(&operators);
  destroy(&values);
  return result;
}

char *parceOperator(char *ptrInputString, Stack *operators, Stack *values,
                    int *isValueInBrackets, int *numberCounter,
                    int *isPrevOperator) {
  int currentPriority = SKORLUPA;
  switch (*ptrInputString) {
  case 'x':
  case '(':
    *isValueInBrackets = true;
    push(CHUSHPAN, OPEN_PARENTHESIS, 0, *isValueInBrackets, operators);
    ptrInputString++;
    break;
  case ')':
    while (peak(operators).operation != OPEN_PARENTHESIS &&
           operators->stackSize != 0) {
      push(CHUSHPAN, 0, valuesCalculation(values, operators, numberCounter),
           *isValueInBrackets, values);
      // printf("==========================================\n");
      // printStack(operators, OPERATOR);
      // printStack(values, VALUE);
    }
    popOperator(operators);
    if (*numberCounter == 0)
      *isValueInBrackets = FALSE;
    ptrInputString++;
    break;
  case '+':
    calculationLogic(operators, values, PLUS, SKORLUPA, numberCounter);
    ptrInputString++;
    break;
  case '-':
    if ((operators->stackSize == 0 && values->stackSize == 0) ||
        *isPrevOperator) {
      currentPriority = AVTOR;
      push(CHUSHPAN, 0, 0, *isValueInBrackets, values);
      // push(SKORLUPA, MINUS, 0, FALSE, operators);
    }
    calculationLogic(operators, values, MINUS, currentPriority, numberCounter);
    ptrInputString++;
    break;
  case '*':
    calculationLogic(operators, values, MULT, SUPERA, numberCounter);
    ptrInputString++;
    break;
  case '/':
    calculationLogic(operators, values, DIV, SUPERA, numberCounter);
    ptrInputString++;
    break;
  case '^':
    calculationLogic(operators, values, POW, STARSHAK, numberCounter);
    ptrInputString++;
    break;
  case ' ':
    ptrInputString++;
    break;
  }

  return ptrInputString;
}

char *parceValue(char *ptrInputString, Stack *values, int *isValueInBrackets,
                 int *numberCounter) {
  long double tmp_number = atof(ptrInputString);
  do {
    ptrInputString++;
  } while (isdigit(*ptrInputString) || *ptrInputString == '.');
  push(0, 0, tmp_number, *isValueInBrackets, values);
  if (peak(values).isValueInBrackets)
    *numberCounter += 1;
  return ptrInputString;
}

char *parceFunction(char *ptrInputString, Stack *operators) {
  int functionType = -1;
  int functionSize = functionTypeDeterminant(ptrInputString, &functionType);
  if (functionType >= 0) {
    push(SUPERA, functionType, 0, FALSE, operators);
  }
  ptrInputString += functionSize;

  return ptrInputString;
}

int isCurrentHigherPriority(const Stack *operators, int currentPriority) {
  int result = 0;
  if (operators->stackSize > 0) {
    result = (peak(operators).operation == POW)
                 ? currentPriority >= peak(operators).priority
                 : currentPriority > peak(operators).priority;
  }
  return result;
}
