#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;
/*
* 利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
*/
class AbstractDrinking
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;
	//制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//制作咖啡
class Coffee :public AbstractDrinking
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "boil water" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "brew coffee" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "pour in cup" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "put suger and milk" << endl;
	}
};

//制作茶叶
class Tea :public AbstractDrinking
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "boil water" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "brew tea" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "pour in cup" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "put suger and fruit" << endl;
	}
};
//制作
void doWork(AbstractDrinking *abs)
{
	abs->makeDrink();     
	delete abs;  //释放堆区数据，避免内存泄露
}

void test01()
{
	//制作咖啡
	doWork(new Coffee);   //父类指针指向子类对象，一个接口有多重形态
	cout << "------------------" << endl;
	doWork(new Tea);
}

int main()
{
	test01();
	return 0;
}