#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

/*
* 继承的好处，减少重复的代码
* 语法：class 子类：继承方式 父类
* 子类也为派生类
* 父类也称为基类
* 
* 派生类的成员，包含两大部分
* 一类是从基类继承过来的，一类是自己增加的成员
* 从基类继承过来的表现其共性，而新增的成员体现了其个性
*/
//公共页面类称
class BasePage
{
public:
	void header()
	{
		cout << "header" << endl;
	}
	void footer()
	{
		cout << "footer" << endl;
	}
	void left()
	{
		cout << "left" << endl;
	}
};

//java页面
class Java :public BasePage
{
public:
	void content()
	{
		cout << "Java" << endl;
	}
};

//python页面
class Python :public BasePage
{
public:
	void content()
	{
		cout << "python" << endl;
	}
};

class Cpp :public BasePage
{
public:
	void content()
	{
		cout << "Cpp" << endl;
	}
};

void test01()
{
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "------------------------" << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "------------------------" << endl;
	Cpp cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
	cout << "------------------------" << endl;

}

int main()
{
	test01();
	return 0;
}