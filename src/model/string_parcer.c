#include "string_parcer.h"
#include "token_stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void parceString(char *string, Stack *operators, Stack *operands) {
  double tmp_number;
  char *ptr_string = string;
  while (*ptr_string != '\0') {
    if (isdigit(*ptr_string)) {
      tmp_number = atof(ptr_string);
      do {
        ptr_string++;
      } while (isdigit(*ptr_string) || *ptr_string == '.');
      push(1, DIGIT, tmp_number, operands);
    } else
      ptr_string++;
  }
  if (!string) {
    push(1, 1, 0, operators);
  }
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
      if (!(isdigit(*(string + 1)) || *(string + 1) == '.'))
        break;
    }
    string++;
  }
  *ptr_string_num = '\0';
  printf("%s\n", string_num);
  num = atof(string_num);
  return num;
}