#include "headers/function_type_determinant.h"

int functionTypeDeterminant(char *ptrInputString, int *functionType) {
  int funcSize = 0;
  if (ptrInputString[0] == 'm' && ptrInputString[1] == 'o' &&
      ptrInputString[2] == 'd') {
    *functionType = MOD;
    funcSize = 3;
  } else if (ptrInputString[0] == 'c' && ptrInputString[1] == 'o' &&
             ptrInputString[2] == 's') {
    *functionType = COS;
    funcSize = 3;
  } else if (ptrInputString[0] == 's' && ptrInputString[1] == 'i' &&
             ptrInputString[2] == 'n') {
    *functionType = SIN;
    funcSize = 3;
  } else if (ptrInputString[0] == 't' && ptrInputString[1] == 'a' &&
             ptrInputString[2] == 'n') {
    *functionType = TAN;
    funcSize = 3;
  } else if (ptrInputString[0] == 'a' && ptrInputString[1] == 'c' &&
             ptrInputString[2] == 'o' && ptrInputString[3] == 's') {
    *functionType = ACOS;
    funcSize = 4;
  } else if (ptrInputString[0] == 'a' && ptrInputString[1] == 's' &&
             ptrInputString[2] == 'i' && ptrInputString[3] == 'n') {
    *functionType = ASIN;
    funcSize = 4;
  } else if (ptrInputString[0] == 'a' && ptrInputString[1] == 't' &&
             ptrInputString[2] == 'a' && ptrInputString[3] == 'n') {
    *functionType = ATAN;
    funcSize = 4;
  } else if (ptrInputString[0] == 's' && ptrInputString[1] == 'q' &&
             ptrInputString[2] == 'r' && ptrInputString[3] == 't') {
    *functionType = SQRT;
    funcSize = 4;
  } else if (ptrInputString[0] == 'l' && ptrInputString[1] == 'n') {
    *functionType = LN;
    funcSize = 2;
  } else if (ptrInputString[0] == 'l' && ptrInputString[1] == 'o' &&
             ptrInputString[2] == 'g') {
    *functionType = LOG;
    funcSize = 3;
  }
  return funcSize;
}