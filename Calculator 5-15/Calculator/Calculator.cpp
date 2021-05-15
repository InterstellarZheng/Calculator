#include"Calculator.h"
using namespace std;

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
	for (auto it = exp.begin(); it != exp.end();) {
		bool is_negative = 0;			//零表示不是负数存入数堆栈
		bool is_con_ope = 0;			//零表示无连续操作符
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
				//if (oo->symbol() == "-" && m_opr.top()->symbol() == "#" )




				auto oo = Factory::create_opr(o);
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
			//else {
			//	//???????????
			//	//做一个啥也不是的报错
			//}
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

