#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* C++提供了初始化列表法，可以用来初始化属性
* 语法：构造函数（）：属性1（值1），属性2（值2）。。。{}
*/

class person
{
public:
	//传统初始化操作
	//person(int a, int b, int c)
	//{
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	//初始化列表属性
	person(int a,int b,int c):m_A(a),m_B(b),m_C(c)
	{}

	int m_A;
	int m_B;
	int m_C;
};

void test01()
{
	//person p(10, 20, 30);
	person p(30,20,10);
	cout << " m_A=" << p.m_A << " m_B=" << p.m_B << " m_C=" << p.m_C << endl;
}

int main()
{
	test01();
	return 0;
}