#pragma once

#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>
class Person
{
public:
	//���캯��
	Person(T1 name, T2 age);

	//��Ա����
	void showPerson();

	T1 m_Name;
	T2 m_Age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)   //��ʾ��ģ��ĳ�Ա����ʵ��
{
	this->m_Name = name;
	this->m_Age = age;
}
//��Ա����
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << this->m_Name << endl;
	cout << this->m_Age << endl;
}