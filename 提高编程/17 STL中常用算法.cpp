#define _CRT_SECURE_NO_WARNINGS 1   
#include <algorithm>
#include <iostream>
#include <numeric>
#include <functional>
#include <vector>
using namespace std;


/*
* 常用遍历算法
* for_each 遍历容器
* transform 搬运容器到另一个容器中
* find查找算法
*/
//普通函数
void print01(int val)
{
	cout << val << " ";
}
//仿函数
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

class Transform
{
public:
	int operator()(int v)
	{
		return v+100;
	}
};

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

void test_for_each_transform_find()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//普通函数 传入函数名称
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	//仿函数，传入函数对象
	for_each(v.begin(), v.end(), print02());
	cout << endl;

	//transform(beg1,end1,beg2,func)    搬运容器到另一个容器中
    //beg1源容器开始迭代器 end1源容器结束迭代器 beg2目标容器开始迭代器 函数或者函数对象

	vector<int>vt;
	vt.resize(v.size()); //目标容器必须提前开辟空间
	transform(v.begin(), v.end(), vt.begin(), Transform());
	for_each(vt.begin(), vt.end(), print02());
	cout << endl;

	//查找元素 find 返回类型为迭代器
	vector<int>::iterator it=find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << "find it: " << *it << endl;
	}
	//自定义数据类型查找
	vector<Person>vp;
	Person p1("vicky", 1);
	Person p2("bob", 1);
	Person p3("tom", 1);
	Person p4("jerry", 1);

}






int main()
{
	test_for_each_transform_find();
	return 0;
}