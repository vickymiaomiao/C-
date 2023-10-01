#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>

using namespace std;

/*
* 通过重载递增运算符，实现自己的整型数据
* 前置递增返回引用，后置递增返回值
*/

//自定义整型
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);

public:
	MyInteger()
	{
		m_Num = 0;
	}
	//重载前置++运算符
	MyInteger& operator++()  //返回引用是为了一直对一个数据进行操作
	{
		m_Num++;
		return *this;
	}

	//重载后置++运算符
	//int代表占位参数，可以用于区分前置和后置递增
	MyInteger operator++(int)  //
	{
		//先记录当时结果
		MyInteger temp = *this; //后置操作返回值，因为是局部引用
		//后递增
		m_Num++;
		//最后将记录的结果做返回
		return temp;
	}

private:
	int m_Num;
};

//重载左移运算符
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num;
	return cout;
}


void test01()
{
	MyInteger myint;
	cout << ++myint << endl;
}

void test02()
{
	MyInteger myint1;
	cout << myint1++ << endl;
	cout << myint1 << endl;
}


int main()
{
	test01();
	test02();
	return 0;
}