#include "headers/token_stack.h"

#include <stdio.h>

void init(Stack *stack) {
  stack->stackSize = 0;
  stack->top = NULL;
}

void push(int priority, int operation, long double value, int isValueInBrackets,
          Stack *stack) {
  Token *newNode = (Token *)malloc(sizeof(Token));
  if (newNode) {
    newNode->priority = priority;
    newNode->operation = operation;
    newNode->value = value;
    newNode->isValueInBrackets = isValueInBrackets;
    newNode->next = stack->top;
    stack->stackSize++;
    stack->top = newNode;
  }
}

long double popValue(Stack *stack) {
  long double value;
  Token *nextNode = NULL;
  if (stack->top == NULL) {
    return NAN;
  }
  nextNode = stack->top->next;
  value = stack->top->value;
  free(stack->top);
  stack->top = nextNode;
  stack->stackSize--;
  return value;
}

int popOperator(Stack *stack) {
  char operation;
  Token *nextNode = NULL;
  if (stack->top == NULL) {
    return -1;
  }
  nextNode = stack->top->next;
  operation = stack->top->operation;
  free(stack->top);
  stack->top = nextNode;
  stack->stackSize--;
  return operation;
}

Token peak(const Stack *stack) { return *stack->top; }

void destroy(Stack *stack) {
  Token *ptr_top = stack->top;
  while (ptr_top != NULL) {
    Token *tmp = ptr_top;
    ptr_top = ptr_top->next;
    free(tmp);
  }
  stack->stackSize = 0;
  stack->top = NULL;
}

// void printStack(const Stack *stack, int stackType) {
//   Token *ptr = stack->top;
//   while (ptr != NULL) {
//     if (stackType == OPERATOR)
//       printf("%d ", ptr->operation);
//     else
//       printf("%Lf ", ptr->value);
//     ptr = ptr->next;
//   }
//   printf("\n");
// }