#ifndef OPERATORFACTORY_H
#define OPERATORFACTORY_H

#include<string>
#include<map>
#include<functional>
#include<memory>
#include"Operator.h"

// 注册Object的宏声明
#define REGISTRAR(T, Key)  Factory::RegisterClass<T> reg_##T(Key);

using namespace std;

class Factory {
public:
	template<typename T>
	struct RegisterClass {
		RegisterClass(string opr) {
			Factory::ms_operator.emplace(opr, [] {return make_unique<T>(); });
		}
	};

	static unique_ptr<Operator> create(string opr) {
		auto it = ms_operator.find(opr);
		if (it != ms_operator.end())
			return it->second();						//做一个未定义操作符报错，可以提出您要使用的作用符是不是？
		else
			throw "Well, our calculator doesn't seem to have this operator or function!";
	}
	//private:
	static map<string, function<unique_ptr<Operator>()>> ms_operator; // 存储已注册运算符名及对应构建函数指针的map
};

#endif


