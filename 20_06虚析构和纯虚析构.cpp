#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;

/*
* 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
* 解决方式：将父类中的析构函数改为虚析构或者纯虚析构
* 
* 虚析构和纯虚析构的共性：
* 1.可以解决父类指针释放子类对象
* 2.都需要有具体的函数实现
* 
* 虚析构和纯虚析构的区别：
* 如果是纯虚析构，该类属于抽象类，无法实例化对象
* 
* 虚析构语法：
* virtual ~类名(){}
* 纯虚析构：
* virtual ~类名（）=0；
* 类名::类名(){}
*/

class Animal
{
public:
	Animal()
	{
		cout << "animal" << endl;
	}
	//纯虚函数
	virtual void speak() = 0;
	//利用虚析构可以解决父类指针释放子类对象时不干净的问题
	virtual ~Animal() = 0;  //纯虚析构声明
	//virtual ~Animal()
	//{
	//	cout << "~animal" << endl;
	//}
};

//纯虚析构函数实现
Animal::~Animal()
{
	cout << "animal 纯虚析构" << endl;
}


class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "cat" << endl;
		m_Name = new string(name);
	}
	virtual void speak()
	{
		cout << *m_Name<<" cat speak" << endl;
	}
	string* m_Name;

	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "~cat " << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
};

void test01()
{
	Animal* animal = new Cat("vicky");
	animal->speak();
	delete animal;

}


int main()
{
	test01();
	return 0;
}