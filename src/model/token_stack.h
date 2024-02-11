#ifndef TOKEN_STACK_H
#define TOKEN_STACK_H
#include <stdlib.h>

typedef enum {
  DIGIT = 1,
  X = 2,
  MINUS = 3,
  PLUS = 4,
  DIV = 5,
  MULT = 6,
  POW = 7,
  MOD = 8,
  UNAR_MINUS = 9,
  UNAR_PLUS = 10,
  COS = 11,
  SIN = 12,
  TAN = 13,
  ACOS = 14,
  ASIN = 15,
  ATAN = 16,
  SQRT = 17,
  LN = 18,
  LOG = 19,
  LEFT_PARENTHESIS = 20,
  RIGHT_PARENTHESIS = 21
} token_enum;

typedef struct Node {
  int priority;
  token_enum type;
  double value;
  struct Node *next;
} Token;

typedef struct {
  size_t stackSize;
  Token *top;
} Stack;


/** Инициализация стэка
* @param Stack *stackList - казатель на стэк 
*/
void init(Stack *stackList);

/** Помещаем новый узел в стэк
* @param int priority
* @param token_enum type
* @param double value
* @param Stack *stack 
*/
void push(int priority, token_enum type, double value, Stack *stack);


Token pop(Stack *stack);
Token peak(const Stack *stack);
void printStack(const Stack *stack);
void destroy(Stack *stack);

#endif