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
}

void MainWindow::on_dot_button_clicked() {
  if (!(ui->display->text().contains('.'))) {
    ui->display->setText(ui->display->text() + ".");
  }
}

void MainWindow::on_pow_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "^");
}

void MainWindow::on_mod_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "mod");
}

void MainWindow::on_unary_minus_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "-");
}

void MainWindow::on_open_bracket_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "(");
}

void MainWindow::on_close_bracket_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + ")");
}

void MainWindow::on_mult_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "*");
}

void MainWindow::on_div_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "/");
}

void MainWindow::on_plus_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "+");
}

void MainWindow::on_minus_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "-");
}

void MainWindow::on_sqrt_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "sqrt(");
}

void MainWindow::on_cos_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "cos(");
}

void MainWindow::on_sin_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "sin(");
}

void MainWindow::on_tan_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "tan(");
}

void MainWindow::on_asin_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "asin(");
}

void MainWindow::on_acos_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "acos(");
}

void MainWindow::on_atan_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "atan(");
}

void MainWindow::on_ln_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "ln(");
}

void MainWindow::on_log_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "log(");
}

void MainWindow::on_x_button_clicked() {
  if (ui->display->text() == "0") {
    ui->display->clear();
  }
  ui->display->setText(ui->display->text() + "X");
}

void MainWindow::on_clear_button_clicked() {
  ui->display->clear();
  ui->display->setText("0");
}

void MainWindow::on_result_button_clicked() {
  QString string = ui->display->text();
  QByteArray ba = string.toLocal8Bit();
  char *inputString = ba.data();
  double result = dijkstraAlgorithm(inputString);
  ui->display->setText(QString::number(result));
}


void MainWindow::on_rb_plot_toggled(bool checked)
{
    if (checked == true) {
    plot.move(250, 400);
    plot.show();
    } else {
        plot.close();
    }
}


