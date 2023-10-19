#define _CRT_SECURE_NO_WARNINGS 1   
#include <algorithm>
#include <iostream>
#include <numeric>
#include <functional>
#include <vector>
#include <ctime>
#include <numeric>
using namespace std;


/*
* 常用遍历算法
* for_each 遍历容器
* transform 搬运容器到另一个容器中
* find查找算法 返回迭代器
* find_if(beg,end,_pred) 谓词  按照条件查找
* adjacent_find(beg,end) 查找相邻重复元素
* bool binary_search(beg,end,val) 查找指定元素是否存在  注意在无序序列中不可用 二分查找法
* count(beg,end,value)  统计元素个数
* count_if(beg,end,_pred)  按照条件统计元素出现次数
* 
* 常用排序算法
* sort(beg,end,_pred) 对容器内元素进行排序
* random_shuffle(beg,end)  洗牌，对容器内元素随机调整次序
* merge(beg1,end1,beg2,end2,dest)  容器元素合并，并存储到另一容器中  必须是有序的容器
* reverse(beg,end)  反转指定范围的元素
* 
* 常用copy和替换算法
* copy  拷贝
* replace(beg,end,oldv,newv) 替换
* replace_if(beg,end,_pred,newv)  满足条件的元素进行替换
* swap 互换两个容器中的元素
* 
* 常用算术生成算法
* 算术生成算法属于小型算法，使用时包含的头文件为 #include <numeric>
* accumulate(beg,end,value) 计算容器元素累计总和  value为起始累加值
* fill(beg,end,value) 向容器中添加元素 value为填充的值
* 
* 常用的集合算法
* set_intersection(beg1,end1,beg2,end2,dest)  求两个容器的交集  两个容器必须是有序序列
* set_union(beg1,end1,beg2,end2,dest) 求两个容器的并集  也必须是有序序列
* set_difference 求两个容器的差集
* 
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

void test_binary_count()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//查找容器中是否有9   容器必须是有序序列
	int ret=binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "find it" << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(10);
	int num = count(v1.begin(), v1.end(), 10);
	//内置数据类型统计
	cout << "num of 10 :" << num << endl;
	//自定义数据类型统计  需配合==重载符使用
	vector<Person>vp;
	Person p1("vicky", 30);
	Person p2("bob", 1);
	Person p3("bob", 40);
	Person p4("jerry", 1);

	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	Person p("andy", 10);
	int num1 = count(vp.begin(), vp.end(), p4);
	cout << "num of p:" << num1 << endl;
	//count_if   内置数据类型
	num = count_if(v.begin(), v.end(), GreaterFind());
	cout << "num of greater 5 : " << num << endl;
	//自定义数据类型
	num=  count_if(vp.begin(), vp.end(), Greater20());
	cout << "num of p.age greater 20 : " << num << endl;
}

void test_sort_random()
{
	srand((unsigned int)time(NULL));
	vector<int>v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(30);
	v.push_back(60);
	v.push_back(20);
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	//改变为降序
	//greater为内建函数对象
	//sort(v.begin(), v.end(), greater<int>());
	//for_each(v.begin(), v.end(), print01);
	//cout << endl;
	////打乱顺序
	//random_shuffle(v.begin(), v.end());
	//for_each(v.begin(), v.end(), print01);
	//cout << endl;
	//merge
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//目标容器
	vector<int>vt;
	//给目标容器分配空间
	vt.resize(v.size() + v1.size());
	merge(v.begin(), v.end(), v1.begin(), v1.end(), vt.begin());
	for_each(vt.begin(), vt.end(), print01);
	cout << endl;
	//reverse   元素进行反转
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), print01);
	cout << endl;
}

void test_copy_replace()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	v2.resize(v1.size());  //目标容器提前开辟空间
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), print01);
	cout << endl;
	//替换
	replace(v1.begin(), v1.end(), 4, 100);
	for_each(v1.begin(), v1.end(), print01);
	cout << endl;
	//满足条件的全部替换
	replace_if(v1.begin(), v1.end(), GreaterFind(), 200);
	for_each(v1.begin(), v1.end(), print01);
	cout << endl;
	//互换两个容器
	swap(v1, v2);
	cout << "after swap------------------" << endl;
	for_each(v1.begin(), v1.end(), print01);
	cout << endl;
	for_each(v2.begin(), v2.end(), print01);
	cout << endl;

}

void test_accumulate_fill()
{
	vector<int>v1;
	for (int i = 0; i <= 100; i++)
	{
		v1.push_back(i);
	}
	//累加
	int total = accumulate(v1.begin(), v1.end(), 0);  //参数3为起始的累加值
	cout << "total = " << total << endl;
	//填充
	vector<int>v2;
	v2.resize(10);
	fill(v2.begin(), v2.end(), 200);
	for_each(v2.begin(), v2.end(), print01);
	cout << endl;
}

void test_set()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i <= 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>vt;
	//目标容器提前开辟空间
	//最特殊的情况两个大容器包含了小容器，开辟空间取小容器的size
	vt.resize(min(v1.size(), v2.size()));//求最小值
	//获取交集   返回交集最后一个迭代器的位置
	vector<int>::iterator itend=set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vt.begin());
	for_each(vt.begin(), itend, print01);
	cout << endl;
	
	//获取并集
	//开辟最大内存空间
	vt.resize(v1.size() + v2.size());
	vector<int>::iterator itend1 = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vt.begin());
	for_each(vt.begin(), itend1, print01);
	cout << endl;

	//获取差集  返回最后一个元素迭代器的位置
	//目标容器的空间为最大的容器的size
	vt.resize(max(v1.size() , v2.size()));
	cout << "v1和v2的差集：" << endl;
	vector<int>::iterator itend2 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vt.begin());
	for_each(vt.begin(), itend2, print01);
	cout << endl;

	cout << "v2和v1的差集：" << endl;
	vector<int>::iterator itend3 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vt.begin());
	for_each(vt.begin(), itend3, print01);
	cout << endl;

}


int main()
{
	//test_for_each_transform_find();
	//test_binary_count();
	//test_sort_random();
	//test_copy_replace();
	//test_accumulate_fill();
	test_set();
	return 0;
}