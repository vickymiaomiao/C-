#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

//函数模板注意事项

template<typename T>  //typename可以替换成class
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//1.自动类型推导，必须要推导出一致的数据类型T才可以使用
void test01()
{
	int a = 10, b = 20;
	char c = 'c';
	mySwap(a, b);
	//mySwap(a, c);   错误，推导出的数据类型不一致
	cout << "a=" << a << " , " << "b=" << b << endl;
}

//2.模板必须要确定出T的数据类型才可以使用
template<class T>
void func()
{
	cout << "func test" << endl;
}

void test02()
{
	//func();//没有指定数据类型T
	func<int>();
}

int main()
{
	test01();
	test02();
	return 0;
}