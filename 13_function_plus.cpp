#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>

using namespace std;


//函数形参列表中的形参可以有默认值
//返回值类型 函数名 （参数=默认值）{}
//如果我们自己传入数据，就用传入的数据，如果没有，就用默认值
//注意事项
//1.如果某个位置已有默认参数，那么从这个位置往后都必须要默认值

int defaultpara(int a, int b=20, int c=30)
{
	return a + b + c;
}
int defaultpara1(int a = 10, int b = 10);
//2.如果函数的声明有默认参数，则函数的实现就不能有默认参数
//声明和实现只能有一个有默认参数
int defaultpara1(int a, int b)
{
	return a + b;
}

//函数占位参数，用来占位
//返回值类型 函数名（数据类型）{}
//目前阶段的占位参数暂时用不到，占位参数可以有默认参数
void zhanweifunc(int a, int =10)   //第二个int属于是占位参数
{
	cout << "this is a func" << endl;
}

//函数重载，函数名可以相同，提高复用性
//1.同一作用域下，2.函数名称相同 3.函数参数类型不同或者个数不同或者顺序不同
//函数的返回值不可以作为函数重载的条件
void func1301()
{
	cout << "函数的调用" << endl;
}
//函数重载
void func1301(int a)
{
	cout << "函数的(int a )调用" << endl;
}
void func1301(double a)
{
	cout << "函数的(double a )调用" << endl;
}
void func1301(int a ,double b)
{
	cout << "函数的(int a ,double b)调用" << endl;
}
void func1301( double b, int a)
{
	cout << "函数的(double b, int a)调用" << endl;
}

//函数重载注意事项
//引用作为重载条件
void func1302(int &a) //可读可写
{
	cout << "func1302(int &a)的调用" << endl;
}
//函数参数类型不同
void func1302(const int& a) //只读状态
{
	cout << "func1302(const int &a)的调用" << endl;
}

//函数重载碰到函数默认参数
void func1303(int a )
{
	cout << "func1303(int a )的调用" << endl;
}

//void func1303(int a, int b=10)    出现二义性
void func1303(int a,int b)
{
	cout << "func1303(int a ,int b)的调用" << endl;
}



int main13()
{
	func1303(10); //当函数重载碰到默认参数会出现二义性
	func1303(10,20);
	int a = 10;
	func1302(a);
	func1302(10);
	func1301();
	func1301(10);
	func1301(3.14);
	func1301(10,3.14);
	func1301(3.14,10);
	cout << defaultpara1(1, 30) << endl;
	cout << defaultpara(1,30) << endl;
	zhanweifunc(10);
	return 0;
}