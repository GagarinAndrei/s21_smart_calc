/********************************************************************************
** Form generated from reading UI file 'plot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOT_H
#define UI_PLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Plot
{
public:
    QCustomPlot *widget;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLabel *l_min_X;
    QLabel *l_min_Y;
    QSpinBox *sB_min_X;
    QSpinBox *sB_min_Y;
    QLabel *l_max_X;
    QLabel *l_max_Y;
    QSpinBox *sB_max_X;
    QSpinBox *sB_max_Y;

    void setupUi(QWidget *Plot)
    {
        if (Plot->objectName().isEmpty())
            Plot->setObjectName(QString::fromUtf8("Plot"));
        Plot->resize(640, 707);
        widget = new QCustomPlot(Plot);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 640, 480));
        widget1 = new QWidget(Plot);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 490, 621, 206));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        l_min_X = new QLabel(widget1);
        l_min_X->setObjectName(QString::fromUtf8("l_min_X"));
        QFont font;
        font.setFamily(QString::fromUtf8("Fira Code"));
        font.setPointSize(24);
        l_min_X->setFont(font);
        l_min_X->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(l_min_X, 0, 0, 1, 1);

        l_min_Y = new QLabel(widget1);
        l_min_Y->setObjectName(QString::fromUtf8("l_min_Y"));
        l_min_Y->setFont(font);
        l_min_Y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(l_min_Y, 0, 1, 1, 1);

        sB_min_X = new QSpinBox(widget1);
        sB_min_X->setObjectName(QString::fromUtf8("sB_min_X"));
        sB_min_X->setFont(font);
        sB_min_X->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sB_min_X->setMinimum(-1000000);
        sB_min_X->setMaximum(1000000);

        gridLayout->addWidget(sB_min_X, 1, 0, 1, 1);

        sB_min_Y = new QSpinBox(widget1);
        sB_min_Y->setObjectName(QString::fromUtf8("sB_min_Y"));
        sB_min_Y->setFont(font);
        sB_min_Y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sB_min_Y->setMinimum(-1000000);
        sB_min_Y->setMaximum(1000000);

        gridLayout->addWidget(sB_min_Y, 1, 1, 1, 1);

        l_max_X = new QLabel(widget1);
        l_max_X->setObjectName(QString::fromUtf8("l_max_X"));
        l_max_X->setFont(font);
        l_max_X->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(l_max_X, 2, 0, 1, 1);

        l_max_Y = new QLabel(widget1);
        l_max_Y->setObjectName(QString::fromUtf8("l_max_Y"));
        l_max_Y->setFont(font);
        l_max_Y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(l_max_Y, 2, 1, 1, 1);

        sB_max_X = new QSpinBox(widget1);
        sB_max_X->setObjectName(QString::fromUtf8("sB_max_X"));
        sB_max_X->setFont(font);
        sB_max_X->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sB_max_X->setMinimum(-1000000);
        sB_max_X->setMaximum(1000000);

        gridLayout->addWidget(sB_max_X, 3, 0, 1, 1);

        sB_max_Y = new QSpinBox(widget1);
        sB_max_Y->setObjectName(QString::fromUtf8("sB_max_Y"));
        sB_max_Y->setFont(font);
        sB_max_Y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sB_max_Y->setMinimum(-1000000);
        sB_max_Y->setMaximum(1000000);

        gridLayout->addWidget(sB_max_Y, 3, 1, 1, 1);


        retranslateUi(Plot);

        QMetaObject::connectSlotsByName(Plot);
    } // setupUi

    void retranslateUi(QWidget *Plot)
    {
        Plot->setWindowTitle(QCoreApplication::translate("Plot", "Graph", nullptr));
        l_min_X->setText(QCoreApplication::translate("Plot", "min X", nullptr));
        l_min_Y->setText(QCoreApplication::translate("Plot", "min Y", nullptr));
        l_max_X->setText(QCoreApplication::translate("Plot", "max X", nullptr));
        l_max_Y->setText(QCoreApplication::translate("Plot", "max Y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Plot: public Ui_Plot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOT_H
