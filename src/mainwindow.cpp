#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->pB_0, SIGNAL(clicked()), this, SLOT(on_number_button_clicked()));
  connect(ui->pB_1, SIGNAL(clicked()), this, SLOT(on_number_button_clicked()));
  connect(ui->pB_2, SIGNAL(clicked()), this, SLOT(on_number_button_clicked()));
  connect(ui->pB_3, SIGNAL(clicked()), this, SLOT(on_number_button_clicked()));
  connect(ui->pB_4, SIGNAL(clicked()), this, SLOT(on_number_button_clicked()));
  connect(ui->pB_5, SIGNAL(clicked()), this, SLOT(on_number_button_clicked()));
  connect(ui->pB_6, SIGNAL(clicked()), this, SLOT(on_number_button_clicked()));
  connect(ui->pB_7, SIGNAL(clicked()), this, SLOT(on_number_button_clicked()));
  connect(ui->pB_8, SIGNAL(clicked()), this, SLOT(on_number_button_clicked()));
  connect(ui->pB_9, SIGNAL(clicked()), this, SLOT(on_number_button_clicked()));
  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_dot_button_clicked()));
  connect(ui->pB_pow, SIGNAL(clicked()), this, SLOT(on_pow_button_clicked()));
  connect(ui->pB_unary_minus, SIGNAL(clicked()), this,
          SLOT(on_unary_minus_button_clicked()));
  connect(ui->pB_mod, SIGNAL(clicked()), this, SLOT(on_mod_button_clicked()));
  connect(ui->pB_open_bracket, SIGNAL(clicked()), this,
          SLOT(on_open_bracket_button_clicked()));
  connect(ui->pB_close_bracket, SIGNAL(clicked()), this,
          SLOT(on_close_bracket_button_clicked()));
  connect(ui->pB_mult, SIGNAL(clicked()), this, SLOT(on_mult_button_clicked()));
  connect(ui->pB_div, SIGNAL(clicked()), this, SLOT(on_div_button_clicked()));
  connect(ui->pB_plus, SIGNAL(clicked()), this, SLOT(on_plus_button_clicked()));
  connect(ui->pB_minus, SIGNAL(clicked()), this,
          SLOT(on_minus_button_clicked()));
  connect(ui->pB_clear, SIGNAL(clicked()), this,
          SLOT(on_clear_button_clicked()));
  connect(ui->pB_sqrt, SIGNAL(clicked()), this, SLOT(on_sqrt_button_clicked()));
  connect(ui->pB_cos, SIGNAL(clicked()), this, SLOT(on_cos_button_clicked()));
  connect(ui->pB_sin, SIGNAL(clicked()), this, SLOT(on_sin_button_clicked()));
  connect(ui->pB_tan, SIGNAL(clicked()), this, SLOT(on_tan_button_clicked()));
  connect(ui->pB_asin, SIGNAL(clicked()), this, SLOT(on_asin_button_clicked()));
  connect(ui->pB_acos, SIGNAL(clicked()), this, SLOT(on_acos_button_clicked()));
  connect(ui->pB_atan, SIGNAL(clicked()), this, SLOT(on_atan_button_clicked()));
  connect(ui->pB_ln, SIGNAL(clicked()), this, SLOT(on_ln_button_clicked()));
  connect(ui->pB_log, SIGNAL(clicked()), this, SLOT(on_log_button_clicked()));
  connect(ui->pB_x, SIGNAL(clicked()), this, SLOT(on_x_button_clicked()));
  connect(ui->pB_result, SIGNAL(clicked()), this,
          SLOT(on_result_button_clicked()));

}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_number_button_clicked() {

  if (ui->display->text() == "0") {
    ui->display->clear();
  }

  QPushButton *button = (QPushButton *)sender();
  QString expressionString;

  expressionString = ui->display->text() + button->text();
  ui->display->setText(expressionString);
  operator_button_availability(true, 0);
  trigonometrics_availability(false);
  ui->pB_x->setEnabled(false);

}

void MainWindow::on_dot_button_clicked() {
    ui->display->setText(ui->display->text() + ".");
    ui->pB_dot->setEnabled(false);
}

void MainWindow::on_pow_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "^");
  operator_button_availability(false, 0);
  number_button_availability(true);
  trigonometrics_availability(true);
  ui->pB_dot->setEnabled(true);
}

void MainWindow::on_mod_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "mod");
  operator_button_availability(false, '(');
  number_button_availability(true);
  trigonometrics_availability(true);
  ui->pB_dot->setEnabled(true);
}

void MainWindow::on_unary_minus_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "-");
  operator_button_availability(false, 0);
  number_button_availability(true);
  trigonometrics_availability(true);
  ui->pB_dot->setEnabled(true);
}

void MainWindow::on_open_bracket_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "(");
  operator_button_availability(false, '(');
  number_button_availability(true);
  trigonometrics_availability(true);
  ui->pB_dot->setEnabled(true);
}

void MainWindow::on_close_bracket_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + ")");
  number_button_availability(false);

}

void MainWindow::on_mult_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "*");
  operator_button_availability(false, 0);
  number_button_availability(true);
  trigonometrics_availability(true);
  ui->pB_dot->setEnabled(true);
}

void MainWindow::on_div_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "/");
  operator_button_availability(false, 0);
  number_button_availability(true);
  ui->pB_0->setEnabled(false);
  trigonometrics_availability(true);
   ui->pB_dot->setEnabled(true);
}

void MainWindow::on_plus_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "+");
  operator_button_availability(false, 0);
  number_button_availability(true);
  trigonometrics_availability(true);
ui->pB_dot->setEnabled(true);
}

void MainWindow::on_minus_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "-");
  operator_button_availability(false, 0);
  number_button_availability(true);
  trigonometrics_availability(true);
ui->pB_dot->setEnabled(true);
}

void MainWindow::on_sqrt_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "sqrt(");
  operator_button_availability(false, '(');
  number_button_availability(true);
  trigonometrics_availability(true);
ui->pB_dot->setEnabled(true);
}

void MainWindow::on_cos_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "cos(");
  operator_button_availability(false, '(');
  number_button_availability(true);
  trigonometrics_availability(true);
ui->pB_dot->setEnabled(true);
}

void MainWindow::on_sin_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "sin(");
  operator_button_availability(false, '(');
  number_button_availability(true);
  trigonometrics_availability(true);
ui->pB_dot->setEnabled(true);
}

void MainWindow::on_tan_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "tan(");
  operator_button_availability(false, '(');
  number_button_availability(true);
  trigonometrics_availability(true);
ui->pB_dot->setEnabled(true);
}

void MainWindow::on_asin_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "asin(");
  operator_button_availability(false, '(');
  number_button_availability(true);
  trigonometrics_availability(true);
ui->pB_dot->setEnabled(true);
}

void MainWindow::on_acos_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "acos(");
  operator_button_availability(false, '(');
  number_button_availability(true);
  trigonometrics_availability(true);
ui->pB_dot->setEnabled(true);
}

void MainWindow::on_atan_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "atan(");
  operator_button_availability(false, '(');
  number_button_availability(true);
  trigonometrics_availability(true);
ui->pB_dot->setEnabled(true);
}

void MainWindow::on_ln_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "ln(");
  operator_button_availability(false, '(');
  number_button_availability(true);
  trigonometrics_availability(true);
ui->pB_dot->setEnabled(true);
}

void MainWindow::on_log_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "log(");
  operator_button_availability(false, '(');
  number_button_availability(true);
  trigonometrics_availability(true);
ui->pB_dot->setEnabled(true);
}

void MainWindow::on_x_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "x");
  operator_button_availability(false, '(');
  number_button_availability(false);
  trigonometrics_availability(false);
  arifmetics_availability(true);
}

void MainWindow::on_clear_button_clicked() {
  ui->display->clear();
  ui->display->setText("0");
  operator_button_availability(true, 0);
  number_button_availability(true);
  trigonometrics_availability(true);
  ui->pB_dot->setEnabled(true);
}

void MainWindow::on_result_button_clicked() {
  QString string = ui->display->text();
  QByteArray ba = string.toLocal8Bit();
  char *inputString = ba.data();
  double x = ui->dSB_xValue->value();
  double result;
  result = dijkstraAlgorithm(inputString, x);
  string = QString::number(result);
  ui->display->setText(string);
  number_button_availability(true);
  operator_button_availability(true, 0);
  trigonometrics_availability(true);
  ui->pB_dot->setEnabled(true);

}

void MainWindow::on_rb_plot_toggled(bool checked)
{
    if (checked == true) {
    plot.move(0, 400);
    plot.show();
    } else {
        plot.close();
    }
}

void MainWindow::on_rB_credit_toggled(bool checked)
{
    if (checked == true) {
        credit.show();
    } else {
        credit.close();
    }
}

void MainWindow::on_rB_deposit_toggled(bool checked)
{
    if (checked == true) {
        deposite.show();
    } else {
        deposite.close();
    }
}


void MainWindow::operator_button_availability(bool is_enabled, char operation) {
    if (operation == '(') {
        after_open_bracket_buttons(is_enabled);
    } else {
    ui->pB_close_bracket->setEnabled(is_enabled);
    trigonometrics_availability(is_enabled);
    arifmetics_availability(is_enabled);
    ui->pB_unary_minus->setEnabled(is_enabled);
    }
}

void MainWindow::after_open_bracket_buttons(bool is_enabled) {
    ui->pB_close_bracket->setEnabled(is_enabled);
    ui->pB_mod->setEnabled(is_enabled);
    ui->pB_dot->setEnabled(is_enabled);
    ui->pB_plus->setEnabled(is_enabled);
    ui->pB_minus->setEnabled(is_enabled);
    ui->pB_mult->setEnabled(is_enabled);
    ui->pB_div->setEnabled(is_enabled);
}

void MainWindow::number_button_availability(bool is_enabled) {
    ui->pB_0->setEnabled(is_enabled);
    ui->pB_1->setEnabled(is_enabled);
    ui->pB_2->setEnabled(is_enabled);
    ui->pB_3->setEnabled(is_enabled);
    ui->pB_4->setEnabled(is_enabled);
    ui->pB_5->setEnabled(is_enabled);
    ui->pB_6->setEnabled(is_enabled);
    ui->pB_7->setEnabled(is_enabled);
    ui->pB_8->setEnabled(is_enabled);
    ui->pB_9->setEnabled(is_enabled);
}

void MainWindow::arifmetics_availability(bool is_enabled) {
    ui->pB_mod->setEnabled(is_enabled);
    ui->pB_pow->setEnabled(is_enabled);
    // ui->pB_dot->setEnabled(is_enabled);
    ui->pB_plus->setEnabled(is_enabled);
    ui->pB_minus->setEnabled(is_enabled);
    ui->pB_mult->setEnabled(is_enabled);
    ui->pB_div->setEnabled(is_enabled);
    // ui->pB_x->setEnabled(is_enabled);
}

void MainWindow::trigonometrics_availability(bool is_enabled) {
    ui->pB_acos->setEnabled(is_enabled);
    ui->pB_asin->setEnabled(is_enabled);
    ui->pB_atan->setEnabled(is_enabled);
    ui->pB_cos->setEnabled(is_enabled);
    ui->pB_sin->setEnabled(is_enabled);
    ui->pB_tan->setEnabled(is_enabled);
    ui->pB_sqrt->setEnabled(is_enabled);
    ui->pB_ln->setEnabled(is_enabled);
    ui->pB_log->setEnabled(is_enabled);
    ui->pB_x->setEnabled(is_enabled);
}


