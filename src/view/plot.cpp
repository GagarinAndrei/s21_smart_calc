#include "plot.h"
#include "headers/dijkstra_algorithm.h"
#include "ui_plot.h"

Plot::Plot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Plot)
{
    ui->setupUi(this);

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(xVector, yVector);
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget->replot();

}

Plot::~Plot()
{
    delete ui;
}



void Plot::on_sB_min_X_textChanged(const QString &arg1)
{
    ui->widget->xAxis->setRangeUpper(arg1.toDouble());
    ui->widget->replot();

}


void Plot::on_sB_max_X_textChanged(const QString &arg1)
{
    ui->widget->xAxis->setRangeUpper(arg1.toDouble());
    ui->widget->replot();


}


void Plot::on_sB_min_Y_textChanged(const QString &arg1)
{
    ui->widget->yAxis->setRangeLower(arg1.toDouble());
    ui->widget->replot();


}


void Plot::on_sB_max_Y_textChanged(const QString &arg1)
{
    ui->widget->yAxis->setRangeUpper(arg1.toDouble());
    ui->widget->replot();
}

void Plot::printGraph()
{
    pointCounts = (xEnd - xStart) / step + 2;
    xVector.clear();
    yVector.clear();
    tempX = xStart;
    for (int i = 0; i < pointCounts; i++) {
        xVector.push_back(xStart + i * step);
        yVector.push_back(dijkstraAlgorithm(inputString, tempX + i * step));
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(xVector, yVector);
    ui->widget->replot();
}

void Plot::plotSlot()
{
    ui->widget->clearGraphs();
    printGraph();
}

