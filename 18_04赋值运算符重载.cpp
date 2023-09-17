#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <string>
using namespace std;
/*
* C++编译器至少给一个类添加4个函数
* 1.默认构造函数（无参，函数体为空）
* 2.默认析构函数（无参，函数体为空）
* 3.默认拷贝构造函数，对其属性进行值拷贝
* 4.赋值运算符operator=.对属性进行值拷贝
* 
* 如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
*/
class Person
{
public:
	Person(int age)
	{
		m_Age = new int(age);
	}
	~Person()  //堆区内存重复释放，利用深拷贝解决带来的问题
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	//重载赋值运算符
	Person& operator=(Person& p)
	{
		//编译器提供浅拷贝
		//m_Age = p.m_Age;

		//应该先判断是否有属性在堆区,如果有先释放
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		//深拷贝
		m_Age = new int(*p.m_Age);
		return *this;
	}

	int* m_Age;

};

void test01()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);

	p3 = p2 = p1;  //赋值操作
	cout <<"p1的年龄为：" << *p1.m_Age << endl;
	cout << "p2的年龄为：" << *p2.m_Age << endl;
	cout << "p3的年龄为：" << *p3.m_Age << endl;
}

int main()
{
	test01();
	return 0;
}
