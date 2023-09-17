#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;
/*
* 函数调用元素运算符也可以重载
* 由于重载后使用的方式非常像函数的调用，因此成为仿函数
* 仿函数没有固定写法，非常灵活
* 
* 匿名函数对象
*/
class MyPrint
{
public:
	//重载函数调用运算符
	void operator()(string test)
	{
		cout << test << endl;
	}
};
//加法类
class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void myprint02(string test)
{
	cout << test << endl;
}

void test01()
{
	MyPrint myprint;
	myprint("hello world");
	myprint02("hello,vicky");
}

void test02()
{
	MyAdd m1;
	int ret = m1(100, 100);
	cout << "ret=" << ret << endl;
	//匿名函数对象
	cout << MyAdd()(100, 200) << endl;

}


int main()
{
	test01();
	test02();
	return 0;
}