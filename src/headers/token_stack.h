#ifndef TOKEN_STACK_H
#define TOKEN_STACK_H
#include <math.h>
#include <stdlib.h>

#define OPERATOR 0
#define VALUE 1

typedef enum {
  OPEN_PARENTHESIS,
  CLOSE_PARENTHESIS,
  PLUS,
  MINUS,
  MULT,
  DIV,
  POW,
  MOD,
  COS,
  SIN,
  TAN,
  ACOS,
  ASIN,
  ATAN,
  SQRT,
  LN,
  LOG,
  //==========
  UNAR_MINUS,
  UNAR_PLUS
} operationType;

typedef enum { CHUSHPAN, SKORLUPA, SUPERA, STARSHAK, AVTOR } operationPriority;

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
void push(int priority, int operation, long double value, int isInBrackets,
          Stack *stack);
long double popValue(Stack *stack);
int popOperator(Stack *stack);
Token peak(const Stack *stack);
void destroy(Stack *stack);

void printStack(const Stack *stack, int stackType);
#endif