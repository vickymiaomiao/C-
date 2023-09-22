#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

/*
* 继承中同名的静态成员在子类对象上如何进行访问？
* 静态成员和非静态成员出现同名，处理方式一致
* 访问子类同名成员直接访问即可
* 访问父类同名成员，需要添加作用域
*/

class Base
{
public:
	static void func()
	{
		cout << "base static func" << endl;
	}
	static void func(int a)
	{
		cout << "base static func int a" << endl;
	}
	static int m_A;
};

int Base::m_A = 100;

class Son :public Base
{
public:
	static void func()
	{
		cout << "son static func" << endl;
	}
	static int m_A;
};

int Son::m_A = 200;

//同名静态成员的属性
void test01()
{
	//1.通过对象来访问
	Son s;
	cout << "通过对象来访问" << endl;
	cout << " son m_A=" << s.m_A << endl;
	cout << " base m_A=" << s.Base::m_A << endl;
	//2.通过类名来访问
	cout << "通过类名来访问" << endl;
	cout << " son m_A=" << Son::m_A << endl;
	//第一个冒号表示通过类名方式，第二个表示作用域
	cout << " base m_A=" << Son::Base::m_A << endl;
}

//同名成员静态函数
void test02()
{
	Son s1;
	cout << "通过对象来访问" << endl;
	s1.func();
	s1.Base::func();
	cout << "通过类名来访问" << endl;
	Son::func();
	Son::Base::func();
	Son::Base::func(100);
}

int main()
{
	test01();
	test02();
	return 0;
}