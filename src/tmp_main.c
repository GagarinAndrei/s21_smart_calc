
#include "headers/string_parcer.h"
// #include "headers/token_stack.h"
// #include "smart_calc.h"
#include <stdio.h>

int main(void) {
  // char *string = "s 123.456ab600f 234";
  // char *string = "(1+2)*3^4^5-6/(7+8/9)";
  char *string = "(1+2.5)*3^4";
  // char *string = "2*(3+5/2)";
  printf("INPUT_STRING:%s\n", string);
  char *output = (char *)calloc(255, sizeof(char));
  Stack operators;
  // init(&output);
  init(&operators);
  parceString(string, &operators, output);
  //===============================

  //===============================
  printStack(&operators);
  printf("OUTPUT:%s\n", output);
  // destroy(&output);
  destroy(&operators);
  return 0;
}
