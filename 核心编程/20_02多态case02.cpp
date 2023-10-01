#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* 分别用普通写法和多态技术，设计实现两个操作数进行运算的计算器类
* 多态的优点：
* 1.代码组织结构清晰
* 2.可读性强
* 3.利于前期和后期维护
* 
* C++开发提倡利用多态设计程序架构，因为多态有点很多
*/

//普通写法
class Calaulator
{
public:
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		//如果想扩展新的操作，需要修改新的源码
		//在真实的开发中，提倡开闭原则
		//开闭原则：对扩展进行开放，对修改进行关闭

	}
	int m_Num1;   //操作数1
	int m_Num2;    //操作数2
};

void test01()
{
	Calaulator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << " + " << c.m_Num2 <<" = " << c.getResult("+") << endl;
	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}


//利用多态实现计算器
//实现计算器的基类
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}

	int m_Num1;
	int m_Num2;
};

//加法计算器的类
class AddCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_Num1 + m_Num2;
	}
};

//减法计算器的类
class SubCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_Num1 - m_Num2;
	}
};
//乘法
class MulCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_Num1 * m_Num2;
	}
};

void test02()
{
	//多态使用条件
	//父类指针或者引用指向子类对象
	
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;

	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
	//堆区创建的数据用完后记得销毁
	delete abc;   //销毁后指针还在
	//减法运算
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
	//乘法运算
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
}

int main()
{
	test01();
	test02();
	return 0;
}