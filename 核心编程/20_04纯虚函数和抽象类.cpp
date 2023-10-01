#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/* 
*在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
*因此可以将虚函数改为纯虚函数
*纯虚函数语法：virtual 返回值类型 函数名 （参数列表）= 0;
*当类中有了纯虚函数，这个类也成为了抽象类
*
* 抽象类特点：
* 1.无法实例化对象
* 2.子类必须重写抽象类中的纯虚函数，否则也属于抽象类
*/

class Base
{
public:
	//只要有一个纯虚函数，这个类称为抽象类
	virtual void func() = 0;     //纯虚函数
};

class Son :public Base
{
public:
	void func()
	{
		cout << "func()" << endl;
	}

};


void test01()
{
	//Base b;   抽象类无法实例化对象
	//new Base   抽象类无法实例化对象
	//Son s;    子类不重写纯虚函数，无法创建对象
	Base * b=new Son;  //多态的方式调用
	b->func();

}


int main()
{
	test01();
	return 0;
}