#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <string>

using namespace std;

/*
* 成员函数做友元
*/
class Building;

class GoodGay
{
public:
	GoodGay();

	void visit(); //visit可以访问Building中的私有成员
	void visit2();  //visit不可以访问私有成员

	Building* building;
	
};

class Building
{
	friend void GoodGay::visit();//告诉编译器goodgay下的visit函数是building的友元
public:
	Building();
public:
	string m_sittingroom;
private:
	string m_bedroom;
};

//类外实现成员函数
Building::Building()
{
	m_sittingroom = "sr";
	m_bedroom = "br";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "visit访问" << building->m_sittingroom << endl;
	cout << "visit访问" << building->m_bedroom << endl;
}

void GoodGay::visit2()
{
	cout << "visit2访问" << building->m_sittingroom << endl;
	//cout << "visit访问" << building->m_bedroom << endl;  未做声明，不可以访问
}

void test01()
{
	GoodGay g;
	g.visit();
	g.visit2();
}


int main()
{
	test01();
	return 0;
}
