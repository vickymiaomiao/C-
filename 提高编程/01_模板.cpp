#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;


/*
* 主要针对泛型编程和STL技术
* 模板：建立通用的模具，大大的提高复用性
* 特点：模板不可以直接使用，它只是一个框架
* 模板的通用并不是万能的
* 
* 提供两种模板机制：函数模板和类模板
* 
* 函数模板作用：
* 建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表
* 语法：template<typename T>  函数声明和定义
* template --- 声明创建模板
* typename --- 表明其后面的符号是一种数据类型，可以用class代替
* T --- 通用的数据类型，名称可以替换，通常为大写字母
* 
*/

//交换两个整型函数
void swapint(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//交换两个浮点型函数
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//函数模板
template<typename T>  //声明一个模板，告诉编译器后面代码中紧跟着的T不要报错
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10, b = 20;
	swapint(a, b);
	//利用函数模板进行交换
	//有两种方式
	//1.自动类型推到
	mySwap(a, b);
	//2.显示指定类型使用<>指定数据类型
	mySwap<int>(a, b);
	cout << "a=" << a << " , " << "b=" << b << endl;

	double c = 3.14, d = 2.34;
	swapDouble(c, d);
	cout << "c=" << c << " , " << "d=" << d << endl;
}

int main()
{
	test01();
	return 0;
}