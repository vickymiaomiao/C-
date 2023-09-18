#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* 当子类与父类出现同名成员，如何通过子类对象访问到父类成员
* 
* 访问子类同名成员直接访问即可
* 访问父类同名成员需要添加作用域
*/

class Base
{
public:
	Base()
	{
		m_A = 100;
	}
	int m_A;

	void func()
	{
		cout << "Base - func()" << endl;
	}
	void func(int a)
	{
		cout << "son - func() - int a" << endl;
	}

};

class son :public Base
{
public:
	son()
	{
		m_A = 200;
	}
	int m_A;

	void func()
	{
		cout << "son - func()" << endl;
	}


};

void test01()
{
	son s;
	cout << "son下的 m_A=" << s.m_A << endl;
	cout << "Base下的 m_A=" << s.Base::m_A << endl;
}

void test02()  //同名成员函数的处理
{
	son s1;
	s1.func();
	s1.Base::func();
	//如果子类中出现了父类同名的成员函数，子类的同名成员会隐藏掉父类中所有的同名成员函数
	//如果要访问需要添加作用域
	s1.Base::func(100);
}

int main()
{
	test01();
	test02();
	return 0;
}