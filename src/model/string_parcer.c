#include "string_parcer.h"
#include <stdio.h>

// void parceString(char *string, token **operators, token **operands) {
//   double tmp_number;
//   while (*string) {
//     double num = 0;
//     int exp = 0;
//     if (isDigit(*string)) {
//       num += (int)*string * pow(10, exp);
//       exp++;
//     }
//   }
// }

// int stringToDouble(char *string, ) {

// }

int isDigit(char c) {
  return (c >= '0' && c <= '9');
}