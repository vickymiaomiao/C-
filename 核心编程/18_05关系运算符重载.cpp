#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;
/*
* 重载关系运算符，可以让两个自定义类型对象进行对比操作
*/
class Person
{
public:
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	//重载==
	bool operator==(Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
			return false;
	}
	//重载！=
	bool operator!=(Person& p)
	{
		if (this->m_Name != p.m_Name || this->m_Age != p.m_Age)
		{
			return true;
		}
		else
			return false;
	}

	string m_Name;
	int m_Age;
};

void test01()
{
	Person p1("vicky", 18);
	Person p2("andy", 18);
	//if (p1 == p2)
	//{
	//	cout << "p1==p2" << endl;
	//}
	//else
	//{
	//	cout << "p1!=p2" << endl;
	//}

	if (p1 != p2)
	{
		cout << "p1!=p2" << endl;
	}
	else
	{
		cout << "p1==p2" << endl;
	}
}


int main()
{
	test01();
	return 0;
}