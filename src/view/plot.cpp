#include "plot.h"

#include "ui_plot.h"

Plot::Plot(QWidget *parent) : QWidget(parent), ui(new Ui::Plot) {
  ui->setupUi(this);
}

Plot::~Plot() { delete ui; }

void Plot::print_graph(char *input_string) {
  int min_x, max_x, min_y, max_y;
  min_x = ui->sB_min_X->value();
  max_x = ui->sB_max_X->value();
  min_y = ui->sB_min_Y->value();
  max_y = ui->sB_max_Y->value();
  double temp_x = 0;
  int accuracy = 200;
  QVector<double> vector_x(accuracy), vector_y(accuracy);

  double step = (max_x - min_x) / (accuracy - 1.0);

  ui->function_graph->addGraph();
  ui->function_graph->graph(0)->setPen(QPen(Qt::blue));
  ui->function_graph->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

  for (int i = 0; i < accuracy - 1; i++) {
    vector_x[i] = min_x + temp_x;
    vector_y[i] = dijkstraAlgorithm(input_string, vector_x[i]);
    temp_x += step;
  }
  vector_x[accuracy - 1] = 0;
  vector_y[accuracy - 1] =
      dijkstraAlgorithm(input_string, vector_x[accuracy - 1]);
  ui->function_graph->graph(0)->setData(vector_x, vector_y);
  ui->function_graph->graph(0)->rescaleAxes();
  ui->function_graph->xAxis->setRange(min_x, max_x);
  ui->function_graph->yAxis->setRange(min_y, max_y);
  ui->function_graph->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom |
                                      QCP::iSelectPlottables);
  ui->function_graph->replot();
}
