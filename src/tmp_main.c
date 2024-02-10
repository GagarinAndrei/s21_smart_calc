
#include "model/string_parcer.h"
#include "model/token_stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *string = "sdf 345.345sdfsd600f";

  //===============================
  double num = stringToDouble(string);
  //===============================

  printf("%lf\n", num);

  return 0;
}
