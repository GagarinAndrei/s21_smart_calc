#include "string_parcer.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "token_stack.h"

void parceString(char *string, Stack *operators, Stack *output) {
  double tmp_number;
  char *ptr_string = string;
  while (*ptr_string != '\0') {
    if (isdigit(*ptr_string)) {
      tmp_number = atof(ptr_string);
      do {
        ptr_string++;
      } while (isdigit(*ptr_string) || *ptr_string == '.');
      push(1, DIGIT, tmp_number, output);
    }

    switch (*ptr_string) {
      case 'x':
      case '(':
        push(0, LEFT_PARENTHESIS, 0, operators);
        ptr_string++;
        break;
      case ')':
        while (operators->stackSize > 0 && peak(operators).type != '(') {
          Token tmp_token = {0};
          tmp_token = pop(operators);
          push(tmp_token.priority, tmp_token.type, tmp_token.value, output);
        }
        push(0, RIGHT_PARENTHESIS, 0, output);
        ptr_string++;
        break;
        push(1, X, 0, output);
        ptr_string++;
        break;
      case '+':
      case '-':
        push(2, MINUS, 0, operators);
        ptr_string++;
        break;
      case '*':
      case '/':
      case '^':
        push(3, POW, 0, operators);
        ptr_string++;
        break;
    }
    printStack(output);
  }
  // if (!string) {
  //   push(1, 1, 0, operators);
  // }
}

double stringToDouble(const char *string) {
  double num = 0;
  char *string_num;
  string_num = malloc(256 * sizeof(char));
  char *ptr_string_num = string_num;

  while (*string) {
    if (isdigit(*string) || *string == '.') {
      *ptr_string_num = *string;
      ptr_string_num++;
      if (!(isdigit(*(string + 1)) || *(string + 1) == '.')) break;
    }
    string++;
  }
  *ptr_string_num = '\0';
  printf("%s\n", string_num);
  num = atof(string_num);
  return num;
}