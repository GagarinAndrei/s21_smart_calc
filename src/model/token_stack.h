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
  UNARM_LEXEME = 9,
  UNARP_LEXEME = 10,
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
} token;

void push(int priority, token_enum type, double value, token **stackList);
token pop(token **stackList);
token peak(token **stackList);
int type(token **top);

#endif