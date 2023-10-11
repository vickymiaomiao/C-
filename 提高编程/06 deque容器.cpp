#define _CRT_SECURE_NO_WARNINGS 1   
#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>  //使用算法时需要包含的
using namespace std;

/*
* 双端数组，可以对头端进行插入删除操作
* deque与vector的区别：
* 1.vector头部插入效率低
* 2.deque头部插入删除速度快
* 3.vector访问元素时的速度会比deque快，这两者和内部实现有关
*
* deque容器的迭代器也是支持随机访问的
* 
* deque工作原理：
*内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实的数据
* 中控器维护的是每个缓冲却的地址，使得使用deque时像一片连续的内存空间
*/

void printDeque(const deque<int>& d) //容器只读 防止被修改
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it<<" ";
	}
	cout << endl;
}

//deque的构造函数
void test01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	//使用区间的方式进行
	deque<int>d2(d1.begin(),d1.end());
	printDeque(d2);
	//n个elem
	deque<int>d3(10, 100);
	printDeque(d3);
	//拷贝构造
	deque<int>d4(d3);
	printDeque(d4);
}

//赋值操作
// = assign
void test02()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	//赋值操作
	deque<int>d2;
	d2 = d1;
	printDeque(d2);
	//assign
	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printDeque(d3);
	deque<int>d4;
	d4.assign(10, 100);
	printDeque(d4);
}

//容器大小
//empty size
//resize重新指定的容器长度比原来长，按默认值填充，若比原来短，删除超出元素
void test03()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	if (d1.empty())
	{
		cout << "d1 is empty" << endl;
	}
	else
	{
		cout << "d1 is not empty" << endl;
		cout << "d1 size:" << d1.size() << endl;
		//deque容器没有容量概念
	}
	//重新指定大小
	d1.resize(15);
	printDeque(d1);
	//重载版本，按指定数据进行填充
	d1.resize(20, 3);
	printDeque(d1);
	d1.resize(5);
	printDeque(d1);
}

//插入和删除操作
//插入和删除提供的位置是迭代器
void test04()
{
	deque<int>d1;
	//尾插
	d1.push_back(10);
	d1.push_back(20);
	//头插
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);
	//尾删
	d1.pop_back();
	d1.pop_front();
	printDeque(d1);

	//insert 在哪个位置进行插入
	d1.insert(d1.begin(), 1000);
	d1.insert(d1.begin(),2,10000);
	printDeque(d1);
	//按照区间进行插入
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d1.insert(d1.begin(), d2.begin(), d2.end());
	printDeque(d1);
	//删除操作,按照区间进行删除
	d1.erase(d1.begin());
	d1.erase(d1.begin(),d1.end());   //清除容器
	//clear 清空
	d1.clear();
	printDeque(d1);
}

//存取
//at [] front() back()
void test05()
{
	deque<int>d1;
	//尾插
	d1.push_back(10);
	d1.push_back(20);
	//头插
	d1.push_front(100);
	d1.push_front(200);
	for (int i = 0; i < d1.size(); i++)
	{
		//访问元素
		cout << d1[i] << " ";
		cout << d1.at(i);
	}
	cout << endl;
	cout << "first elem: " << d1.front() << endl;
	cout << "end elem: " << d1.back() << endl;

}

//利用算法实现对deque容器的排序
//sort(beg,end),对区间内的数据进行排序
void test06()
{
	deque<int>d1;
	//尾插
	d1.push_back(10);
	d1.push_back(20);
	//头插
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);
	//对于支持随机访问迭代器的容器，都可以利用sort算法直接对齐进行排序
	//vector容器也可以利用sort进行排序
	sort(d1.begin(), d1.end());  //默认排序规则是升序
	cout << "after sort" << endl;
	printDeque(d1);
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

