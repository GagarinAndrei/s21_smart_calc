#include "stack.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(struct StackNode **top, double value) {
  struct StackNode *node = NULL;
  node = (struct StackNode *)malloc(sizeof(struct StackNode));
  if (!node) {
    sprintf(strerror(errno));
    exit(-1);
  }
}

int peek(struct StackNode *top);
int pop(struct StackNode **top);

int isEmpty(struct StackNode *top) { return top == NULL; }

int stackSize(struct StackNode *node) { return node->nodeCount; }