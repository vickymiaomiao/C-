#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;


/*
* 函数重载调用操作符的类，其对象常称为函数对象
* 函数对象使用重载的()时，行为类似函数调用，也叫做仿函数
* 函数对象（仿函数）是一个类，也叫做仿函数
* 函数对象的特点：
* 函数对象在使用时，可以向普通函数那样调用，可以参数，可以有返回值
* 函数对象超出普通函数的概念，函数对象可以有自己的状态
* 函数对象可以作为参数传递
*/

class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test01()
{
	MyAdd myadd;
	cout << myadd(10, 10) << endl;
}

class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		this->count++;
	}
	int count;//记录内部自己被调用的状态
};

void test02()
{
	MyPrint myprint;
	myprint("hello");
	cout << "times:" << myprint.count << endl;
}


int main()
{
	test01();
	test02();
	return 0;
}