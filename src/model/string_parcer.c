#include "../headers/string_parcer.h"

void parceString(char *inputString, Stack *operators, char *output) {
  // double tmp_number;
  // char *space = " ";
  char *ptrInputString = inputString;
  while (*ptrInputString != '\0') {
    if (isdigit(*ptrInputString) || *ptrInputString == '.') {
      strncat(output, ptrInputString, 1);
      // tmp_number = atof(ptr_string);
      // do {
      // ptr_string++;
      // } while (isdigit(*ptr_string) || *ptr_string == '.');
      // push(1, tmp_number, operators);
    } else {
      switch (*ptrInputString) {
        case 'x':
        case '(':
          push(0, *ptrInputString, operators);
          break;
        case ')':
          while (peak(operators).operation != '(') {
            char tmp = peak(operators).operation;
            strncat(output, &tmp, 1);
            pop(operators);
          }
          pop(operators);
          break;
          break;
        case '+':
        case '-':
          push(2, *ptrInputString, operators);
          break;
        case '*':
        case '/':
        case '^':
          push(3, *ptrInputString, operators);
          break;
      }
      printf("OUTPUT:%s\n", output);
      printStack(operators);
    }
    ptrInputString++;
  }
  while (operators->stackSize != 0) {
    char buffer = pop(operators).operation;
    strncat(output, &buffer, 1);
  }
}

// double stringToDouble(const char *string) {
//   double num = 0;
//   char *string_num;
//   string_num = malloc(256 * sizeof(char));
//   char *ptr_string_num = string_num;

//   while (*string) {
//     if (isdigit(*string) || *string == '.') {
//       *ptr_string_num = *string;
//       ptr_string_num++;
//       if (!(isdigit(*(string + 1)) || *(string + 1) == '.'))
//         break;
//     }
//     string++;
//   }
//   *ptr_string_num = '\0';
//   printf("%s\n", string_num);
//   num = atof(string_num);
//   return num;
// }