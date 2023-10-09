#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* 建立一个通用类，类中的成员数据类型可以不具体定制，用一个虚拟类型来代替
*函数模板和类模板的区别：
* 1.类模板没有自动类型推导使用方式
* 2.类模板在模板参数列表中可以有默认参数
* 
* 类模板中的成员函数和普通类中的成员函数创建时机有区别：
* 1.普通类中的成员函数一开始就可以创建
* 2.类模板中的成员函数在调用时才创建
* 
* 类模板对象，做函数的参数，有三种传入方式：
* 1.指定传入的类型---比较常用
* 2.参数模板化
* 3.整个类模板化
* 
*/

template<class NameType,class AgeType=int>
class Person
{
public:
	Person(NameType name,AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "m_Name = " << this->m_Name << endl;
		cout << "m_Age = " << this->m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

//1.指定类型传入
void printPerson1(Person<string, int>&p)
{
	p.showPerson();
}
void test01()
{
	Person<string, int>p("vicky", 18);
	printPerson1(p);
}

//2.参数模板化
template<class T1,class T2>
void printPerson2(Person<T1, T2>&p)
{
	p.showPerson();
	//打印T1,T2的数据类型
	cout << "T1的数据类型为：" << typeid(T1).name() << endl;
	cout << "T2的数据类型为：" << typeid(T2).name() << endl;
}
void test02()
{
	Person<string, int>p("tom", 18);
	printPerson2(p);
}

//3.整个类模板化

template<class T>
void printPerson3(T &p)
{
	p.showPerson();
	//打印T1,T2的数据类型
	cout << "T1的数据类型为：" << typeid(T).name() << endl;
	
}
void test03()
{
	Person<string, int>p("andy", 18);
	printPerson3(p);
}

int main()
{
	//Person<string> p1("vicky", 18);  //只有显示类型转换
	//p1.showPerson();
	test01();
	test02();
	test03();
	return 0;
}