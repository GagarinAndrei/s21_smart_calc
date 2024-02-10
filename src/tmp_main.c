
#include "model/string_parcer.h"
#include "model/token_stack.h"

int main(void) {
  char *string = "s 123.456ab600f 234";
  Stack operands;
  Stack operators;
  init(&operands);
  init(&operators);
  parceString(string, &operators, &operands);
  //===============================


  //===============================

  printStack(&operands);
  destroy(&operands);
  destroy(&operators);
  return 0;
}
