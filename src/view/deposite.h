#ifndef DEPOSITE_H
#define DEPOSITE_H

#include <QWidget>

namespace Ui {
class Deposite;
}

class Deposite : public QWidget
{
    Q_OBJECT

public:
    explicit Deposite(QWidget *parent = nullptr);
    ~Deposite();

private:
    Ui::Deposite *ui;
};

#endif // DEPOSITE_H
