#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <string>
using namespace std;

/*
* 全局函数类内实现--直接在类内声明友元即可
* 全局函数类外实现---提前让编译器知道全局函数的存在
*/
template<class T1, class T2>   //提前让编译器知道模板的存在
class Person;

template<class T1, class T2>
void printPerson2(Person<T1, T2> p)
{
	cout << p.m_Name << endl;
	cout << p.m_Age << endl;
	cout << "类外实现" << endl;
}

//通过全局函数打印person的信息

template<class T1, class T2>
class Person
{
	//全局函数类内实现
	friend void printPerson(Person<T1,T2> p)
	{
		cout << p.m_Name << endl;
		cout << p.m_Age << endl;
		cout << "类内实现" << endl;
	}
	//全局函数类外实现
	friend void printPerson2<>(Person<T1, T2> p);//添加空模板的参数列表


public:
	//构造函数
	Person(T1 name, T2 age);

private:
	T1 m_Name;
	T2 m_Age;
};



//类外实现，类内只写声明
//构造函数
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)   //表示类模板的成员函数实现
{
	this->m_Name = name;
	this->m_Age = age;
}
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
	printPerson(p);
	printPerson2<string,int>(p);
	
}


int main()
{
	test01();
	return 0;
}