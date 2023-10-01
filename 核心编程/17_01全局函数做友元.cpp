#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>

using namespace std;

/*
* 友元的目的是让一个函数或者类进访问另一个类中的私有成员
* 友元的关键字为friend
* 全局函数做友元
* 
*/

//房屋类
class building 
{
	//goodfriend全局函数是building的好朋友，可以访问building中的私有成员
	friend void goodfriend(building* building);
public:
	building()
	{
		m_SittingRoom = "sittingroom";
		m_BedRoom = "bedroom";
	}
public:
	string m_SittingRoom;

private:
	string m_BedRoom;
};

//全局函数
void goodfriend(building *building)
{
	cout << "访问：" << building->m_SittingRoom << endl;
	cout << "访问：" << building->m_BedRoom << endl;
}

void test01()
{
	building b;
	goodfriend(&b);
}

int main()
{
	test01();
	return 0;
}
