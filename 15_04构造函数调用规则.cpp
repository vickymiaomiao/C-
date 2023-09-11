#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

//
// 默认情况下，C++至少给一个类添加3个函数
// 1.默认构造函数（空实现）
// 2.默认析构函数（空实现）
// 3.默认拷贝构造函数，对其属性进行值拷贝
//
/*
* 构造函数调用规则如下
*1.如果用户定义有参构造函数，C++不在提供默认无参构造函数 ，但依然提供拷贝构造函数
2.如果我们写了拷贝构造函数，编译器就不提供替他的构造函数
*/

class person
{
public:
	person()
	{
		cout << "person的默认构造函数调用" << endl;
	}
	person(int age)
	{
		m_Age = age;
		cout << "person的有参构造函数的调用" << endl;
	}
	person(const person& p)
	{
		m_Age = p.m_Age;
		cout << "person 的拷贝函数的调用" << endl;
	}
	~person()
	{
		cout << "person的析构函数的调用" << endl;
	}
	int m_Age;
};

void test150401()
{
	person p;
	p.m_Age = 18;

	person p2(p);
	cout << "p2的年龄为" << p2.m_Age << endl;
}

int main1504()
{
	test150401();
	return 0;
}