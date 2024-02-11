#include "token_stack.h"

#include <stdio.h>
#include <stdlib.h>

void init(Stack *stack) {
  stack->stackSize = 0;
  stack->top = NULL;
}

void push(int priority, token_enum type, double value, Stack *stack) {
  Token *newNode = malloc(sizeof(Token));
  newNode->priority = priority;
  newNode->type = type;
  newNode->value = value;
  newNode->next = stack->top;
  stack->stackSize++;
  stack->top = newNode;
}

Token pop(Stack *stack) {
  Token *node = stack->top;
  if (node) free(stack->top);
  stack->top = node->next;
  stack->stackSize--;
  return *node;
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

void printStack(const Stack *stack) {
  Token *ptr = stack->top;
  while (ptr != NULL) {
    printf("%f ", ptr->value);
    ptr = ptr->next;
  }
  printf("-=END_OF_STACK=-\n");
}