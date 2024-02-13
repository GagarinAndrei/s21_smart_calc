#include "utils.h"

#include "model/token_stack.h"

void printStack(const Stack *stack) {
  Token *ptr = stack->top;
  while (ptr != NULL) {
    if (ptr->type == DIGIT) {
      printf("%f ", ptr->value);
    } else {
      printf("%c ", selectOperator(ptr));
    }
    ptr = ptr->next;
  }
  printf("\n========================\n");
}

char selectOperator(Token *node) {
    char operator;
  switch (node->type) {
    case X:
      operator= 'x';
      break;
    case MINUS:
      operator= '-';
      break;
    case PLUS:
      operator= '+';
      break;
    case DIV:
      operator= '/';
      break;
    case MULT:
      operator= '*';
      break;
    case POW:
      operator= '^';
      break;
    case LEFT_PARENTHESIS:
      operator= '(';
      break;
    case RIGHT_PARENTHESIS:
      operator= ')';
      break;
    case DIGIT:
    case MOD:
    case UNAR_MINUS:
    case UNAR_PLUS:
    case COS:
    case SIN:
    case TAN:
    case ACOS:
    case ASIN:
    case ATAN:
    case SQRT:
    case LN:
    case LOG:
      break;
  }
  return operator;
}