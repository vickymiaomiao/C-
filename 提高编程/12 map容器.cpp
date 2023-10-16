#define _CRT_SECURE_NO_WARNINGS 1 
#include<iostream>
#include <map>
#include <string>
using namespace std;

/*
* map容器中的所有元素都是pair
* pair中第一个元素为key键值，祈祷索引作用，第二个元素为value
* map容器高效率高性能
* 所有元素都会根据键值自动排序
* 
* 本质：
* map/multimap属于关联式容器，底层结构使用二叉树实现
* 优点：
* 可以根据key值快速找到value值
* map和multimap的区别：
* map中不允许有重复key值元素
* multimap允许容器中有重复key值元素
* map元素中所有元素都是成对出现，插入数据时要使用对组
*/
void printMap(map<int, int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		//对组
		cout << "key : " << it->first << "    value : " << it->second << endl;
	}
}

//构造和赋值
void test01()
{
	//创建map容器
	map<int, int>m;
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(2, 20));
	
	printMap(m);

	//拷贝构造
	map<int, int>m2(m);
	printMap(m2);
	//赋值
	map<int, int>m3;
	m3 = m2;
	printMap(m3);
}

//map大小和交换
//size empty swap()
void test02()
{
	map<int, int>m;
	cout << "before swap" << endl;
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(2, 20));

	printMap(m);
	if (m.empty())
	{
		cout << "map is empty" << endl;
	}
	else
	{
		cout << "map is not empty" << endl;
		cout << "map size is :" << m.size() << endl;
	}
	map<int, int>m1;
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(4, 40));
	printMap(m1);
	cout << "after swap" << endl;
	m.swap(m1);
	printMap(m);
	printMap(m1);



}

//插入和删除
//insert clear erase erase(key)删除容器中为key的元素
void test03()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	//第二种
	m.insert(make_pair(2, 20));
	//第三种
	m.insert(map<int, int>::value_type(3, 30));
	//第四种  不建议插入，可以用key来访问value
	m[4] = 40;
	printMap(m);
	cout << m[5] << endl;   //key不存在则创建value值为0的数据
	m.erase(m.begin());
	printMap(m);
	m.erase(3);//删除key为3的数据
	printMap(m);
	m.erase(m.begin(), m.end());//清空操作
	m.clear();
	printMap(m);

}

//查找和统计
//find 查找key是否存在，若存在，返回该键的元素迭代器，若不存在，返回m.end()
//count 统计key 的元素个数
void test04()
{
	map<int, int>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	map<int, int>::iterator pos = m.find(4);//返回元素的迭代器，所以需要用迭代器接受
	if (pos != m.end())
	{
		cout << "find it" << endl;
		cout << " key = " << pos->first << " value = " << pos->second << endl;
	}
	else
	{
		cout << "not find" << endl;
	}
	//map不允许插入重复的key，所以count结果要么是0要么是1 multimap的count可能大于1
	int num = m.count(3);
	cout << num << endl;
}

class MyCompare
{
public:
	bool operator()(int v1,int v2) const
	{
		return v1 > v2;
	}
};

//排序
//默认排序规则为升序，利用仿函数改变排序规则
void test05()
{
	map<int, int,MyCompare>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		//对组
		cout << "key : " << it->first << "    value : " << it->second << endl;
	}
}



int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}