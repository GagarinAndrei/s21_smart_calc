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
  double monthly_peyments, total_payout, interest_charges, credit_amount,
      max_payment, min_payment, interest_rate;
  int credit_term;
};

#endif  // CREDIT_H
