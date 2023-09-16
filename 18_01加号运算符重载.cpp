#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;

/*
* 对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
* 实现两个自定义数据类型相加的运算
* 1.通过成员函数重载加号
* 2.通过全局函数重载加号
* 注意：
* 1.对于内置的数据类型的表达式的运算符是不可能改变的
* 2.不要滥用运算符重载
*/

class Person
{
public:
	//通过成员函数实现运算符重载
	//Person operator+(Person p)
	//{
	//	Person temp;
	//	temp.m_A = this->m_A + p.m_A;
	//	temp.m_B = this->m_B + p.m_B;
	//	return temp;
	//}

	int m_A;
	int m_B;
};

//通过全局函数实现运算符重载
Person operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
//重载
Person operator+(Person& p1, int num)
{
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

void test01()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 10;
	p2.m_B = 20;
	//成员函数本质调用
	Person p3 = p1 + p2;
	Person p4 = p1 + 30;
	//运算符重载也可以发生函数重载
	cout << "p3.m_A=" << p3.m_A << endl;
	cout << "p3.m_B=" << p3.m_B << endl;
	cout << "p4.m_A=" << p4.m_A << endl;
	cout << "p4.m_B=" << p4.m_B << endl;
}

int main()
{
	test01();
	return 0;
}