#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

//拷贝构造函数的调用时机


class person
{
public:
	person()
	{
		cout << "默认构造函数的调用" << endl;
	}

	person(int a)
	{
		m_Age = a;
		cout << "有参构造函数的调用" << endl;
	}

	person(const person& p)
	{
		m_Age = p.m_Age;
		cout << "拷贝构造函数的调用" << endl;
	}

	~person()
	{
		cout << "析构函数的调用" << endl;
	}

	int m_Age;
};

//1.使用一个创建完毕的对象来初始化一个新对象
//void test01()
//{
//	person p1(20);
//	person p2(p1);
//	cout << "p2的年龄：" << p2.m_Age << endl;
//}

//2.值传递的当时给函数参数传值
void dowork(person p)
{}
void test02()
{
	person p;
	dowork(p);

}
// 
//3.值方式返回局部对象

person dowork2()
{
	person p1;
	return p1;
	//返回时根据p1创建新的对象
}
void test03()
{
	person p = dowork2();
}

int main1503()
{
	/*test01();*/
	test02();
	return 0;
}