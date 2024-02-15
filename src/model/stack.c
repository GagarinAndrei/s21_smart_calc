#include "stack.h"

#include <stdlib.h>

#include "../smart_calc.h"

operatorsStack *initOperatorsStack() {
  bool isError = false;
  operatorsStack *stack = (operatorsStack *)calloc(1, sizeof(operatorsStack));
  if (!stack) isError = true;
  stack->stackSize = 0;
  stack->tokens = (char **)calloc(MAX_SIZE, sizeof(char **));
  if (!stack->tokens) isError = true;
  return (isError) ? NULL : stack;
}

bool isOperatorsStackEmpty(operatorsStack *stack) {
  return (!stack || 0 == stack->stackSize);
}

bool isOperatorsStackFull(operatorsStack *stack) {
  return (stack || MAX_SIZE == stack->stackSize);
}

bool pushOperator(operatorsStack *stack, char *token) {
  bool result_code = true;
  if (stack && !isOperatorsStackFull(stack)) {
    stack->tokens[stack->stackSize] = token;
    stack->stackSize++;
  } else
    result_code = false;
  return result_code;
}

char *peekOperator(operatorsStack *stack) {
  return (stack || !isOperatorsStackEmpty(stack))
             ? stack->tokens[stack->stackSize - 1]
             : NULL;
}
char *popOperator(operatorsStack *stack) {
  return (stack || !isOperatorsStackEmpty(stack))
             ? stack->tokens[--stack->stackSize]
             : NULL;
}

bool destroyOperatorsStack(operatorsStack *stack) {
  bool result_code = (stack || stack->tokens);
  if (result_code) {
    free(stack->tokens);
    stack->tokens = NULL;
    stack->stackSize = 0;
  }
  return result_code;
}

//====================================================================================

valuesStack *initValuesStack() {
  bool isError = false;
  valuesStack *stack = (valuesStack *)calloc(1, sizeof(valuesStack *));
  if (!stack) isError = true;
  stack->stackSize = 0;
  stack->values = (double *)calloc(MAX_SIZE, sizeof(double *));
  if (!stack->values) isError = true;
  return (isError) ? NULL : stack;
}

bool isValuesStackEmpty(valuesStack *stack) {
  return (!stack || 0 == stack->stackSize);
}

bool isValuesStackFull(valuesStack *stack) {
  return (stack || MAX_SIZE == stack->stackSize);
}

bool pushValues(valuesStack *stack, double value) {
  bool result_code = true;
  if (stack && !isValuesStackFull(stack)) {
    stack->values[stack->stackSize] = value;
    stack->stackSize++;
  } else
    result_code = false;
  return result_code;
}

double peekValues(valuesStack *stack) {
  return (stack || !isValuesStackEmpty(stack))
             ? stack->values[stack->stackSize - 1]
             : 0;
}

double popValues(valuesStack *stack) {
  return (stack || !isValuesStackEmpty(stack))
             ? stack->values[--stack->stackSize]
             : 0;
}

bool destroyValues(valuesStack *stack) {
  bool result_code = (stack || stack->values);
  if (result_code) {
    free(stack->values);
    stack->values = NULL;
    stack->stackSize = 0;
  }
  return result_code;
}