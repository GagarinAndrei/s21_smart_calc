/********************************************************************************
** Form generated from reading UI file 'credit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_H
#define UI_CREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Credit
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rB_annuity;
    QRadioButton *rB_differentiated;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *l_credit_amount;
    QDoubleSpinBox *dSB_credit_amount;
    QLabel *l_interest_rate;
    QDoubleSpinBox *dSB_interest_rate;
    QLabel *l_credit_term;
    QSpinBox *sB_credit_term;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *l_interest_charges;
    QDoubleSpinBox *dSB_interest_charges;
    QLabel *l_monthly_payments;
    QDoubleSpinBox *dSB_monthly_payments;
    QLabel *l_total_payout;
    QDoubleSpinBox *dSB_total_payout;

    void setupUi(QWidget *Credit)
    {
        if (Credit->objectName().isEmpty())
            Credit->setObjectName(QString::fromUtf8("Credit"));
        Credit->resize(631, 429);
        layoutWidget = new QWidget(Credit);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 380, 611, 36));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(8, 0, 0, 0);
        rB_annuity = new QRadioButton(layoutWidget);
        rB_annuity->setObjectName(QString::fromUtf8("rB_annuity"));
        QFont font;
        font.setFamily(QString::fromUtf8("Fira Code"));
        font.setPointSize(16);
        rB_annuity->setFont(font);
        rB_annuity->setChecked(true);

        horizontalLayout->addWidget(rB_annuity);

        rB_differentiated = new QRadioButton(layoutWidget);
        rB_differentiated->setObjectName(QString::fromUtf8("rB_differentiated"));
        rB_differentiated->setFont(font);

        horizontalLayout->addWidget(rB_differentiated);

        layoutWidget_2 = new QWidget(Credit);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 10, 298, 341));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        l_credit_amount = new QLabel(layoutWidget_2);
        l_credit_amount->setObjectName(QString::fromUtf8("l_credit_amount"));
        l_credit_amount->setFont(font);

        verticalLayout_2->addWidget(l_credit_amount);

        dSB_credit_amount = new QDoubleSpinBox(layoutWidget_2);
        dSB_credit_amount->setObjectName(QString::fromUtf8("dSB_credit_amount"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Fira Code"));
        font1.setPointSize(24);
        dSB_credit_amount->setFont(font1);
        dSB_credit_amount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dSB_credit_amount->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSB_credit_amount->setMaximum(10000000000.000000000000000);

        verticalLayout_2->addWidget(dSB_credit_amount);

        l_interest_rate = new QLabel(layoutWidget_2);
        l_interest_rate->setObjectName(QString::fromUtf8("l_interest_rate"));
        l_interest_rate->setFont(font);

        verticalLayout_2->addWidget(l_interest_rate);

        dSB_interest_rate = new QDoubleSpinBox(layoutWidget_2);
        dSB_interest_rate->setObjectName(QString::fromUtf8("dSB_interest_rate"));
        dSB_interest_rate->setFont(font1);
        dSB_interest_rate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dSB_interest_rate->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSB_interest_rate->setMaximum(10000000000.000000000000000);

        verticalLayout_2->addWidget(dSB_interest_rate);

        l_credit_term = new QLabel(layoutWidget_2);
        l_credit_term->setObjectName(QString::fromUtf8("l_credit_term"));
        l_credit_term->setFont(font);

        verticalLayout_2->addWidget(l_credit_term);

        sB_credit_term = new QSpinBox(layoutWidget_2);
        sB_credit_term->setObjectName(QString::fromUtf8("sB_credit_term"));
        sB_credit_term->setFont(font1);
        sB_credit_term->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(sB_credit_term);

        layoutWidget_3 = new QWidget(Credit);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(320, 10, 298, 341));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        l_interest_charges = new QLabel(layoutWidget_3);
        l_interest_charges->setObjectName(QString::fromUtf8("l_interest_charges"));
        l_interest_charges->setFont(font);

        verticalLayout_3->addWidget(l_interest_charges);

        dSB_interest_charges = new QDoubleSpinBox(layoutWidget_3);
        dSB_interest_charges->setObjectName(QString::fromUtf8("dSB_interest_charges"));
        dSB_interest_charges->setFont(font1);
        dSB_interest_charges->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dSB_interest_charges->setReadOnly(true);
        dSB_interest_charges->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSB_interest_charges->setMaximum(10000000000.000000000000000);

        verticalLayout_3->addWidget(dSB_interest_charges);

        l_monthly_payments = new QLabel(layoutWidget_3);
        l_monthly_payments->setObjectName(QString::fromUtf8("l_monthly_payments"));
        l_monthly_payments->setFont(font);

        verticalLayout_3->addWidget(l_monthly_payments);

        dSB_monthly_payments = new QDoubleSpinBox(layoutWidget_3);
        dSB_monthly_payments->setObjectName(QString::fromUtf8("dSB_monthly_payments"));
        dSB_monthly_payments->setFont(font1);
        dSB_monthly_payments->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dSB_monthly_payments->setReadOnly(true);
        dSB_monthly_payments->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSB_monthly_payments->setMaximum(10000000000.000000000000000);

        verticalLayout_3->addWidget(dSB_monthly_payments);

        l_total_payout = new QLabel(layoutWidget_3);
        l_total_payout->setObjectName(QString::fromUtf8("l_total_payout"));
        l_total_payout->setFont(font);

        verticalLayout_3->addWidget(l_total_payout);

        dSB_total_payout = new QDoubleSpinBox(layoutWidget_3);
        dSB_total_payout->setObjectName(QString::fromUtf8("dSB_total_payout"));
        dSB_total_payout->setFont(font1);
        dSB_total_payout->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dSB_total_payout->setReadOnly(true);
        dSB_total_payout->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSB_total_payout->setMaximum(10000000000.000000000000000);

        verticalLayout_3->addWidget(dSB_total_payout);


        retranslateUi(Credit);

        QMetaObject::connectSlotsByName(Credit);
    } // setupUi

    void retranslateUi(QWidget *Credit)
    {
        Credit->setWindowTitle(QCoreApplication::translate("Credit", "Credit", nullptr));
        rB_annuity->setText(QCoreApplication::translate("Credit", "Annuity", nullptr));
        rB_differentiated->setText(QCoreApplication::translate("Credit", "Differentiated", nullptr));
        l_credit_amount->setText(QCoreApplication::translate("Credit", "Credit Amount", nullptr));
        dSB_credit_amount->setSpecialValueText(QString());
        l_interest_rate->setText(QCoreApplication::translate("Credit", "Interest Rate", nullptr));
        l_credit_term->setText(QCoreApplication::translate("Credit", "Credit Term", nullptr));
        l_interest_charges->setText(QCoreApplication::translate("Credit", "Interest Charges", nullptr));
        dSB_interest_charges->setSpecialValueText(QString());
        l_monthly_payments->setText(QCoreApplication::translate("Credit", "Monthly Payments", nullptr));
        l_total_payout->setText(QCoreApplication::translate("Credit", "Total Payout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Credit: public Ui_Credit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_H
