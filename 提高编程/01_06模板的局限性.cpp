#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* ģ���ͨ���Բ��������ܵ�,��Щ�ض��������ͣ���Ҫ���廯����ʵ��
*/

class Person
{
public:
	Person(string name,int age)
	{
		m_Name = name;
		m_Age = age;
	}

	string m_Name;
	int m_Age;
};

//�Ա������Ƿ���ȵĺ���������true
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//���þ��廯��person�汾ʵ�ִ��룬���廯���ȵ���
template<>bool myCompare(Person& a, Person& b)
{
	if (a.m_Name == b.m_Name && a.m_Age == b.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int a = 10, b = 20;
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}

	Person p1("vicky", 10);
	Person p2("vicky", 110);
	bool ret1 = myCompare(p1, p2);
	if (ret1)
	{
		cout << "p1==p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}

	return 0;
}