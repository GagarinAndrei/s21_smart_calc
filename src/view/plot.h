#ifndef PLOT_H
#define PLOT_H

#include <QWidget>

namespace Ui {
class Plot;
}

class Plot : public QWidget
{
    Q_OBJECT

public:
    explicit Plot(QWidget *parent = nullptr);
    ~Plot();

private slots:

    void on_sB_min_X_textChanged(const QString &arg1);

    void on_sB_max_X_textChanged(const QString &arg1);

    void on_sB_min_Y_textChanged(const QString &arg1);

    void on_sB_max_Y_textChanged(const QString &arg1);

private:
    Ui::Plot *ui;
    double xStart, xEnd, step, tempX;
    int pointCounts;
    char *inputString;
    QVector<double> xVector,yVector;
    void printGraph();

public slots:
    void plotSlot();
};

#endif // PLOT_H
