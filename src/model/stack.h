#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct operatorsStack {
  int stackSize;
  char **tokens;
} operatorsStack;

typedef struct valuesStack {
  int stackSize;
  double *values;
} valuesStack;

/**
 *  @brief Stack initialization
 *  @return return pointer of created stack or NULL;
 */
operatorsStack *initOperatorsStack();

/**
 *  @brief Check if stack is empty
 *  @param pointer to stack
 *  @return bool
 *          0 - stack is not empty
 *          1 - stack is empty
 */
bool isOperatorsStackEmpty(operatorsStack *stack);

/**
 *  @brief Check if stack is full
 *  @param pointer to stack
 *  @return bool
 *          0 - stack is not full
 *          1 - stack is full
 */
bool isOperatorsStackFull(operatorsStack *stack);

/**
 *  @brief Push token to the stack
 *  @param stack pointer to stack
 *  @param token char*
 *  @return bool
 *          0 - operation is fail
 *          1 - operation is success
 */
bool pushOperator(operatorsStack *stack, char *token);

/**
 *  @brief Display top element of stack
 *  @param pointer to stack
 *  @return char* of top token in stack
 *          NULL - if stack is empty
 */
char *peekOperator(operatorsStack *stack);

/**
 *  @brief Extracts top element of stack
 *  @param pointer to stack
 *  @return char* of top token in stack
 *          NULL - if stack is empty
 */
char *popOperator(operatorsStack *stack);

/**
 *  @brief Erase stack
 *  @param pointer to stack
 *  @return bool
 *          0 - operation is fail
 *          1 - operation is success
 */
bool destroyOperator(operatorsStack *stack);

/**
 *  @brief Stack initialization
 *  @return return pointer of created stack or NULL;
 */
valuesStack *initValuesStack();

/**
 *  @brief Check if stack is empty
 *  @param pointer to stack
 *  @return bool
 *          0 - stack is not empty
 *          1 - stack is empty
 */
bool isValuesStackEmpty(valuesStack *stack);

/**
 *  @brief Check if stack is full
 *  @param pointer to stack
 *  @return bool
 *          0 - stack is not full
 *          1 - stack is full
 */
bool isValuesStackFull(valuesStack *stack);

/**
 *  @brief Push value to the stack
 *  @param stack pointer to stack
 *  @param value double
 *  @return bool
 *          0 - operation is fail
 *          1 - operation is success
 */
bool pushValues(valuesStack *stack, double value);

/**
 *  @brief Display top element of stack
 *  @param pointer to stack
 *  @return double of top value in stack
 *          NULL - if stack is empty
 */
double peekValues(valuesStack *stack);

/**
 *  @brief Extracts top element of stack
 *  @param pointer to stack
 *  @return double of top value in stack
 *          NULL - if stack is empty
 */
double popValues(valuesStack *stack);

/**
 *  @brief Erase stack
 *  @param pointer to stack
 *  @return bool
 *          0 - operation is fail
 *          1 - operation is success
 */
bool destroyValues(valuesStack *stack);

#endif