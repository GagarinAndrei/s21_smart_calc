#ifndef CREDIT_H
#define CREDIT_H

typedef enum { ANNUITY, DIFFERENTIATED } creditType;

double creditTypeChooser(double creditAmount, double interestRate,
                         int creditTerm, int creditType);
double annuity(double creditAmount, double interestRate, int creditTerm);
double differentiated(double creditAmount, double interestRate, int creditTerm);
#endif