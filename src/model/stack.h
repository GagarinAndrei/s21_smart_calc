#ifndef STACK_H
#define STACK_H

#define STACK_CAPACITY 255

#include <stdio.h>

struct StackNode{
  int nodeCount = 0;
  double data;
  struct StackNode *next;
};

/**
* Добавление узла в стек
* @param top указатель на верхний узел
* @param value значение
*/
void push(struct StackNode **top, double value);


int peek(struct StackNode *top);
int pop(struct StackNode **top);


/**
* Проверяет пуст ли стек
* @param top указатель на верхний узел
* @return 1 - пуст
*         0 - не пуст
*/
int isEmpty(struct StackNode *top);

/**
* Возвращает размер стека
* @param top указатель на верхний узел
* @return количество узлов в стеке
*/
int stackSize(struct StackNode *top);

#endif