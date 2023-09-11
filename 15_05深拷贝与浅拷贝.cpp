#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* 浅拷贝：简单的赋值拷贝操作
* 深拷贝：在堆区申请空间在进行拷贝
* 如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
*/


class person
{
public:
	person()
	{
		cout << "默认构造函数" << endl;
	}
	person(int age,int height)
	{
		m_Age = age;
		m_Height = new int(height);   //在堆区开辟空间存放数据
		cout << "有参构造函数" << endl;
	}
	//自己实现拷贝构造函数，解决浅拷贝带来的问题
	person(const person& p)
	{
		m_Age = p.m_Age;
		//深拷贝操作,重新开辟内存，存放拷贝的属性的值
		m_Height = new int(*p.m_Height);

	}

	~person()
	{
		//将堆区开辟的数据做释放操作,栈区数据先进后出
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;       //浅拷贝会导致堆区内存重复释放
		}
		cout << "析构函数" << endl;
	}
	int m_Age;
	int* m_Height;
};

void test01()
{
	person p1(18,160);
	cout << "p1的年龄为" << p1.m_Age << endl;
	cout << "p1的身高为" << *p1.m_Height << endl;
	person p2(p1);
	cout << "p2的年龄为" << p2.m_Age << endl;
	cout << "p2的身高为" << *p2.m_Height << endl;

}


int main1505()
{
	test01();
	return 0;
}