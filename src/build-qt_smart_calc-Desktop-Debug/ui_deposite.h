/********************************************************************************
** Form generated from reading UI file 'deposite.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITE_H
#define UI_DEPOSITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Deposite
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QRadioButton *rB_annuity;
    QRadioButton *rB_differentiated;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *l_deposit_amount;
    QDoubleSpinBox *dSB_credit_amount;
    QLabel *l_interest_rate;
    QDoubleSpinBox *dSB_interest_rate;
    QLabel *l_tax_rate;
    QDoubleSpinBox *dSB_interest_rate_2;
    QLabel *l_placement_period;
    QSpinBox *sB_placement_period;

    void setupUi(QWidget *Deposite)
    {
        if (Deposite->objectName().isEmpty())
            Deposite->setObjectName(QString::fromUtf8("Deposite"));
        Deposite->resize(530, 642);
        widget = new QWidget(Deposite);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(320, 10, 204, 101));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rB_annuity = new QRadioButton(widget);
        rB_annuity->setObjectName(QString::fromUtf8("rB_annuity"));
        QFont font;
        font.setFamily(QString::fromUtf8("Fira Code"));
        font.setPointSize(16);
        rB_annuity->setFont(font);

        verticalLayout->addWidget(rB_annuity);

        rB_differentiated = new QRadioButton(widget);
        rB_differentiated->setObjectName(QString::fromUtf8("rB_differentiated"));
        rB_differentiated->setFont(font);

        verticalLayout->addWidget(rB_differentiated);

        widget1 = new QWidget(Deposite);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 10, 298, 361));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        l_deposit_amount = new QLabel(widget1);
        l_deposit_amount->setObjectName(QString::fromUtf8("l_deposit_amount"));
        l_deposit_amount->setFont(font);

        verticalLayout_2->addWidget(l_deposit_amount);

        dSB_credit_amount = new QDoubleSpinBox(widget1);
        dSB_credit_amount->setObjectName(QString::fromUtf8("dSB_credit_amount"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Fira Code"));
        font1.setPointSize(24);
        dSB_credit_amount->setFont(font1);
        dSB_credit_amount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dSB_credit_amount->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSB_credit_amount->setMaximum(10000000000.000000000000000);

        verticalLayout_2->addWidget(dSB_credit_amount);

        l_interest_rate = new QLabel(widget1);
        l_interest_rate->setObjectName(QString::fromUtf8("l_interest_rate"));
        l_interest_rate->setFont(font);

        verticalLayout_2->addWidget(l_interest_rate);

        dSB_interest_rate = new QDoubleSpinBox(widget1);
        dSB_interest_rate->setObjectName(QString::fromUtf8("dSB_interest_rate"));
        dSB_interest_rate->setFont(font1);
        dSB_interest_rate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dSB_interest_rate->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSB_interest_rate->setMaximum(10000000000.000000000000000);

        verticalLayout_2->addWidget(dSB_interest_rate);

        l_tax_rate = new QLabel(widget1);
        l_tax_rate->setObjectName(QString::fromUtf8("l_tax_rate"));
        l_tax_rate->setFont(font);

        verticalLayout_2->addWidget(l_tax_rate);

        dSB_interest_rate_2 = new QDoubleSpinBox(widget1);
        dSB_interest_rate_2->setObjectName(QString::fromUtf8("dSB_interest_rate_2"));
        dSB_interest_rate_2->setFont(font1);
        dSB_interest_rate_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dSB_interest_rate_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSB_interest_rate_2->setMaximum(10000000000.000000000000000);

        verticalLayout_2->addWidget(dSB_interest_rate_2);

        l_placement_period = new QLabel(widget1);
        l_placement_period->setObjectName(QString::fromUtf8("l_placement_period"));
        l_placement_period->setFont(font);

        verticalLayout_2->addWidget(l_placement_period);

        sB_placement_period = new QSpinBox(widget1);
        sB_placement_period->setObjectName(QString::fromUtf8("sB_placement_period"));
        sB_placement_period->setFont(font1);
        sB_placement_period->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sB_placement_period->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sB_placement_period->setMinimum(1);
        sB_placement_period->setMaximum(36);

        verticalLayout_2->addWidget(sB_placement_period);


        retranslateUi(Deposite);

        QMetaObject::connectSlotsByName(Deposite);
    } // setupUi

    void retranslateUi(QWidget *Deposite)
    {
        Deposite->setWindowTitle(QCoreApplication::translate("Deposite", "Deposite", nullptr));
        rB_annuity->setText(QCoreApplication::translate("Deposite", "Annuity", nullptr));
        rB_differentiated->setText(QCoreApplication::translate("Deposite", "Differentiated", nullptr));
        l_deposit_amount->setText(QCoreApplication::translate("Deposite", "Deposit Amount", nullptr));
        dSB_credit_amount->setSpecialValueText(QString());
        l_interest_rate->setText(QCoreApplication::translate("Deposite", "Interest Rate", nullptr));
        l_tax_rate->setText(QCoreApplication::translate("Deposite", "Tax Rate", nullptr));
        l_placement_period->setText(QCoreApplication::translate("Deposite", "Placement Period", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Deposite: public Ui_Deposite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITE_H
