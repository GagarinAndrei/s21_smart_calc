#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define START -1000000
#define END 1000000

#include <QMainWindow>
#include <QVector>

#include "view/credit.h"
#include "view/deposite.h"
#include "view/plot.h"

extern "C" {
#include "./headers/dijkstra_algorithm.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void text_to_display_on_button_clicked();
  void on_dot_button_clicked();
  void on_pow_button_clicked();
  void on_unary_minus_button_clicked();
  void on_unary_plus_button_clicked();
  void on_mod_button_clicked();
  void on_open_bracket_button_clicked();
  void on_close_bracket_button_clicked();
  void on_mult_button_clicked();
  void on_div_button_clicked();
  void on_plus_button_clicked();
  void on_minus_button_clicked();
  void on_clear_button_clicked();
  void on_sqrt_button_clicked();
  void on_cos_button_clicked();
  void on_sin_button_clicked();
  void on_tan_button_clicked();
  void on_asin_button_clicked();
  void on_acos_button_clicked();
  void on_atan_button_clicked();
  void on_ln_button_clicked();
  void on_log_button_clicked();
  void on_x_button_clicked();
  void on_result_button_clicked();

  void operator_button_availability(bool is_enabled);
  void number_button_availability(bool is_enabled);
  void trigonometrics_button_availability(bool is_enabled);
  void close_bracket_and_result_availability(int open_brackets_count);
  void dot_availability(bool is_dot_present_in_number, bool is_digit);

  void on_rB_credit_toggled(bool checked);
  void on_rB_plot_toggled(bool checked);
  void on_rB_deposit_toggled(bool checked);

 private:
  Ui::MainWindow *ui;
  Plot plot;
  Credit credit;
  Deposite deposite;
  int open_bracket_count = 0;
  bool is_dot_present_in_digit;
  bool is_digit;
};

#endif  // MAINWINDOW_H
