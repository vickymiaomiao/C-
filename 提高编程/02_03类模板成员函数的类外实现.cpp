#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

template<class T1,class T2>
class Person
{
public:
	//构造函数
	Person(T1 name, T2 age);
	//{
	//	this->m_Name = name;
	//	this->m_Age = age;
	//}
	//成员函数
	void showPerson();
	//{
	//	cout << this->m_Name << endl;
	//	cout << this->m_Age << endl;
	//}

	T1 m_Name;
	T2 m_Age;
};

//类外实现，类内只写声明
//构造函数
template<class T1, class T2>
Person<T1,T2>::Person(T1 name, T2 age)   //表示类模板的成员函数实现
{
	this->m_Name = name;
	this->m_Age = age;
}
//成员函数
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << this->m_Name << endl;
	cout << this->m_Age << endl;
}

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