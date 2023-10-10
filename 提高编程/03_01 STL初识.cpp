#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <vector>
#include <algorithm> //算法标准库
using namespace std;


/*
* 为了建立数据结构和算法的一套标准，诞生了STL
* STL（standard Template Library）标准模板库
* 广义上分为：容器（container）、算法(algorithm)、迭代器(iterator)
* 容器和算法之间通过迭代器进行无缝连接
* STL几乎所有的代码都带用了模板类或者模板函数
* 
* STL六大组件：
* 1.容器：各种数据结构，如vector/list/deque/set/map等，用来存放数据
* 2.算法：各种常用算法，如sort/find/copy/for_each等
* 3.迭代器：扮演了容器与算法之间的胶合剂
* 4.仿函数：行为类似函数，可作为算法的某种策略
* 5.适配器（配接器）：一种用来修饰容器或者仿函数或迭代器接口的东西
* 6.空间配置器：负责空间的配置与管理
*/

/*
* 容器：将应用最广泛的数据结构实现出来
* 序列式容器：强调值的顺序
* 关联式容器：二叉树结构
* 
* 算法：解决问题
* 质变算法：是指运算过程中会更改区间内的元素内容。例如拷贝，替换，删除等等
* 非质变算法：运算过程中不会改变区间中的内容，例如查找、计数、遍历、寻找极值等。
* 
* 迭代器：算法通过迭代器才能访问容器中的元素
* 每个容器都有自己专属的迭代器
* 迭代器非常类似于指针
* 种类：
* 输入迭代器-》只读
* 输出迭代器-》只写
* 前向迭代器-》读写，并能向前推进
* 双向迭代器-》读写，可以向前或者向后
* 随机访问迭代器-》读写，可以跳跃访问任意数据，功能最强的迭代器
* 常用容器中的迭代器种类为双向迭代器和随机访问迭代器
*/

/*
* 存放内置数据类型
* 容器：vector
* 算法：for_each
* 迭代器：vector<int>::iterator
*/

void myPrint(int val)
{
	cout << val << endl;
}

void test01()
{
	//创建了一个vector容器，数组
	vector<int> v;
	//向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	////通过迭代器访问容器中的数据
	//vector<int>::iterator itBegin = v.begin();  //起始迭代器，指向第一个元素
	//vector<int>::iterator itEnd = v.end(); //结束迭代器，指向结束元素下一个迭代器的位置
	////第一种遍历方式
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}
	//第二种遍历方式
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << endl;
	//}
	//第三种遍历方式
	for_each(v.begin(), v.end(), myPrint);  //利用回调函数技术，打印数据
}

int main()
{
	test01();
	return 0;
}