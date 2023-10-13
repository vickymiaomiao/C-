#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
#include <list>
using namespace std;


/*
* ��person�Զ����������ͽ�������Person�����������������䡢���
* ������򣺰�����������������������ͬ������߽��н���
*/

class Person
{
public:
	Person(string name,int age,int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	string m_Name;
	int m_Age;
	int m_Height;
};
//��ӡ����
void printList(const list<Person>& l)
{
	for (list<Person>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << it->m_Name << " " << it->m_Age << " " << it->m_Height << endl;
	}
}

//ָ���������
bool comparePerson(Person &p1,Person &p2)
{
	//������������
	if (p1.m_Age == p2.m_Age)
	{
		//������ͬ������߽���
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_Age < p2.m_Age;

}

int main()
{
	//����list����
	list<Person> L;
	//������
	Person p2("tom", 20, 168);
	Person p1("vicky", 20, 188);
	Person p3("bob", 30, 188);
	Person p4("andy", 8, 153);
	//���˲��뵽������
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	//��ӡ��ǰ����
	printList(L);
	cout << "-----------------------" << endl;
	cout << "after sort" << endl;
	L.sort(comparePerson);
	printList(L);
	return 0;
}