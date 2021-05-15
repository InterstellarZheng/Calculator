//������ջʵ��
/*
1.���ӻ�������ת��
2.�Զ�ɾ���ո񽫱��ʽת����Сд�������û���쳣�ַ�
3.��������Ƿ�ƥ��
1.�������������0
*/


/*��Ҫ��
* 1.��Ӵ���λ��
* 1.�����ֱ༭ģʽ��һ��matlabʽ��һ��ʵʱ����ģʽ
* 1.�����������������ȡ���һ��
* 2.��������Ҫ�����ţ����Ƿ�����λ
1.��������
3.��������
4.��������
5.�����ϴ�������
*/
#include <string>
#include <iostream>
#include "Calculator.h"


using namespace std;

// ʹ�ú��Operator����ע��
map<string, function<unique_ptr<Operator>()>> Factory::ms_operator; // ����洢ObjectCreator�ľ�̬map
map<string, function<unique_ptr<Operator>()>> Factory::ms_function; // ����洢ObjectCreator�ľ�̬map
REGISTRAROPR(Plus, "+");
REGISTRAROPR(Minus, "-");
REGISTRAROPR(Multiply, "*");
REGISTRAROPR(Divide, "/");
REGISTRAROPR(Lbra, "(");
REGISTRAROPR(Rbra, ")");
REGISTRAROPR(Equal, "=");
REGISTRAROPR(Power, "^");
REGISTRAROPR(Mod, "%");
REGISTRARFUN(Log, "log");
REGISTRARFUN(Ln, "ln");
REGISTRARFUN(Sin, "sin");
REGISTRARFUN(Cos, "cos");
REGISTRARFUN(Tan, "tan");
REGISTRARFUN(dtor, "dtor");
REGISTRARFUN(Sqrt, "sqrt");

int main() {
	string exp;
	while (getline(cin, exp)) {
		Calculator cclt;
		if (cclt.bracheck(exp) && cclt.check(exp) && cclt.del_space(exp)) {
			try {
				cout << cclt.doIt(exp) << endl;
			}
			catch (const char* str) {
				continue;
			}
		}
	}
	system("pause");
	return 0;
}

