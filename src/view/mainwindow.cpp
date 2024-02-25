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
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_unary_minus_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_mod_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_open_bracket_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_close_bracket_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_mult_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_div_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_plus_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_minus_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_clear_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_sqrt_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_cos_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_sin_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_tan_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_asin_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_acos_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_atan_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_ln_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_log_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_x_button_clicked()));
//  connect(ui->pB_dot, SIGNAL(clicked()), this, SLOT(on_result_button_clicked()));
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
}

void MainWindow::on_dot_button_clicked() {
  if (!(ui->display->text().contains('.'))) {
    ui->display->setText(ui->display->text() + ".");
  }
}

void MainWindow::on_pow_button_clicked() {
//  if (!(ui->display->text().contains('.'))) {
    ui->display->setText(ui->display->text() + "^");
//  }
}

