#define _CRT_SECURE_NO_WARNINGS 1   
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

/*
* 链表：将数据进行链式存储
* 链表是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
* 
* 链表由一系列结点组成
* 结点的组成：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域
* 优点，可以对任意位置进行快速插入或者删除元素，采用动态存储分配，不会造成内存浪费
* 缺点：容器遍历速度没有数组快，占用空间比数组大
* 
* 双向循环链表，每个结点有两个指针（指向下一个和上一个）
* 链表的迭代器是双向迭代器，只支持前移和后移
* 
* list插入和删除操作都不会导致原有的list迭代器的失效，这在vector是不成立的
* vector和list是两个最常使用的容器
*/

//遍历容器
void printList(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//构造函数
void test01()
{
	list<int>l1;
	//添加数据
	l1.push_back(10);
	l1.push_back(10); 
	l1.push_back(10); 
	l1.push_back(10);
	//遍历容器
	printList(l1);

	//按照区间
	list<int>l2(l1.begin(),l1.end());
	printList(l2);
	//拷贝构造
	list<int>l3(l1);
	printList(l3);
	//N个elem
	list<int>l4(10, 100);
	printList(l4);
}

//赋值和交换  assign = swap
void test02()
{
	list<int>l1;
	//添加数据
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);
	list<int>l2;
	l2 = l1;
	printList(l2);
	list<int>l3;
	l3.assign(l2.begin(), l2.end());
	printList(l3);
	list<int>l4;
	l4.assign(10,100);
	printList(l4);

	//swap
	l4.swap(l1);
	cout << "after swap" << endl;
	printList(l1);
	printList(l4);

}

//大小  empty size resize
void test03()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);
	//判断容器是否为空
	if (l1.empty())
	{
		cout << "l1 is empty" << endl;
	}
	else
	{
		cout << "l1 is not empty" << endl;
		cout << "l1 size is : " << l1.size() << endl;
	}
	//重新指定大小
	l1.resize(6);
	printList(l1);
	l1.resize(10,100);
	printList(l1);
	l1.resize(4);
	printList(l1);
}

//插入和删除
void test04()
{
	list<int>L;
	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//头插
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);
	printList(L);
	//尾删
	L.pop_back();
	//头删
	L.pop_front();
	printList(L);
	//插入
	list<int>::iterator it = L.begin();
	L.insert(++it, 1000);
	printList(L);
	//删除  clear清空
	it = L.begin();
	L.erase(it);
	printList(L);
	//remove移除  容器中所有的匹配元素
	L.push_back(10000);
	printList(L);
	L.remove(10000);
	printList(L);
	//清空
	L.clear();
	printList(L);
}

//存取 front back
void test05()
{
	list<int>L;
	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	//不可以用[]或者at方式提供存取方式
	//list 本质是链表不是连续的线性空间存储数据，迭代器也不支持跳跃访问
	cout << "first elem : " << L.front() << endl;
	cout << "last elem : " << L.back() << endl;

	//验证迭代器不支持随机访问
	list<int>::iterator it = L.begin();
	it++; //不支持it=it+1  支持双向
}


bool myCompare(int val1,int val2)
{
	//降序 第一个数大于第二个数
	return val1 > val2;

}

//反转和排序
//将容器中的元素反转，以及将容器中的数据进行排序
//reverse()  sort()
void test06()
{
	list<int>L;
	//尾插
	L.push_back(20);
	L.push_back(10);
	L.push_back(40);
	L.push_back(30);
	cout << "before reverse" << endl;
	printList(L);

	L.reverse();
	cout << "after reverse" << endl;
	printList(L);
	//所有不支持随机访问迭代器的容器，不可以用标准算法
	//不支持随机访问迭代器的内容，内部会提供对应一些算法
	cout << "after sort" << endl;
	L.sort();     //按照升序排列
	printList(L);

	//降序实现
	L.sort(myCompare);
	printList(L);

}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	return 0;
}