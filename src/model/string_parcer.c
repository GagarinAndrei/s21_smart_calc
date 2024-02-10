#include "string_parcer.h"
#include <ctype.h>
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

double stringToDouble(const char *string) {
  double num = 0;
  char *string_num;
  string_num = malloc(256 * sizeof(char));
  char *ptr_string_num = string_num;
  // int end_ptr = 0;

  while (*string) {
    if (isdigit(*string) || *string == '.') {
      *ptr_string_num = *string;
      ptr_string_num++;
      // end_ptr++;
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