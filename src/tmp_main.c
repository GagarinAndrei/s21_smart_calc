
#include "model/string_parcer.h"
#include "model/token_stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(void) {
  char *string = "sdf 345.345sdfsd600f";

  //===============================
  // double num = 0;
  // char *string_num;
  // string_num = malloc(256 * sizeof(char));
  // char *ptr_string_num = string_num;

  // while (*string) {
  //   if (isdigit(*string) || *string == '.') {
  //     *ptr_string_num = *string;
  //     ptr_string_num++;
  //   }
  //   string++;
  // }
  // *ptr_string_num = '\0';
  // printf("%s\n", string_num);
  // num = atof(string_num);
  double num = stringToDouble(string);
  //===============================

  printf("%lf\n", num);

  return 0;
}
