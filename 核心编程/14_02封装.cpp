#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

//访问权限
//1.public     成员在类内可以访问,类外可以访问
//2.protected  类内可以访问，类外不可以访问  儿子也可以访问父亲中保护的内容
//3.private    类内可以访问，类外不可以访问  儿子不可以访问父亲的私有内容


class Person
{
	//公共权限的成员
public:
	string m_name;
	//保护权限
protected:
	string m_car;
	//私有权限
private:
	int m_pwd;

public:
	void func140201()
	{
		m_name = "vicky";
		m_car = "BYD";
		m_pwd = 12345;
		cout << m_name << "  " << m_car << "  " << m_pwd << endl;
	}
};

//struct和class和区别在于默认的访问权限不同，struct默认权限为公共，class默认权限为私有
class C1
{
	int m_A; //默认权限为私有
};
struct C2
{
	int m_b;//默认是公共权限
};



int main1402()
{
	C1 c1;
	//c1.m_A = 100;私有变量，不可以访问
	C2 c2;
	c2.m_b = 100;  //公共权限可以访问
	Person p1;
	p1.m_name = "andy";
	//p1.m_car = "LX";  保护权限内容在类外不可以访问
	//p1.m_pwd=12;私有权限的成员类外也不可以访问
	p1.func140201();
	return 0;
}