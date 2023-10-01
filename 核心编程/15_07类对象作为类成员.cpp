#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <string>
using namespace std;

/*
* C++类中的成员可以是另一个类的对象，我们称该成员为对象成员
* 当其他类的对象作为本类的成员时，先构造其他类的对象，在构造自身
* 析构的顺序是先析构自身，再析构其他类，与构造相反
*/
//手机类
class phone
{
public:
	//构造函数进行初始化
	phone(string name)
	{
		m_PName = name;
		cout << "phone" << endl;
	}
	string m_PName;

	~phone()
	{
		cout << "phone析构" << endl;
	}
};

//人类
class person 
{
public:
	//初始化列表的方式进行赋值
	//phone m_phone=pname;
	person(string name,string pname):m_name(name),m_phone(pname)
	{
		cout << "person" << endl;
	}
	string m_name;
	phone m_phone;

	~person()
	{
		cout << "person析构" << endl;
	}
};

void test01()
{
	person p("vicky", "iphone 13");
	cout << p.m_name << " takes " << p.m_phone.m_PName << endl;

}

int main()
{
	test01();
	return 0;
}