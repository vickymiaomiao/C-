#define _CRT_SECURE_NO_WARNINGS 1  
#include <queue>
#include <iostream>
#include <string>
using namespace std;


/*
* 队列容器，是一种先进先出的数据结构，有两个出口
* 入队 push
* 出队 pop
* back()队尾  front() 队头 
* 不允许遍历，只能队尾进数据，队头出数据
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
	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	cout << "queue size: " << q.size() << endl;
	while (!q.empty())
	{
		cout << "队头->name:" << q.front().m_Name 
			<< "队头->age:" << q.front().m_Age << " ";
		cout << "队尾->name:" << q.back().m_Name
			<< "队尾->age:" << q.back().m_Age << endl;
		q.pop();
	}
	cout << "queue size: " << q.size() << endl;
}

int main()
{
	test01();
	return 0;
}