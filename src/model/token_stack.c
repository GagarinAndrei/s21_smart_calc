#include "token_stack.h"
#include <stdlib.h>

void push(int priority, token_enum type, double value, token **top) {
  token *newNode = malloc(sizeof(token));
  newNode->priority = priority;
  newNode->type = type;
  newNode->value = value;
  newNode->next = *top;
  *top = newNode;
}

token pop(token **top) {
  token *node = *top;
  if (node)
    free(*top);
  *top = node->next;
  return *node;
}

token peak(token **stackList) {
  token *topNode = *stackList;
  return *topNode;
}

int type(token **top) { return (*top)->type; }