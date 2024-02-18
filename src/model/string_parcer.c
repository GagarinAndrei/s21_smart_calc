#include "../headers/string_parcer.h"

void parceString(char *inputString, Stack *operators, Stack *values) {
  double tmp_number;
  char *ptrInputString = inputString;
  while (*ptrInputString != '\0') {
    if (isdigit(*ptrInputString)) {
      tmp_number = atof(ptrInputString);
      do {
        ptrInputString++;
      } while (isdigit(*ptrInputString) || *ptrInputString == '.');
      push(0, 0, tmp_number, values);
    } else {
      switch (*ptrInputString) {
      case 'x':
      case '(':
        push(OPEN_PARENTHESIS, *ptrInputString, 0, operators);
        ptrInputString++;
        break;
      case ')':
        while (peak(operators).operation != '(') {
          long double calcResult = valuesCalculation(values, operators);
          push(0, 0, calcResult, values);
        }
        pop(operators);
        ptrInputString++;
        break;
      case '+':
      case '-':
        if (isHigherPriority(operators, PLUS_MINUS))
          push(PLUS_MINUS, *ptrInputString, 0, operators);
        else {
          long double calcResult = valuesCalculation(values, operators);
          push(0, 0, calcResult, values);
          push(PLUS_MINUS, *ptrInputString, 0, operators);
        }
        ptrInputString++;
        break;
      case '*':
      case '/':
        if (isHigherPriority(operators, MULT_DIV))
          push(MULT_DIV, *ptrInputString, 0, operators);
        else {
          long double calcResult = valuesCalculation(values, operators);
          push(0, 0, calcResult, values);
          push(MULT_DIV, *ptrInputString, 0, operators);
        }
        ptrInputString++;
        break;
      case '^':
        if (isHigherPriority(operators, POW))
          push(POW, *ptrInputString, 0, operators);
        else {
          long double calcResult = valuesCalculation(values, operators);
          push(0, 0, calcResult, values);
          push(POW, *ptrInputString, 0, operators);
        }
        ptrInputString++;
        break;
      default:
        ptrInputString++;
      }
      printf("===============================================\n");
      printStack(operators, OPERATOR);
      printStack(values, VALUE);
    }
  }
  while (operators->stackSize != 0) {
    long double calcResult = valuesCalculation(values, operators);
    push(0, 0, calcResult, values);
  }
  // while (operators->stackSize != 0) {
  //   char buffer = pop(operators).operation;
  //   // strncat(output, &buffer, 1);
  // }
}

int isHigherPriority(const Stack *operators, int priority) {
  int result = 0;
  if (operators->stackSize > 0) {
    int inStackOperatorPriority = peak(operators).priority;
    result = inStackOperatorPriority < priority;
  }
  if (operators->stackSize == 0)
    result = 1;
  return result;
}

long double valuesCalculation(Stack *values, Stack *operators) {
  long double result, a, b;
  b = pop(values).value;
  a = pop(values).value;
  switch (pop(operators).operation) {
  case '+':
    result = a + b;
    break;
  case '-':
    result = a - b;
    break;
  case '*':
    result = a * b;
    break;
  case '/':
    result = a / b;
    break;
  case '^':
    result = pow(a, b);
    break;
  }
  return result;
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