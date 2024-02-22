#ifndef TOKEN_STACK_H
#define TOKEN_STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include "dijkstra_algorithm.h"

#define OPERATOR 0
#define VALUE 1

typedef enum {
  OPEN_PARENTHESIS = 0,
  CLOSE_PARENTHESIS = 1,
  PLUS = 2,
  MINUS = 3,
  MULT = 4,
  DIV = 5,
  POW = 6,
  MOD = 7,
  COS = 8,
  SIN = 9,
  TAN = 10,
  ACOS = 11,
  ASIN = 12,
  ATAN = 13,
  SQRT = 14,
  LN = 15,
  LOG = 16,
  //==========
  UNAR_MINUS = 17,
  UNAR_PLUS = 18
} operationType;

typedef enum {
  CHUSHPAN,
  SKORLUPA,
  SUPERA,
  STARSHAK,
  AVTOR
} operationPriority;

typedef struct Node {
  int priority;
  int operation;
  long double value;
  int isValueInBrackets;
  struct Node *next;
} Token;

typedef struct {
  int stackSize;
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
void push(int priority, int operation, long double value, int isInBrackets, Stack *stack);
long double popValue(Stack *stack);
char popOperator(Stack *stack);
Token peak(const Stack *stack);
void destroy(Stack *stack);

void printStack(const Stack *stack, int stackType);
#endif