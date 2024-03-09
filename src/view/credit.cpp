#include "credit.h"

#include "ui_credit.h"

Credit::Credit(QWidget *parent) : QWidget(parent), ui(new Ui::Credit) {
  ui->setupUi(this);
  ui->dSB_monthly_payments_2->setVisible(false);
}

Credit::~Credit() { delete ui; }

void Credit::on_pB_calculate_clicked() {
  credit_amount = ui->dSB_credit_amount->value();
  interest_rate = ui->dSB_interest_rate->value();
  credit_term = ui->sB_credit_term->value();

  if (ui->rB_annuity->isChecked()) {
    total_payout = 0.0;
    double monthly_peyments;
    annuity(credit_amount, interest_rate, credit_term, &monthly_peyments);
    total_payout = monthly_peyments * credit_term;
    interest_charges = total_payout - credit_amount;

    ui->dSB_monthly_payments->setValue(monthly_peyments);
    ui->dSB_interest_charges->setValue(interest_charges);
    ui->dSB_total_payout->setValue(total_payout);
    ui->dSB_monthly_payments_2->setVisible(false);
  } else {
    double result[credit_term];
    total_payout = 0.0;
    differentiated(credit_amount, interest_rate, credit_term, result);
    min_payment = result[credit_term - 1];
    max_payment = result[0];
    for (int i = 0; i < credit_term; i++) {
      total_payout += result[i];
    }
    ui->dSB_monthly_payments_2->setVisible(true);
    ui->dSB_total_payout->setValue(total_payout);
    ui->dSB_interest_charges->setValue(total_payout - credit_amount);
    ui->dSB_monthly_payments_2->setValue(max_payment);
    ui->dSB_monthly_payments->setValue(min_payment);
  }
}
