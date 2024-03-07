#include "../headers/credit.h"

#include <math.h>

double annuity(double creditAmount, double interestRate, int creditTerm) {
  double result;
  double balanceOfLoanAmount = creditAmount;
  double monthlyInterestRate = interestRate / (100 * 12);
  int interestPeriods = creditTerm;

  result = balanceOfLoanAmount * monthlyInterestRate /
           (1 - (1 + pow(monthlyInterestRate, -interestPeriods)));
  return result;
}