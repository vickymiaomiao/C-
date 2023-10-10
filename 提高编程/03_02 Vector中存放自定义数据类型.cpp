#define _CRT_SECURE_NO_WARNINGS 1   
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Person
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void test01()
{
	vector<Person> v;
	Person p1("vicky", 18);
	Person p2("tom", 18);
	Person p3("bob", 18);
	Person p4("andy", 18);
	Person p5("lucy", 18);

	//利用尾插方式
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//遍历容器中的数据
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//cout << " name :" << (*it).m_Name << " age :" << (*it).m_Age << endl;
		cout << " name :" << it->m_Name << " age :" << it->m_Age << endl;
	}
}
//存放自定义数据类型的指针
void test02()
{
	vector<Person *> v;
	Person p1("vicky", 18);
	Person p2("tom", 18);
	Person p3("bob", 18);
	Person p4("andy", 18);
	Person p5("lucy", 18);

	//利用尾插方式
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	//遍历容器
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << " name :" << (*(*it)).m_Name << " age :" << (*(*it)).m_Age << endl;
		cout << " name :" << (*it)->m_Name << " age :" << (*it)->m_Age << endl;
	}
}

//容器嵌套容器
void test03()
{
	//创建大容器
	vector<vector<int>>v;
	//创建小容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	//向小容器中添加数据
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	//将4个小容器放入大容器
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	//通过大容器将所有数据遍历一遍
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//(*it)是一个容器
		//遍历小容易
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}



int main()
{
	test01();
	test02();
	test03();
	return 0;
}