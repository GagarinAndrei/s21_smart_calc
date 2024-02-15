#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct operatorsStack {
  int stackSize;
  char **tokens;
} operatorsStack;

typedef struct valuesStack {
  int stackSize;
  double *values;
} valuesStack;

operatorsStack *initOperatorsStack();
bool isOperatorsStackEmpty(operatorsStack *stack);
bool isOperatorsStackFull(operatorsStack *stack);
bool pushOperator(operatorsStack *stack, char *token);
char *peekOperator(operatorsStack *stack);
char *popOperator(operatorsStack *stack);
bool destroyOperator(operatorsStack *stack);

valuesStack *initValuesStack();
bool isValuesStackEmpty(valuesStack *stack);
bool isValuesStackFull(valuesStack *stack);
bool pushValues(valuesStack *stack, double value);
double peekValues(valuesStack *stack);
double popValues(valuesStack *stack);
bool destroyValues(valuesStack *stack);

#endif