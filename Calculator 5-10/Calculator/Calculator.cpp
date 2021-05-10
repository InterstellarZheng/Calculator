#include"Calculator.h"
using namespace std;

double Calculator::readNum(string::const_iterator& it) {
	string t;
	while (isNum(it)) {
		t += *it++;
	}
	return stod(t);
}

string Calculator::readStr(string::const_iterator& it) {
	string t;
	while (isStr(it)) {
		t += *it++;
	}
	return t;
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
	for (auto it = exp.begin(); it != exp.end();) {
		if (isNum(it))
			m_num.push(readNum(it));
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
				else{
					try {
						auto oo = Factory::create(f);
					}
					catch (const char* str) {
						cerr << str << endl;
						throw "Error: undefined behaviors!";
					}
					m_opr.push(std::move(oo));
				}
					
			}
			else {
				string o;
				o.push_back(*it++);
				try {
					auto oo = Factory::create(o);
				}
				catch (const char* str) {
					cerr << str << endl;
					throw "Error: undefined behaviors!";
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
		}
	}
	double result = m_num.top();
	if (result < 1.0e-8 && result >-1.0e-8)
		result = 0;
	m_num.pop();
	return result;
}

bool Calculator::del_space(string& exp)				//自动删除空格并检查异常字符
{
	string res;
	for (auto it = exp.begin(); it != exp.end(); ++it) {
		if (isStr(it) || isNum(it) || isOpe(it))
			res += *it;
		else if (*it == ' ') {}
		else {
			cout << "Warning:Unusual character!" << endl;
			return false;
		}
	}
	exp = res;
	return true;
}

bool Calculator::check(string& exp) {//需要修改
	for (auto it = exp.begin(); it != exp.end(); ++it) {
		char o = *it;
		unique_ptr<Operator>oo;
		if (o == '(') {
			oo = make_unique<Lbra>();
			m_cheopr.push(std::move(oo));
		}
		else if (o == ')'&& m_cheopr.top()->symbol() == "(") {
			m_cheopr.pop();
		}
		else if (o == ')' && m_cheopr.top()->symbol() == ")") {
			cout << "Warning:Missing left bracket!" << endl;
			return 0;
		}
		else if (o == ')' && m_cheopr.top()->symbol() == "#") {
			cout << "Warning:Missing left bracket!" << endl;
			return 0;
		}
	}
	if (m_cheopr.top()->symbol() == "(") {
		cout << "Warning:Missing right bracket!" << endl;
		return 0;
	}
	else
		return (m_cheopr.top()->symbol() == "#");
}
