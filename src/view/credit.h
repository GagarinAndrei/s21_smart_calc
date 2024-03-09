#ifndef CREDIT_H
#define CREDIT_H

#include <QWidget>

extern "C" {
#include "./headers/credits.h"
}

namespace Ui {
class Credit;
}

class Credit : public QWidget {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private slots:
  void on_pB_calculate_clicked();

 private:
  Ui::Credit *ui;
  double total_payout = 0, interest_charges = 0, credit_amount = 0,
         max_payment = 0, min_payment = 0, interest_rate = 0;
  int credit_term = 0;
};

#endif  // CREDIT_H
