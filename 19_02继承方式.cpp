#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <string>

using namespace std;
/*
* 继承方式
* 1.公共继承
* 2.保护继承
* 3.私有继承
*/
//公共继承
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class son1 :public Base1
{
	void func()
	{
		m_A = 10; //父类中的公共权限成员到子类中依旧是公共权限
		m_B = 10;//父类中的保护权限成员到子类中依然是保护权限成员
		//m_C = 10;  父类中的私有成员子类无法访问
	}
};

void test01()
{
	son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100;到了son1中是保护权限类外访问不到
}
//保护继承
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class son2 :protected Base2
{
public:
	void func()
	{
		m_A = 100; //父类公共成员到子类中变为保护成员
		m_B = 100;//父类中的保护成员到子类中变为保护成员
		//m_C = 100;//父类中的私有成员子类访问不到
	}
};

void test02()
{
	son2 s2;
	//s2.m_A = 100;  到子类中变为保护权限无法访问
	//s2.m_B = 100;  到子类中变为保护权限无法访问
	//s2.m_C = 100;  到子类中变为保护权限无法访问
}

//私有继承
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class son3 :private Base3
{
	void func()
	{
		m_A = 100; //公共->私有
		m_B = 100;//保护->私有
		//m_C=100;  子类不可以访问父类中的私有成员
	}
};

void test03()
{
	son3 s3;
	//s3.m_A = 100;  父类中的公共成员到子类中变为私有成员，私有成员类外不可以访问
	//s3.m_B = 100;
	//s3.m_C = 100;
}
//孙子类，测试son3中的私有继承
class Grandson3 :public son3
{
public:
	void func()
	{
		//全部是私有成员，不可以继承
	/*	m_A = 100;
		m_B = 100;
		m_C = 100;*/
	}
};

int main()
{
	test01();
	return 0;
}