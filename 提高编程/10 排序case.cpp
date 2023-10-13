#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
#include <list>
using namespace std;


/*
* 将person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
* 排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
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
//打印容器
void printList(const list<Person>& l)
{
	for (list<Person>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << it->m_Name << " " << it->m_Age << " " << it->m_Height << endl;
	}
}

//指定排序规则
bool comparePerson(Person &p1,Person &p2)
{
	//按照年龄升序
	if (p1.m_Age == p2.m_Age)
	{
		//年龄相同按照身高降序
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_Age < p2.m_Age;

}

int main()
{
	//创建list容器
	list<Person> L;
	//创建人
	Person p2("tom", 20, 168);
	Person p1("vicky", 20, 188);
	Person p3("bob", 30, 188);
	Person p4("andy", 8, 153);
	//将人插入到容器中
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	//打印当前数据
	printList(L);
	cout << "-----------------------" << endl;
	cout << "after sort" << endl;
	L.sort(comparePerson);
	printList(L);
	return 0;
}