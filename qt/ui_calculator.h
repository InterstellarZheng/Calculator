/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QLineEdit *expression;
    QLabel *label;
    QLabel *history;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *Botton_mod;
    QPushButton *Botton_ce;
    QPushButton *Botton_c;
    QPushButton *Botton_del;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *Botton_recip;
    QPushButton *Botton_squar;
    QPushButton *Botton_sqrt;
    QPushButton *Botton_division;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *Botton_7;
    QPushButton *Botton_8;
    QPushButton *Botton_9;
    QPushButton *Botton_multi;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Botton_4;
    QPushButton *Botton_5;
    QPushButton *Botton_6;
    QPushButton *Botton_minus;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Botton_1;
    QPushButton *Botton_2;
    QPushButton *Botton_3;
    QPushButton *Botton_plus;
    QHBoxLayout *horizontalLayout;
    QPushButton *Botton_neg_pos;
    QPushButton *Botton_0;
    QPushButton *Botton_point;
    QPushButton *Botton_equ;

    void setupUi(QWidget *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(1046, 923);
        Calculator->setStyleSheet(QString::fromUtf8("QWidget { background-color: rgb(237,237,237);}"));
        expression = new QLineEdit(Calculator);
        expression->setObjectName(QString::fromUtf8("expression"));
        expression->setGeometry(QRect(0, 50, 721, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        font.setPointSize(16);
        expression->setFont(font);
        expression->setFrame(false);
        expression->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(Calculator);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 140, 701, 111));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Calibri")});
        font1.setPointSize(24);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setFrameShadow(QFrame::Sunken);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        history = new QLabel(Calculator);
        history->setObjectName(QString::fromUtf8("history"));
        history->setGeometry(QRect(760, 130, 261, 771));
        history->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        widget = new QWidget(Calculator);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 280, 721, 644));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_6->setContentsMargins(-1, 0, -1, -1);
        Botton_mod = new QPushButton(widget);
        Botton_mod->setObjectName(QString::fromUtf8("Botton_mod"));
        Botton_mod->setMinimumSize(QSize(100, 100));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Cambria")});
        font2.setPointSize(24);
        font2.setBold(false);
        Botton_mod->setFont(font2);
        Botton_mod->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_mod->setFlat(true);

        horizontalLayout_6->addWidget(Botton_mod);

        Botton_ce = new QPushButton(widget);
        Botton_ce->setObjectName(QString::fromUtf8("Botton_ce"));
        Botton_ce->setMinimumSize(QSize(100, 100));
        Botton_ce->setSizeIncrement(QSize(0, 0));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Calibri")});
        font3.setPointSize(18);
        font3.setBold(false);
        Botton_ce->setFont(font3);
        Botton_ce->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_ce->setFlat(true);

        horizontalLayout_6->addWidget(Botton_ce);

        Botton_c = new QPushButton(widget);
        Botton_c->setObjectName(QString::fromUtf8("Botton_c"));
        Botton_c->setMinimumSize(QSize(100, 100));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Calibri")});
        font4.setPointSize(18);
        Botton_c->setFont(font4);
        Botton_c->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_c->setFlat(true);

        horizontalLayout_6->addWidget(Botton_c);

        Botton_del = new QPushButton(widget);
        Botton_del->setObjectName(QString::fromUtf8("Botton_del"));
        Botton_del->setMinimumSize(QSize(100, 100));
        Botton_del->setFont(font4);
        Botton_del->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(232,232,232); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_del->setFlat(true);

        horizontalLayout_6->addWidget(Botton_del);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        Botton_recip = new QPushButton(widget);
        Botton_recip->setObjectName(QString::fromUtf8("Botton_recip"));
        Botton_recip->setMinimumSize(QSize(100, 100));
        Botton_recip->setFont(font3);
        Botton_recip->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_recip->setFlat(true);

        horizontalLayout_5->addWidget(Botton_recip);

        Botton_squar = new QPushButton(widget);
        Botton_squar->setObjectName(QString::fromUtf8("Botton_squar"));
        Botton_squar->setMinimumSize(QSize(100, 100));
        Botton_squar->setSizeIncrement(QSize(0, 0));
        Botton_squar->setFont(font3);
        Botton_squar->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_squar->setFlat(true);

        horizontalLayout_5->addWidget(Botton_squar);

        Botton_sqrt = new QPushButton(widget);
        Botton_sqrt->setObjectName(QString::fromUtf8("Botton_sqrt"));
        Botton_sqrt->setMinimumSize(QSize(100, 100));
        Botton_sqrt->setFont(font4);
        Botton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_sqrt->setFlat(true);

        horizontalLayout_5->addWidget(Botton_sqrt);

        Botton_division = new QPushButton(widget);
        Botton_division->setObjectName(QString::fromUtf8("Botton_division"));
        Botton_division->setMinimumSize(QSize(100, 100));
        Botton_division->setFont(font1);
        Botton_division->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(232,232,232); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_division->setFlat(true);

        horizontalLayout_5->addWidget(Botton_division);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        Botton_7 = new QPushButton(widget);
        Botton_7->setObjectName(QString::fromUtf8("Botton_7"));
        Botton_7->setMinimumSize(QSize(100, 100));
        Botton_7->setFont(font2);
        Botton_7->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_7->setFlat(true);

        horizontalLayout_4->addWidget(Botton_7);

        Botton_8 = new QPushButton(widget);
        Botton_8->setObjectName(QString::fromUtf8("Botton_8"));
        Botton_8->setMinimumSize(QSize(100, 100));
        Botton_8->setSizeIncrement(QSize(0, 0));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Calibri")});
        font5.setPointSize(24);
        font5.setBold(false);
        Botton_8->setFont(font5);
        Botton_8->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_8->setFlat(true);

        horizontalLayout_4->addWidget(Botton_8);

        Botton_9 = new QPushButton(widget);
        Botton_9->setObjectName(QString::fromUtf8("Botton_9"));
        Botton_9->setMinimumSize(QSize(100, 100));
        Botton_9->setFont(font1);
        Botton_9->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_9->setFlat(true);

        horizontalLayout_4->addWidget(Botton_9);

        Botton_multi = new QPushButton(widget);
        Botton_multi->setObjectName(QString::fromUtf8("Botton_multi"));
        Botton_multi->setMinimumSize(QSize(100, 100));
        Botton_multi->setFont(font1);
        Botton_multi->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(232,232,232); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_multi->setFlat(true);

        horizontalLayout_4->addWidget(Botton_multi);


        gridLayout->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        Botton_4 = new QPushButton(widget);
        Botton_4->setObjectName(QString::fromUtf8("Botton_4"));
        Botton_4->setMinimumSize(QSize(100, 100));
        Botton_4->setFont(font2);
        Botton_4->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_4->setFlat(true);

        horizontalLayout_3->addWidget(Botton_4);

        Botton_5 = new QPushButton(widget);
        Botton_5->setObjectName(QString::fromUtf8("Botton_5"));
        Botton_5->setMinimumSize(QSize(100, 100));
        Botton_5->setSizeIncrement(QSize(0, 0));
        Botton_5->setFont(font5);
        Botton_5->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_5->setFlat(true);

        horizontalLayout_3->addWidget(Botton_5);

        Botton_6 = new QPushButton(widget);
        Botton_6->setObjectName(QString::fromUtf8("Botton_6"));
        Botton_6->setMinimumSize(QSize(100, 100));
        Botton_6->setFont(font1);
        Botton_6->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_6->setFlat(true);

        horizontalLayout_3->addWidget(Botton_6);

        Botton_minus = new QPushButton(widget);
        Botton_minus->setObjectName(QString::fromUtf8("Botton_minus"));
        Botton_minus->setMinimumSize(QSize(100, 100));
        Botton_minus->setFont(font1);
        Botton_minus->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(232,232,232); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_minus->setFlat(true);

        horizontalLayout_3->addWidget(Botton_minus);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        Botton_1 = new QPushButton(widget);
        Botton_1->setObjectName(QString::fromUtf8("Botton_1"));
        Botton_1->setMinimumSize(QSize(100, 100));
        Botton_1->setFont(font2);
        Botton_1->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_1->setFlat(true);

        horizontalLayout_2->addWidget(Botton_1);

        Botton_2 = new QPushButton(widget);
        Botton_2->setObjectName(QString::fromUtf8("Botton_2"));
        Botton_2->setMinimumSize(QSize(100, 100));
        Botton_2->setSizeIncrement(QSize(0, 0));
        Botton_2->setFont(font5);
        Botton_2->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_2->setFlat(true);

        horizontalLayout_2->addWidget(Botton_2);

        Botton_3 = new QPushButton(widget);
        Botton_3->setObjectName(QString::fromUtf8("Botton_3"));
        Botton_3->setMinimumSize(QSize(100, 100));
        Botton_3->setFont(font1);
        Botton_3->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_3->setFlat(true);

        horizontalLayout_2->addWidget(Botton_3);

        Botton_plus = new QPushButton(widget);
        Botton_plus->setObjectName(QString::fromUtf8("Botton_plus"));
        Botton_plus->setMinimumSize(QSize(100, 100));
        Botton_plus->setFont(font1);
        Botton_plus->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(232,232,232); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_plus->setFlat(true);

        horizontalLayout_2->addWidget(Botton_plus);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        Botton_neg_pos = new QPushButton(widget);
        Botton_neg_pos->setObjectName(QString::fromUtf8("Botton_neg_pos"));
        Botton_neg_pos->setMinimumSize(QSize(100, 100));
        Botton_neg_pos->setFont(font2);
        Botton_neg_pos->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_neg_pos->setFlat(true);

        horizontalLayout->addWidget(Botton_neg_pos);

        Botton_0 = new QPushButton(widget);
        Botton_0->setObjectName(QString::fromUtf8("Botton_0"));
        Botton_0->setMinimumSize(QSize(100, 100));
        Botton_0->setSizeIncrement(QSize(0, 0));
        Botton_0->setFont(font5);
        Botton_0->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_0->setFlat(true);

        horizontalLayout->addWidget(Botton_0);

        Botton_point = new QPushButton(widget);
        Botton_point->setObjectName(QString::fromUtf8("Botton_point"));
        Botton_point->setMinimumSize(QSize(100, 100));
        Botton_point->setFont(font1);
        Botton_point->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(255, 255, 255); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(181, 181, 181); }"));
        Botton_point->setFlat(true);

        horizontalLayout->addWidget(Botton_point);

        Botton_equ = new QPushButton(widget);
        Botton_equ->setObjectName(QString::fromUtf8("Botton_equ"));
        Botton_equ->setMinimumSize(QSize(100, 100));
        Botton_equ->setFont(font1);
        Botton_equ->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(177, 225, 231); border-radius: 1px; color: rgb(0, 0, 0); color:black} QPushButton:hover { background-color: rgb(124, 224, 236); }"));
        Botton_equ->setFlat(true);

        horizontalLayout->addWidget(Botton_equ);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);


        retranslateUi(Calculator);

        Botton_ce->setDefault(false);
        Botton_c->setDefault(false);
        Botton_squar->setDefault(false);
        Botton_sqrt->setDefault(false);
        Botton_8->setDefault(false);
        Botton_9->setDefault(false);
        Botton_5->setDefault(false);
        Botton_6->setDefault(false);
        Botton_2->setDefault(false);
        Botton_3->setDefault(false);
        Botton_0->setDefault(false);
        Botton_point->setDefault(false);


        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QWidget *Calculator)
    {
        Calculator->setWindowTitle(QCoreApplication::translate("Calculator", "Calculator", nullptr));
        label->setText(QString());
        history->setText(QCoreApplication::translate("Calculator", "TextLabel", nullptr));
        Botton_mod->setText(QCoreApplication::translate("Calculator", "%", nullptr));
        Botton_ce->setText(QCoreApplication::translate("Calculator", "CE", nullptr));
        Botton_c->setText(QCoreApplication::translate("Calculator", "C", nullptr));
        Botton_del->setText(QCoreApplication::translate("Calculator", "DEL", nullptr));
        Botton_recip->setText(QCoreApplication::translate("Calculator", "1/x", nullptr));
        Botton_squar->setText(QCoreApplication::translate("Calculator", "x^2", nullptr));
        Botton_sqrt->setText(QCoreApplication::translate("Calculator", "sqrt(x)", nullptr));
        Botton_division->setText(QCoreApplication::translate("Calculator", "/", nullptr));
        Botton_7->setText(QCoreApplication::translate("Calculator", "7", nullptr));
        Botton_8->setText(QCoreApplication::translate("Calculator", "8", nullptr));
        Botton_9->setText(QCoreApplication::translate("Calculator", "9", nullptr));
        Botton_multi->setText(QCoreApplication::translate("Calculator", "*", nullptr));
        Botton_4->setText(QCoreApplication::translate("Calculator", "4", nullptr));
        Botton_5->setText(QCoreApplication::translate("Calculator", "5", nullptr));
        Botton_6->setText(QCoreApplication::translate("Calculator", "6", nullptr));
        Botton_minus->setText(QCoreApplication::translate("Calculator", "-", nullptr));
        Botton_1->setText(QCoreApplication::translate("Calculator", "1", nullptr));
        Botton_2->setText(QCoreApplication::translate("Calculator", "2", nullptr));
        Botton_3->setText(QCoreApplication::translate("Calculator", "3", nullptr));
        Botton_plus->setText(QCoreApplication::translate("Calculator", "+", nullptr));
        Botton_neg_pos->setText(QCoreApplication::translate("Calculator", "+/-", nullptr));
        Botton_0->setText(QCoreApplication::translate("Calculator", "0", nullptr));
        Botton_point->setText(QCoreApplication::translate("Calculator", ".", nullptr));
        Botton_equ->setText(QCoreApplication::translate("Calculator", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
