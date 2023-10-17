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
* find查找算法 返回迭代器
* find_if(beg,end,_pred) 谓词  按照条件查找
* adjacent_find(beg,end) 查找相邻重复元素
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
	//重载一下 ==号 让底层知道如何对比person的数据类型
	bool operator==(const Person &p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	string m_Name;
	int m_Age;
};

class GreaterFind
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

class Greater20
{
public:
	bool operator()(Person &p)
	{
		return p.m_Age > 20;
	}
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
	Person p3("tom", 30);
	Person p4("jerry", 1);

	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	//查找是否存在P2
	vector<Person>::iterator it1 = find(vp.begin(), vp.end(), p2);
	if (it1 == vp.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << "find it: " << it1->m_Name<<" : "<<it1->m_Age<< endl;
	}
	//find_if
	//1、查找内置数据类型
	vector<int>::iterator it2=find_if(v.begin(), v.end(), GreaterFind());
	if (it2 == v.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << "find it: " << *it2<< endl;
	}
	//2.查找定义数据类型
	vector<Person>::iterator it3 = find_if(vp.begin(), vp.end(), Greater20());
	if (it3 == vp.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << "find it: " << it3->m_Name << " : " << it3->m_Age << endl;
	}

	//adjacent_find  查找相邻重复元素
	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos == v.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << "find it: " << *pos << endl;
	}


}






int main()
{
	test_for_each_transform_find();
	return 0;
}