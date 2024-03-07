#include "deposite.h"

#include "ui_deposite.h"

Deposite::Deposite(QWidget *parent) : QWidget(parent), ui(new Ui::Deposite) {
  ui->setupUi(this);
}

Deposite::~Deposite() { delete ui; }
