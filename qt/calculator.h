#ifndef CALCULATOR_H
#define CALCULATOR_H

#include<QWidget>

#include<memory>
#include<string>
#include<QString>
#include<cmath>
#include"Operator.h"
#include"OperatorFactory.h"
#include"Stack.h"

#include "calculator_sc.h"
#include "ui_calculator_sc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

constexpr double PI = 3.14159265358979323846;
constexpr double e = 2.718281828459045;
extern double ans;

class Calculator : public QWidget
{
    Q_OBJECT
private:
    QString Inputnum = "0";
    QString Inputexp;
    Stack<double> m_num;
    Stack<unique_ptr<Operator>> m_opr;
    Stack<unique_ptr<Operator>> m_cheopr;
    double readNum(string::const_iterator& it);
    bool isNum(string::const_iterator& it) {					//判断是否是数字
        return (*it >= '0' && *it <= '9') || *it == '.';
    }
    string readStr(string::const_iterator& it);
    bool isStr(string::const_iterator& n) {						//判断是否是字符
        return *n >= 'a' && *n <= 'z';
    }
    bool isOpr(string::const_iterator& it) {					//判断是否是操作符
        string o;
        o.push_back(*it);
        for (auto is = Factory::ms_operator.begin(); is != Factory::ms_operator.end(); ++is) {
            if (is->first == o)
                return true;
        }
        return false;
    }
    string readOpr(string::const_iterator& it);					//读取连续运算符的最后一位
    void calculate();
public:
    double doIt(const string& exp);
    bool del_space(string& exp);//删除空格以及判断输入字符是否合法
    bool bracheck(string& exp);//括号检测
    bool check(string& exp);//检查语法是否合法（连续输入多个运算符，运算符顺序违法
public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void on_Botton_0_clicked();

    void on_Botton_1_clicked();

    void on_Botton_2_clicked();

    void on_Botton_3_clicked();

    void on_Botton_4_clicked();

    void on_Botton_5_clicked();

    void on_Botton_6_clicked();

    void on_Botton_7_clicked();

    void on_Botton_8_clicked();

    void on_Botton_9_clicked();

    void on_Botton_point_clicked();

    void on_Botton_neg_pos_clicked();

    void on_Botton_equ_clicked();

    void on_Botton_plus_clicked();

    void on_Botton_minus_clicked();

    void on_Botton_multi_clicked();

    void on_Botton_division_clicked();

    void on_Botton_mod_clicked();

    void on_Botton_squar_clicked();

    void on_Botton_recip_clicked();

    void on_Botton_sqrt_clicked();

    void on_Botton_c_clicked();

    void on_Botton_ce_clicked();

    void on_Botton_del_clicked();

private:
    Ui::Calculator *ui;
    calculator_sc sc;
};

QString get_form(double);

#endif // CALCULATOR_H
