#include "../headers/function_type_determinant.h"

int functionTypeDeterminant(char *ptrIntString, Stack *operators) {
  
  return result;
}

int isMod(char *ptrInputString) {

if (ptrInputString[0] == 'm' && ptrInputString[1] == 'o' &&
      ptrInputString[2] == 'd') {
    push(SUPERA, MOD, 0, &operators);
}
    ptrInputString += 3;
  } else if (ptrInputString[0] == 'c' && ptrInputString[1] == 'o' &&
             ptrInputString[2] == 's') {
    push(SUPERA, COS, 0, &operators);
    ptrInputString += 3;
  } else if (ptrInputString[0] == 's' && ptrInputString[1] == 'i' &&
             ptrInputString[2] == 'n') {
    push(SUPERA, SIN, 0, &operators);
    ptrInputString += 3;
  } else if (ptrInputString[0] == 't' && ptrInputString[1] == 'a' &&
             ptrInputString[2] == 'n') {
    push(SUPERA, TAN, 0, &operators);
    ptrInputString += 3;
  } else if (ptrInputString[0] == 'a' && ptrInputString[1] == 'c' &&
             ptrInputString[2] == 'o' && ptrInputString[2] == 's') {
    push(SUPERA, ACOS, 0, &operators);
    ptrInputString += 4;
  } else if (ptrInputString[0] == 'a' && ptrInputString[1] == 's' &&
             ptrInputString[2] == 'i' && ptrInputString[2] == 'n') {
    push(SUPERA, ASIN, 0, &operators);
    ptrInputString += 4;
  } else if (ptrInputString[0] == 'a' && ptrInputString[1] == 't' &&
             ptrInputString[2] == 'a' && ptrInputString[2] == 'n') {
    push(SUPERA, ATAN, 0, &operators);
    ptrInputString += 4;
  } else if (ptrInputString[0] == 's' && ptrInputString[1] == 'q' &&
             ptrInputString[2] == 'r' && ptrInputString[2] == 't') {
    push(SUPERA, SQRT, 0, &operators);
    ptrInputString += 4;
  } else if (ptrInputString[0] == 'l' && ptrInputString[1] == 'n') {
    push(SUPERA, LN, 0, &operators);
    ptrInputString += 2;
  } else if (ptrInputString[0] == 'l' && ptrInputString[1] == 'o' &&
             ptrInputString[2] == 'g') {
    push(SUPERA, LOG, 0, &operators);
    ptrInputString += 3;
  }
  return ptrInputString;