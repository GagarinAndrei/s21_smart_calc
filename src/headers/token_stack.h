#ifndef TOKEN_STACK_H
#define TOKEN_STACK_H
#include <stdio.h>
#include <stdlib.h>
// #include "smart_calc.h"

typedef enum {
  OPEN_PARENTHESIS,
  CLOSE_PARENTHESIS,
  POW,
  MULT,
  DIV = 3,
  MINUS,
  PLUS = 4,
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
 * @param token_enum type
 * @param double value
 * @param Stack *stack
 */
void push(int priority, char operation, Stack *stack);
Token pop(Stack *stack);
Token peak(const Stack *stack);
void printStack(const Stack *stack);
void destroy(Stack *stack);

#endif