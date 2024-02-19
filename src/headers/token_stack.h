#ifndef TOKEN_STACK_H
#define TOKEN_STACK_H
#include <stdio.h>
#include <stdlib.h>

#define OPERATOR 0
#define VALUE 1
// #include "smart_calc.h"

typedef enum {
  OPEN_PARENTHESIS,
  CLOSE_PARENTHESIS = 0,
  PLUS_MINUS,
  MULT_DIV,
  POW,
  //==========
  MOD,
  UNAR_MINUS,
  UNAR_PLUS,
  COS,
  SIN,
  TAN,
  ACOS,
  ASIN,
  ATAN,
  SQRT,
  LN,
  LOG,
} operationPriority;

typedef struct Node {
  int priority;
  // token_enum type;
  char operation;
  long double value;
  struct Node *next;
} Token;

typedef struct {
  size_t stackSize;
  Token *top;
} Stack;

/**
 * @brief Инициализация стэка
 * @param Stack *stackList - казатель на стэк
 */
void init(Stack *stackList);

/**
 * @brief Помещаем новый узел в стэк
 * @param int priority
 * @param char operation
 * @param long double value
 * @param Stack *stack
 */
void push(int priority, char operation, long double value, Stack *stack);
long double popValue(Stack *stack);
char popOperator(Stack *stack);
Token peak(const Stack *stack);
void destroy(Stack *stack);

void printStack(const Stack *stack, int stackType);
#endif