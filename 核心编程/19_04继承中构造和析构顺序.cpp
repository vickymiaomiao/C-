#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;
/*
* 继承中的构造和析构函数
* 子类继承父类后，当创建子类对象，也会调用父类的构造函数
* 先构造父类再构造子类，析构的顺序与构造的顺序相反
*/

class Base
{
public:
	Base()
	{
		cout << "Base的构造函数" << endl;
	}

	~Base()
	{
		cout << "Base的析构函数" << endl;
	}
};

class son:public Base
{
public:
	son()
	{
		cout << "son构造函数" << endl;
	}
	~son()
	{
		cout << "son析构函数" << endl;
	}
};

void test01()
{
	//son s1;
	//Base b;
	son s;
}

int main()
{
	test01();
	return 0;
}
