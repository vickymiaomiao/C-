#define _CRT_SECURE_NO_WARNINGS 1   
//#include <iostream>
#include "07_func.h"
using namespace std;

int max(int x, int y);

//函数的声明，在编译之前告诉编译器函数的存在
// 声明可以声明多次，但是定义只能有一次
//比较函数，返回较大值
int max(int x, int y)
{
	return x > y ? x : y;
}


//如果函数不需要返回值，声明的时候可以写void,形参变化不会影响实参
void swap(int x, int y)
{
	int temp = 0;
	temp = x;
	x = y;
	y = temp;
	cout << "交换后x" << x << endl;
	cout << "交换后y" << y << endl;
}

//函数的常见形式
//1.无参数无返回值
void test01()
{
	cout << "test01" << endl;
}

//2.有参数无返回值
void test02(int a)
{
	cout << "test02 " << a << endl;
}

//3.无参数有返回值

int test03()
{
	return 0;
}

//4.有参数有返回值
//函数的定义,形参，函数调用时传入的参数为实参
int add(int num1, int num2)
{
	return num1 + num2;
}

int main07()
{
	int a = 10, b = 3;
	cout << "相加的和为：" << add(a, b) << endl;
	swap(a, b);
	test01();
	test02(4);
	int num1 = test03();
	cout << "num1 " << num1 << endl;
	cout << "最大值为" << max(a, b) << endl;


	return 0;
}