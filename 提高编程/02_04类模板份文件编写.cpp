#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <string>
using namespace std;
//#include "02_04 person.cpp"
#include "02_04 person.hpp"


/*
* ���⣺��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���
* 
* ����취��
* 1.ֱ�Ӱ���.cppԴ�ļ�
* 2.��������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊhpp,hpp��Լ�������ƣ�������ǿ��
*/

//template<class T1, class T2>
//class Person
//{
//public:
//	//���캯��
//	Person(T1 name, T2 age);
//
//	//��Ա����
//	void showPerson();
//
//	T1 m_Name;
//	T2 m_Age;
//};

//����ʵ�֣�����ֻд����
//���캯��
//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)   //��ʾ��ģ��ĳ�Ա����ʵ��
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}
////��Ա����
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