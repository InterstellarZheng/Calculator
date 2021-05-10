#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<memory>
#include<string>
#include<cmath>
#include"Operator.h"
#include"OperatorFactory.h"
#include"Stack.h"


constexpr double PI = 3.14159265358979323846;
constexpr double e = 2.718281828459045;

class Calculator {
private:
	Stack<double> m_num;
	Stack<unique_ptr<Operator>> m_opr;
	Stack<unique_ptr<Operator>> m_cheopr;
	double readNum(string::const_iterator& it);
	bool isNum(string::const_iterator& it) {					//�ж��Ƿ�������
		return *it >= '0' && *it <= '9' || *it == '.';
	}
	string readStr(string::const_iterator& it);
	bool isStr(string::const_iterator& n) {						//�ж��Ƿ����ַ�
		return *n >= 'a' && *n <= 'z';
	}
	bool isOpe(string::const_iterator& it) {					//�ж��Ƿ��ǲ�����			
		for (auto is = Factory::ms_operator.begin(); is != Factory::ms_operator.end(); ++is) {
			string o;
			o.push_back(*it);
			if (is->first == o)
				return true;
		}
		return false;
	}
	void calculate();
public:
	Calculator() { m_opr.push(make_unique<Hash>()); m_cheopr.push(make_unique<Hash>()); }
	double doIt(const string& exp);
	bool del_space(string& exp);//ɾ���ո��Լ��ж������ַ��Ƿ�Ϸ�		
	bool check(string& exp);//����﷨�Ƿ�Ϸ�
};





#endif // !CALCULATOR_H
