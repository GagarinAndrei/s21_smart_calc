#include "../headers/token_stack.h"

void init(Stack *stack) {
  stack->stackSize = 0;
  stack->top = NULL;
}

void push(int priority, char operation, long double value, Stack *stack) {
  Token *newNode = malloc(sizeof(Token));
  newNode->priority = priority;
  newNode->operation = operation;
  newNode->value = value;
  newNode->next = stack->top;
  stack->stackSize++;
  stack->top = newNode;
}

Token pop(Stack *stack) {
  Token *node = stack->top;
  if (node)
    free(stack->top);
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

void printStack(const Stack *stack, int stackType) {
  Token *ptr = stack->top;
  while (ptr != NULL) {
    if (stackType == OPERATOR)
      printf("%c ", ptr->operation);
    else
      printf("%Lf ", ptr->value);
    ptr = ptr->next;
  }
  printf("\n");
}