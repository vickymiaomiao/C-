#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* 调用规则如下：
* 1.如果函数模板和普通函数都可以实现，优先调用普通函数
* 2.可以通过空模板列表来强制调用函数模板
* 3.函数模板也可以发生重载
* 4.如果函数模板可以产生更好的匹配，优先调用函数模板
* 
* 注意：提供函数模板就不要提供普通函数，容易产生二义性
*/

void myprint(int a, int b)
{
	cout << "normal func" << endl;
}

template<class T>
void myprint(T a, T b)
{
	cout << "template func" << endl;
}

template<class T>
void myprint(T a, T b,T c)
{
	cout << "template func 重载" << endl;
}

void test01()
{
	int a = 10, b = 20;
	char c1 = 'a';
	char c2 = 'b';
	myprint(a, b);
	//通过空模板参数列表
	myprint<>(a, b);
	myprint(a, b, 10);//重载
	myprint(c1, c2);//调用模板，更好的匹配
}







int main()
{
	test01();
	return 0;
}