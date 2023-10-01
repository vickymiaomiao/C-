#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;

/*
* 多态是C++面向对象三大特性之一
* 多态分为两类
* 1.静态多态：函数重载和运算符重载属于静态多态，复用函数名
* 2.动态多态：派生类和虚函数实现运行时多态
* 
* 静态多态和动态多态区别：
* 静态多态的函数地址早绑定-编译阶段确定函数地址
* 动态多态的函数地址晚绑定-运行阶段确定函数地址
* 
* 动态多态满足条件
* 1.有继承关系
* 2.子类要重写父类的虚函数
* 
* 重写：函数返回值类型 函数名 参数列表 完全想用
* 
* 动态多态的使用：
* 父类的指针或者引用 指向子类对象
*/

class Animal
{
public:
	//虚函数，实现地址晚绑定
	virtual void speak()
	{
		cout << "Animal speak" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "cat speak" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "dog speak" << endl;
	}
};
//执行说话的函数
//地址早绑定，在编译阶段确定了函数的地址
//如果想执行让猫说话，那么这个函数的地址不能提前绑定，需要地址晚绑定
void doSpeak(Animal& animal) // Animal& animal = cat 父类的引用指向子类对象
{
	animal.speak();
}

void test01()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}


int main()
{
	test01();
	return 0;
}

