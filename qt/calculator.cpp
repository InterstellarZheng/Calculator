#include "calculator.h"
#include<QString>
#include "ui_calculator.h"
#include<typeinfo>

using namespace std;
bool clicknum = 1; //0代表上一次点击为操作符，
bool afequ_num = 0; //0代表为用等号处理

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    ui->label->setText(Inputnum);
    m_opr.push(make_unique<Hash>());
    m_cheopr.push(make_unique<Hash>());
}

Calculator::~Calculator()
{
    delete ui;
}

double Calculator::readNum(string::const_iterator& it) {
    string t;
    while (isNum(it)) {
        t.push_back(*it++);
    }
    return stod(t);
}

string Calculator::readStr(string::const_iterator& it) {
    string t;
    while (isStr(it)) {
        t.push_back(*it++);
    }
    return t;
}

string Calculator::readOpr(string::const_iterator& it) {
    string oo;
    while (isOpr(it)) {
        if (*it != '=')
            oo.push_back(*it++);
        else
            break;
    }
    return oo;
}

void Calculator::calculate() {			//添加异常处理
    double a[2] = { 0 };
    for (auto i = 0; i < m_opr.top()->numOprand(); ++i) {
        a[i] = m_num.top();
        m_num.pop();
    }
    try {
        m_num.push(m_opr.top()->get(a[1], a[0]));
    }
    catch (const char* str) {
        cerr << str << endl;
        throw "Error:syntax errors!";
    }
    m_opr.pop();
}

double Calculator::doIt(const string& exp) {
    bool is_negative = 0;			//1表示下一个数是负数存入数堆栈
    for (auto it = exp.begin(); it != exp.end();) {
        if (isNum(it)){
            if (is_negative == 1) {
                m_num.push((-1) * readNum(it));
                is_negative = 0;
            }
            else
                m_num.push(readNum(it));
        }
        else {
            unique_ptr<Operator> oo;
            if (isStr(it)) {
                string f = readStr(it);
                if (f == "pi") {
                    m_num.push(PI);
                }
                else if (f == "e") {
                    m_num.push(e);
                }
                else if (f == "ans") {
                    m_num.push(ans);
                }
                else{
                    try {
                        auto oo = Factory::create_fun(f);
                    }
                    catch (const char* str) {
                        cerr << str << endl;
                        throw "Error: undefined behaviors!";
                    }
                    auto oo = Factory::create_fun(f);
                    m_opr.push(std::move(oo));
                }

            }
            else if (isOpr(it)) {
                string o;
                o.push_back(*it++);
                try {
                    auto oo = Factory::create_opr(o);
                }
                catch (const char* str) {
                    cerr << str << endl;
                    throw "Error: undefined behaviors!";
                }
                auto oo = Factory::create_opr(o);
                if ((oo->symbol() == "-" && m_opr.top()->symbol() == "#") ||
                    (oo->symbol() == "-" && m_opr.top()->symbol() == "(")) {
                    is_negative = 1;
                    continue;
                }

                while (oo->precedence() <= m_opr.top()->precedence()) {
                    if (m_opr.top()->symbol() == "#" || m_opr.top()->symbol() == "(")
                        break;
                    try {
                        calculate();
                    }
                    catch (const char* str) {								//跳出错误时需要对数据栈，操作符栈进行清空
                        throw "Error:syntax errors!";
                    }
                }
                if (oo->symbol() == ")" && m_opr.top()->symbol() == "(") {
                    m_opr.pop();
                }
                if (oo->symbol() != "=" && oo->symbol() != ")")//右括号不进栈
                    m_opr.push(std::move(oo));
            }
            else {
                throw "Error: undefined behaviors!";
            }
        }
    }
    double result = m_num.top();
    m_num.pop();
    //if (result < 1.0e-8 && result >-1.0e-8)
        //result = 0;
    return result;
}

bool Calculator::del_space(string& exp)				//自动删除空格并检查异常字符
{
    string res;
    for (auto it = exp.begin(); it != exp.end(); ++it) {
        if (isStr(it) || isNum(it) || isOpr(it))
            res += *it;
        else if (*it == ' ') {}
        else {
            try {
                throw "Error:Unusual character!";
            }
            catch (const char* str) {
                cerr << str << endl;
                return false;
            }
        }
    }
    exp = res;
    return true;
}

bool Calculator::bracheck(string& exp) {//需要修改
    for (auto it = exp.begin(); it != exp.end(); ++it) {
        char o = *it;
        unique_ptr<Operator>oo;
        if (o == '(') {
            oo = make_unique<Lbra>();
            m_cheopr.push(std::move(oo));
        }
        else if (o == ')' && m_cheopr.top()->symbol() == "(") {
            m_cheopr.pop();
        }
        else if (o == ')' && m_cheopr.top()->symbol() == ")") {
            try {
                throw "Error:Missing left bracket!";
            }
            catch (const char* str) {
                cerr << str << endl;
                return false;
            }
        }
        else if (o == ')' && m_cheopr.top()->symbol() == "#") {
            try {
                throw "Error:Missing left bracket!";
            }
            catch (const char* str) {
                cerr << str << endl;
                return false;
            }
        }
    }
    if (m_cheopr.top()->symbol() == "(") {
        try {
            throw "Error:Missing right bracket!";
        }
        catch (const char* str) {
            cerr << str << endl;
            return false;
        }
    }
    else
        return (m_cheopr.top()->symbol() == "#");
}

bool Calculator::check(string& exp) {			//语法检测函数，适用于编程模式(多个运算符一起）
    bool isvalid = 1;
    for (auto it = exp.begin(); it != exp.end(); ) {
        if (isOpr(it)) {
            string o = readOpr(it);
            int length = o.size();
            unique_ptr<Operator>oo;
            if (length == 2) {
                if (o.at(1) == '(')
                    continue;
                else if (o == "(-")
                    continue;
                else {
                    isvalid = 0;
                    break;
                }
            }
            else if (length == 3) {
                if (o.at(1) == '(' && o.at(2) == '-')
                    continue;
                else {
                    isvalid = 0;
                    break;
                }
            }
            else if (length > 3)
            {
                isvalid = 0;
                break;
            }
            if (*it == '=')
                it++;
        }
        else
            it++;
    }
    if (isvalid == 0) {
        try {
            throw "Error:syntax errors!";
        }
        catch (const char* str) {
            cerr << str << endl;
            return false;
        }
    }
    return isvalid;
}

QString get_form(double result){
    QString rhs;
    int inresult = int(result);
    double temp =inresult-result;
    if(abs(temp)<1.0e-6){
        result = int(result);
        rhs = QString::number(result,10,0);
    }
    else{
        rhs = QString::number(result,10,4);
    }
    return rhs;
}

void Calculator::on_Botton_0_clicked()
{
    if(afequ_num == 1){
        ui->expression->setText(Inputexp);
        afequ_num = 0;
    }
    QString temp= "0";
    if(Inputnum == "0"){
        ui->label->setText(temp);
    }
    else{
        Inputnum+=temp;
        ui->label->setText(Inputnum);
    }
}


void Calculator::on_Botton_1_clicked()
{
    if(afequ_num == 1){
        ui->expression->setText(Inputexp);
        afequ_num = 0;
    }
    QString temp= "1";
    if(Inputnum == "0"){
        Inputnum = temp;
        ui->label->setText(Inputnum);
    }
    else{
        Inputnum+=temp;
        ui->label->setText(Inputnum);
    }
}


void Calculator::on_Botton_2_clicked()
{
    if(afequ_num == 1){
        ui->expression->setText(Inputexp);
        afequ_num = 0;
    }
    QString temp= "2";
    if(Inputnum == "0"){
        Inputnum = temp;
        ui->label->setText(Inputnum);
    }
    else{
        Inputnum+=temp;
        ui->label->setText(Inputnum);
    }
}


void Calculator::on_Botton_3_clicked()
{
    if(afequ_num == 1){
        ui->expression->setText(Inputexp);
        afequ_num = 0;
    }
    QString temp= "3";
    if(Inputnum == "0"){
        Inputnum = temp;
        ui->label->setText(Inputnum);
    }
    else{
        Inputnum+=temp;
        ui->label->setText(Inputnum);
    }
}


void Calculator::on_Botton_4_clicked()
{
    if(afequ_num == 1){
        ui->expression->setText(Inputexp);
        afequ_num = 0;
    }
    QString temp= "4";
    if(Inputnum == "0"){
        Inputnum = temp;
        ui->label->setText(Inputnum);
    }
    else{
        Inputnum+=temp;
        ui->label->setText(Inputnum);
    }
}


void Calculator::on_Botton_5_clicked()
{
    if(afequ_num == 1){
        ui->expression->setText(Inputexp);
        afequ_num = 0;
    }
    QString temp= "5";
    if(Inputnum == "0"){
        Inputnum = temp;
        ui->label->setText(Inputnum);
    }
    else{
        Inputnum+=temp;
        ui->label->setText(Inputnum);
    }
}


void Calculator::on_Botton_6_clicked()
{
    if(afequ_num == 1){
        ui->expression->setText(Inputexp);
        afequ_num = 0;
    }
    QString temp= "6";
    if(Inputnum == "0"){
        Inputnum = temp;
        ui->label->setText(Inputnum);
    }
    else{
        Inputnum+=temp;
        ui->label->setText(Inputnum);
    }
}


void Calculator::on_Botton_7_clicked()
{
    if(afequ_num == 1){
        ui->expression->setText(Inputexp);
        afequ_num = 0;
    }
    QString temp= "7";
    if(Inputnum == "0"){
        Inputnum = temp;
        ui->label->setText(Inputnum);
    }
    else{
        Inputnum+=temp;
        ui->label->setText(Inputnum);
    }
}


void Calculator::on_Botton_8_clicked()
{
    if(afequ_num == 1){
        ui->expression->setText(Inputexp);
        afequ_num = 0;
    }
    QString temp= "8";
    if(Inputnum == "0"){
        Inputnum = temp;
        ui->label->setText(Inputnum);
    }
    else{
        Inputnum+=temp;
        ui->label->setText(Inputnum);
    }
}


void Calculator::on_Botton_9_clicked()
{
    if(afequ_num == 1){
        ui->expression->setText(Inputexp);
        afequ_num = 0;
    }
    QString temp= "9";
    if(Inputnum == "0"){
        Inputnum = temp;
        ui->label->setText(Inputnum);
    }
    else{
        Inputnum+=temp;
        ui->label->setText(Inputnum);
    }
}


void Calculator::on_Botton_point_clicked()
{
    QString temp;
    if(afequ_num == 1){
        ui->expression->setText(Inputexp);
        afequ_num = 0;
    }
    if(Inputnum.isEmpty()==1)
        temp= "0.";
    else
        temp= ".";
    Inputnum+=temp;
    ui->label->setText(Inputnum);
}


void Calculator::on_Botton_neg_pos_clicked()
{
    QString rhs;
    if(Inputnum == "0"){
        ui->label->setText(Inputnum);
    }
    else{
        string inputnum = Inputnum.toStdString();
        string::iterator it = inputnum.begin();
        double number = stod(inputnum);
        if(number<0){
            inputnum.erase(it);
            rhs = QString::fromStdString(inputnum);
            Inputnum = rhs;
        }
        else{
            inputnum = "-"+inputnum;
            rhs = QString::fromStdString(inputnum);
            Inputnum = QString::fromStdString(inputnum);
            Inputnum = "("+Inputnum+")";
        }
        ui->label->setText(rhs);
    }
}


void Calculator::on_Botton_equ_clicked()
{
    Inputexp += Inputnum;
    Inputexp+="=";
    ui->expression->setText(Inputexp);
    string inputexp = Inputexp.toStdString();
    ans = doIt(inputexp);
    Inputnum = get_form(ans);
    ui->label->setText(Inputnum);
    Inputexp = QString();
    afequ_num = 1;
    Inputnum = QString();
}


void Calculator::on_Botton_plus_clicked()
{
    Inputexp+=Inputnum; //将最新的数存入表达式
    Inputexp += "=";    //完整表达式用于下一步计算
    string inputexp = Inputexp.toStdString();
    ans = doIt(inputexp);
    Inputnum = get_form(ans);
    ui->label->setText(Inputnum);
    Inputnum+="+";     //根据不同运算符进行计算
    Inputexp = Inputnum;
    ui->expression->setText(Inputexp);
    Inputnum = QString();
}


void Calculator::on_Botton_minus_clicked()
{
    Inputexp+=Inputnum; //将最新的数存入表达式
    Inputexp += "=";    //完整表达式用于下一步计算
    string inputexp = Inputexp.toStdString();
    ans = doIt(inputexp);
    Inputnum = get_form(ans);
    ui->label->setText(Inputnum);
    Inputnum+="-";     //根据不同运算符进行计算
    Inputexp = Inputnum;
    ui->expression->setText(Inputexp);
    Inputnum = QString();
}


void Calculator::on_Botton_multi_clicked()
{
    Inputexp+=Inputnum; //将最新的数存入表达式
    Inputexp += "=";    //完整表达式用于下一步计算
    string inputexp = Inputexp.toStdString();
    ans = doIt(inputexp);
    Inputnum = get_form(ans);
    ui->label->setText(Inputnum);
    Inputnum+="*";     //根据不同运算符进行计算
    Inputexp = Inputnum;
    ui->expression->setText(Inputexp);
    Inputnum = QString();
}


void Calculator::on_Botton_division_clicked()
{
    Inputexp+=Inputnum; //将最新的数存入表达式
    Inputexp += "=";    //完整表达式用于下一步计算
    string inputexp = Inputexp.toStdString();
    ans = doIt(inputexp);
    Inputnum = get_form(ans);
    ui->label->setText(Inputnum);
    Inputnum+="/";     //根据不同运算符进行计算
    Inputexp = Inputnum;
    ui->expression->setText(Inputexp);
    Inputnum = QString();
}


void Calculator::on_Botton_mod_clicked()
{
    Inputexp+=Inputnum; //将最新的数存入表达式
    Inputexp += "=";    //完整表达式用于下一步计算
    string inputexp = Inputexp.toStdString();
    ans = doIt(inputexp);
    Inputnum = get_form(ans);
    ui->label->setText(Inputnum);
    Inputnum+="%";     //根据不同运算符进行计算
    Inputexp = Inputnum;
    ui->expression->setText(Inputexp);
    Inputnum = QString();
}


void Calculator::on_Botton_squar_clicked()  //是一种不存入ans的操作
{
    string inputnum = Inputnum.toStdString();
    double number = stod(inputnum);
    number = pow(number,2);
    Inputnum = get_form(number);
    ui->label->setText(Inputnum);
    Inputnum = "("+QString::fromStdString(inputnum)+"^2)";
    Inputexp += Inputnum;
    ui->expression->setText(Inputexp);
    Inputnum = QString();
    afequ_num = 1;
}


void Calculator::on_Botton_recip_clicked()
{
    string inputnum = Inputnum.toStdString();
    double number = stod(inputnum);
    number = 1/number;
    Inputnum = get_form(number);
    ui->label->setText(Inputnum);
    Inputnum = "(1/"+QString::fromStdString(inputnum);
    Inputexp += Inputnum;
    ui->expression->setText(Inputexp);
    Inputnum = QString();
    afequ_num = 1;
}


void Calculator::on_Botton_sqrt_clicked()
{
    string inputnum = Inputnum.toStdString();
    double number = stod(inputnum);
    number = sqrt(number);
    Inputnum = get_form(number);
    ui->label->setText(Inputnum);
    Inputnum = "sqrt("+QString::fromStdString(inputnum)+")";
    Inputexp += Inputnum;
    ui->expression->setText(Inputexp);
    Inputnum = QString();
    afequ_num = 1;
}


void Calculator::on_Botton_c_clicked()
{
    ans = 0;
    Inputnum = "0";
    Inputexp = QString();
    ui->expression->setText(Inputexp);
    ui->label->setText(Inputnum);
}


void Calculator::on_Botton_ce_clicked()
{
    Inputnum = "0";
    ui->label->setText(Inputnum);
}


void Calculator::on_Botton_del_clicked()
{
    Inputnum = Inputnum.left(Inputnum.length() - 1);
    if(Inputnum.isEmpty())
        Inputnum = "0";
    ui->label->setText(Inputnum);
}

