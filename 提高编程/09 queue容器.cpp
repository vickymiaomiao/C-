#define _CRT_SECURE_NO_WARNINGS 1  
#include <queue>
#include <iostream>
#include <string>
using namespace std;


/*
* ������������һ���Ƚ��ȳ������ݽṹ������������
* ��� push
* ���� pop
* back()��β  front() ��ͷ 
* �����������ֻ�ܶ�β�����ݣ���ͷ������
* empty size
*/

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void test01()
{
	queue<Person> q;
	Person p1("vicky", 18);
	Person p2("tom", 8);
	Person p3("andy", 108);
	Person p4("bob", 180);
	//���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	cout << "queue size: " << q.size() << endl;
	while (!q.empty())
	{
		cout << "��ͷ->name:" << q.front().m_Name 
			<< "��ͷ->age:" << q.front().m_Age << " ";
		cout << "��β->name:" << q.back().m_Name
			<< "��β->age:" << q.back().m_Age << endl;
		q.pop();
	}
	cout << "queue size: " << q.size() << endl;
}

int main()
{
	test01();
	return 0;
}