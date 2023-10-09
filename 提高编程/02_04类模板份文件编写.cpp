#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <string>
using namespace std;
//#include "02_04 person.cpp"
#include "02_04 person.hpp"


/*
* 问题：类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
* 
* 解决办法：
* 1.直接包含.cpp源文件
* 2.将声明和实现写到同一个文件中，斌哥更改后缀名为hpp,hpp是约定的名称，并不是强制
*/

//template<class T1, class T2>
//class Person
//{
//public:
//	//构造函数
//	Person(T1 name, T2 age);
//
//	//成员函数
//	void showPerson();
//
//	T1 m_Name;
//	T2 m_Age;
//};

//类外实现，类内只写声明
//构造函数
//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)   //表示类模板的成员函数实现
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}
////成员函数
//template<class T1, class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << this->m_Name << endl;
//	cout << this->m_Age << endl;
//}

void test01()
{
	Person<string, int> p("vicky", 18);
	p.showPerson();
}


int main()
{
	test01();
	return 0;
}