/********************************************************************************
** Form generated from reading UI file 'calculator_sc.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_SC_H
#define UI_CALCULATOR_SC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calculator_sc
{
public:

    void setupUi(QWidget *calculator_sc)
    {
        if (calculator_sc->objectName().isEmpty())
            calculator_sc->setObjectName(QString::fromUtf8("calculator_sc"));
        calculator_sc->resize(994, 848);

        retranslateUi(calculator_sc);

        QMetaObject::connectSlotsByName(calculator_sc);
    } // setupUi

    void retranslateUi(QWidget *calculator_sc)
    {
        calculator_sc->setWindowTitle(QCoreApplication::translate("calculator_sc", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calculator_sc: public Ui_calculator_sc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_SC_H
