//利用链栈实现
/*
1.增加弧度数字转换
2.自动删除空格将表达式转换成小写并检查有没有异常字符
3.检查括号是否匹配
1.报错处理，比如除以0
*/


/*需要做
* 
* 
1.调整精度
3.负数处理
4.矩阵运算
5.保留上次运算结果
*/
#include <string>
#include <iostream>
#include "Calculator.h"


using namespace std;

// 使用宏对Operator进行注册
map<string, function<unique_ptr<Operator>()>> Factory::ms_operator; // 定义存储ObjectCreator的静态map
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

