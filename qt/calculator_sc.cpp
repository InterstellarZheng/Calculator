#include "calculator_sc.h"
#include "ui_calculator_sc.h"

calculator_sc::calculator_sc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::calculator_sc)
{
    ui->setupUi(this);
}

calculator_sc::~calculator_sc()
{
    delete ui;
}
