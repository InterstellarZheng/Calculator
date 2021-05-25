#ifndef CALCULATOR_SC_H
#define CALCULATOR_SC_H

#include <QWidget>

namespace Ui {
class calculator_sc;
}

class calculator_sc : public QWidget
{
    Q_OBJECT

public:
    explicit calculator_sc(QWidget *parent = nullptr);
    ~calculator_sc();

protected:
    Ui::calculator_sc *ui;

};

#endif // CALCULATOR_SC_H
