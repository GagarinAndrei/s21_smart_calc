#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_number_button_clicked();
    void on_dot_button_clicked();
    void on_pow_button_clicked();
//    void on_unary_minus_button_clicked();
//    void on_mod_button_clicked();
//    void on_open_bracket_button_clicked();
//    void on_close_bracket_button_clicked();
//    void on_mult_button_clicked();
//    void on_div_button_clicked();
//    void on_plus_button_clicked();
//    void on_minus_button_clicked();
//    void on_clear_button_clicked();
//    void on_sqrt_button_clicked();
//    void on_cos_button_clicked();
//    void on_sin_button_clicked();
//    void on_tan_button_clicked();
//    void on_asin_button_clicked();
//    void on_acos_button_clicked();
//    void on_atan_button_clicked();
//    void on_ln_button_clicked();
//    void on_log_button_clicked();
//    void on_x_button_clicked();
//    void on_result_button_clicked();

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
