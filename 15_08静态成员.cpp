#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* 静态成员就是在成员函数前加上关键字static
* 1.静态成员变量，
* 所有对象共享同一份数据
* 在编译阶段分配内存
* 类内声明，类内初始化
* 2.静态成员函数
* 所有对象共享同一个函数
* 静态成员函数只能访问静态成员变量
*/

class person
{
public:
	//静态成员变量也有访问权限
	static int m_A; 
	int m_C;

	static void func()
	{
		m_A = 500;
		//m_C = 300;   非静态成员变量，静态函数无法访问，无法区分到底是哪个对象的属性
		cout << "static func 调用" << endl;
	}
private:
	static int m_B;   //私有作用域类外不可以访问
	//静态成员函数也有访问权限
	static void func2()
	{
		cout << "private static func调用" << endl;
	}
};

int person::m_A = 100; //类外初始化
int person::m_B = 200;

void test01()
{
	person p;
	cout << p.m_A << endl;

	person p2;
	p2.m_A = 200;
	cout << p.m_A << endl;
}

void test02()
{
	//静态成员变量不属于某个对象上，所有对象都共享同一份数据
	//因此静态成员变量有两种访问方式
	//1.通过对象访问
	person p1;
	cout << p1.m_A << endl;
	p1.func();
	//2.通过类名进行访问
	cout << person::m_A << endl;
	person::func();
	//cout << person::m_B << endl;    类外无法访问私有成员变量
	//person::func2();   类外无法访问静态成员函数
}

int main()
{
	test01();
	test02();
	return 0;
}