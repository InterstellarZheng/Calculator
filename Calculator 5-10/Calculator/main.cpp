//������ջʵ��
/*
1.���ӻ�������ת��
2.�Զ�ɾ���ո񽫱��ʽת����Сд�������û���쳣�ַ�
3.��������Ƿ�ƥ��
1.�������������0
*/


/*��Ҫ��
* 
* 
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
REGISTRAR(Plus, "+");
REGISTRAR(Minus, "-");
REGISTRAR(Multiply, "*");
REGISTRAR(Divide, "/");
REGISTRAR(Lbra, "(");
REGISTRAR(Rbra, ")");
REGISTRAR(Equal, "=");
REGISTRAR(Power, "^");
REGISTRAR(Mod, "%");
REGISTRAR(Log, "log");
REGISTRAR(Ln, "ln");
REGISTRAR(Sin, "sin");
REGISTRAR(Cos, "cos");
REGISTRAR(Tan, "tan");
REGISTRAR(dtor, "dtor");
REGISTRAR(Sqrt, "sqrt");

int main() {
	string exp;
	while (getline(cin, exp)) {
		Calculator cclt;					
		if (cclt.del_space(exp) && cclt.check(exp)) {
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

