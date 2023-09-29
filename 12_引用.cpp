#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;


//引用的作用，给变量起别名
//int a=10;
//语法：数据类型 &别名=原名
//引用必须要初始化
//引用一旦初始化后就不可以更改

//引用做函数参数，函数传参时，可以利用引用计数让形参修饰实参
//交换函数

//值传递
void myswap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "swap01_a= " << a << endl;
	cout << "swap01_b= " << b << endl;
}
//地址传递
void myswap02(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
//引用传递
void myswap03(int& a, int& b)
{
	int temp = a;
	a = b; 
	b = temp;

}

//引用做函数的返回值
//1.不要返回局部变量的引用
//2.函数的调用可以作为左值
int& yinyong01()  //返回引用
{
	static int a = 300;//局部变量，存放在栈区，加上static之后存放在全局区
	//全局区上的数据在程序结束后系统释放
	return a;  //返回a的引用，a的变量
}

//引用的本质在c++内部实现是一个指针常量
//int * const ref = &a;指针常量的指向不可更改

//打印数据的函数
void showvalue(const int &val)  //修饰形参，不能进行修改
{
	//val = 1000;
	cout <<"val=" << val << endl;
}
 


int main12()
{
	//常量引用：修饰形参，防止误操作
	int x = 90;
	//加上const之后，编译器将代码修改为int temp=10;int &ref=temp;加上const之后变为只读，不可修改
	//const int& y = x;//引用必须引一块合法的内存
	showvalue(x);
	
	//int a = 10;
	//int &b = a;//别名为b
	//b = 20;
	//cout << a << endl;
	int& ref = yinyong01();
	cout << "ref=" <<  ref << endl;
	yinyong01() = 1000;  //如果函数的返回值是引用，这个函数调用可以作为左值
	cout << "ref=" << ref << endl;
	int a = 10;
	int b = 20;
	myswap01(a, b);  //值传递，形参不会修饰实参
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	myswap02(&a, &b);  //地址传递，形参会修饰实参
	cout << "swap02 a= " << a << endl;
	cout << "swap02 b= " << b << endl;
	myswap03(a, b); //引用传递，形参会修饰实参
	cout << "swap03 a= " << a << endl;
	cout << "swap03 b= " << b << endl;

	return 0;
}