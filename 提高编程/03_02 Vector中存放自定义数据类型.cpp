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

	//����β�巽ʽ
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//���������е�����
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//cout << " name :" << (*it).m_Name << " age :" << (*it).m_Age << endl;
		cout << " name :" << it->m_Name << " age :" << it->m_Age << endl;
	}
}
//����Զ����������͵�ָ��
void test02()
{
	vector<Person *> v;
	Person p1("vicky", 18);
	Person p2("tom", 18);
	Person p3("bob", 18);
	Person p4("andy", 18);
	Person p5("lucy", 18);

	//����β�巽ʽ
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	//��������
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << " name :" << (*(*it)).m_Name << " age :" << (*(*it)).m_Age << endl;
		cout << " name :" << (*it)->m_Name << " age :" << (*it)->m_Age << endl;
	}
}

//����Ƕ������
void test03()
{
	//����������
	vector<vector<int>>v;
	//����С����
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	//��С�������������
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	//��4��С�������������
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	//ͨ�����������������ݱ���һ��
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//(*it)��һ������
		//����С����
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