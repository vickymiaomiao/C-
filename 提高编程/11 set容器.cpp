#define _CRT_SECURE_NO_WARNINGS 1  
#include <set>
#include <string>
#include <iostream>
using namespace std;

/*
* set 集合
* 所有元素在插入时都会自动被排序
* 本质set/multiset属于关联式容器，底层结构是使用二叉树实现
* 两者区别：
* set不允许容器中有重复的元素
* multiset允许容器中有重复的元素
* 
*/

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//构造和赋值
void test01()
{
	set<int>s1;
	//插入数据只有insert方式
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//遍历容器   自动排序，并且不允许重复的值
	printSet(s1);

	set<int>s2(s1);
	printSet(s2);

	set<int>s3;
	s3 = s2;
	printSet(s3);
}

//大小和交换操作
//size empty swap
void test02()
{
	set<int>s1;
	//插入数据只有insert方式
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//遍历容器   自动排序，并且不允许重复的值
	cout << "before change:" << endl;
	printSet(s1);
	if (s1.empty())
	{
		cout << "s1 is empty" << endl;
	}
	else
	{
		cout << "s1 is not empty" << endl;
		cout << "s1 size : " << s1.size() << endl;
	}
	set<int>s2;
	s2.insert(100);
	s2.insert(200);
	s2.insert(300);
	s2.insert(400);
	printSet(s2);
	cout << "after change" << endl;
	s1.swap(s2);
	printSet(s1); 
	printSet(s2);
	//不支持resize

}

//插入和删除
//insert erase(可以按照迭代器也可以删除指定元素) clear 
void test03()
{
	set<int>s1;
	//插入数据只有insert方式
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//遍历容器   自动排序，并且不允许重复的值

	printSet(s1);
	//删除
	s1.erase(s1.begin());
	printSet(s1);
	//s1.erase(s1.begin(),s1.end());
	//printSet(s1);
	s1.erase(30);//删除指定元素
	printSet(s1);
	//清空 clear
	s1.clear();
	printSet(s1);
}

//查找和统计
//对set容器进行查找数据和统计数据
//find 查找key是否存在，若存在，返回改元素的迭代器，若不存在，返回set.end()
//count 统计key中的元素个数
void test04()
{
	set<int>s1;
	//插入数据只有insert方式
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//查找元素位置
	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end())
	{
		cout << "find elem:" << *pos << endl;
	}
	else
	{
		cout << "not find" << endl;
	}
	//统计元素个数
	//对于set而言，统计的结果要么是0，要么是1
	cout << "30 count:" << s1.count(30) << endl;
}

//set不可以插入重复数据
//set插入数据同时会返回插入结果，表示插入是否成功
//multiset不会检测数据，因此可以插入重复的数据
void test05()
{
	set<int> s;
	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second)
	{
		cout << "first insert success" << endl;
	}
	else
	{
		cout << "first insert fail" << endl;
	}
	ret=s.insert(10);
	if (ret.second)
	{
		cout << "second insert success" << endl;
	}
	else
	{
		cout << "second insert fail" << endl;
	}
	multiset<int>ms;
	//允许插入重复的值
	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

//pair 对组创建
//成对出现的数据，利用对组可以返回两个数据
//pair<type,type> p(value1,value2)
//pair<type,type> p=make_pair(value1,value2)
void test06()
{
	//第一种方式
	pair<string, int> p("vicky", 18);
	cout << "name : " << p.first << "    age : " << p.second << endl;

	//第二种方式
	pair<string, int> p2 = make_pair("bob", 18);
	cout << "name : " << p2.first << "    age : " << p2.second << endl;
}

//仿函数  本质是一个数据类型
class MyCompare
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};

//set容器默认的排序规则为升序，掌握如何改变排序规则
//主要技术点：利用仿函数，可以改变排序规则
void test07()
{
	set<int>s1;
	s1.insert(80);
	s1.insert(10);
	s1.insert(30);
	s1.insert(50);
	s1.insert(40);
	printSet(s1);
	//指定排序规则为从大到小
	//set<int, MyCompare>s2;
	//s2.insert(80);
	//s2.insert(10);
	//s2.insert(30);
	//s2.insert(50);
	//s2.insert(40);
	//for (set<int,MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;
	
}

//set容器存放自定义数据类型
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

class compareperson
{
public:
	bool operator()(const Person& p1,const Person& p2) const
	{
		//按照年龄降序
		return p1.m_Age > p2.m_Age;
	}
};

void test08()
{
	//自定义的数据类型，都会指定排序规则
	set<Person, compareperson>s;
	//创建person
	Person p1("tom", 20);
	Person p2("vicky", 22);
	Person p3("bob", 30);
	Person p4("andy", 8);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, compareperson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << it->m_Name << " : " << it->m_Age << endl;
	}
	

}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();
	return 0;
}