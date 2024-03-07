#ifndef PLOT_H
#define PLOT_H

#include <QWidget>

extern "C" {
#include "./headers/dijkstra_algorithm.h"
}

namespace Ui {
class Plot;
}

class Plot : public QWidget {
  Q_OBJECT

 public:
  explicit Plot(QWidget *parent = nullptr);
  ~Plot();

 private:
  Ui::Plot *ui;

 public slots:
  void print_graph(char *input_string);
};

#endif  // PLOT_H
