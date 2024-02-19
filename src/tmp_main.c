
#include "headers/string_parcer.h"
#include "headers/token_stack.h"
// #include "headers/token_stack.h"
// #include "smart_calc.h"
#include <stdio.h>

int main(void) {
  // char *string = "(1+2)*3^2^2-6/(7+8/9)";
  char *string = "5/2 - (1 + 3.5) * 3^4";
  // char *string = "2*(3+5/2)";
  printf("\033[42mINPUT_STRING:\033[0m %s\n", string);
  // char *output = (char *)calloc(255, sizeof(char));
  Stack operators, values;
  // init(&output);
  init(&operators);
  init(&values);
  parceString(string, &operators, &values);
  //===============================

  //===============================
  printStack(&operators, OPERATOR);
  printStack(&values, VALUE);
  // printf("OUTPUT:%s\n", output);
  // destroy(&output);
  destroy(&operators);
  destroy(&values);
  return 0;
}
