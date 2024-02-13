
#include "model/string_parcer.h"
#include "model/token_stack.h"
#include "utils.h"
#include <stdio.h>

int main(void) {
  // char *string = "s 123.456ab600f 234";
  char *string = "(1+2)*3^4-6/(7+8/9)";
  // char *string = "(1+2)*3^4";
  Stack output;
  Stack operators;
  init(&output);
  init(&operators);
  parceString(string, &operators, &output);
  //===============================

  //===============================
  printf("-=RPN=-:\n");
  printStack(&output);
  // printStack(&output);
  destroy(&output);
  destroy(&operators);
  return 0;
}
