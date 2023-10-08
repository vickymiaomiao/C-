#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* 普通函数与函数模板的区别：
* 1.普通函数调用时可以发生自动类型转换（隐式类型转换）
* 2.函数模板调用时，如果利用自动类型推导，不会发生隐式类型转化
* 3.如果利用显示指定类型的方式，可以发生隐式类型转换
*/
int myadd01(int a, int b)
{
	return a + b;
}

//函数模板
template<class T>
T myadd02(T a, T b)
{
	return a + b;
}

void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	cout << myadd01(a, b) << endl;
	cout << myadd01(a, c) << endl; //隐式类型转换

	//自动类型推导
	cout << myadd02(a, b) << endl;
	//cout << myadd02(a, c) << endl;
	//显示指定类型
	cout << myadd02<int>(a, c) << endl;
	

}

int main()
{
	test01();
	return 0;
}