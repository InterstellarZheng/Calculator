#ifndef OPERATORFACTORY_H
#define OPERATORFACTORY_H

#include<string>
#include<map>
#include<functional>
#include<memory>
#include"Operator.h"

// ע��Object�ĺ�����
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
			return it->second();						//��һ��δ����������������������Ҫʹ�õ����÷��ǲ��ǣ�
		else
			throw "Well, our calculator doesn't seem to have this operator or function!";
	}
	//private:
	static map<string, function<unique_ptr<Operator>()>> ms_operator; // �洢��ע�������������Ӧ��������ָ���map
};

#endif


