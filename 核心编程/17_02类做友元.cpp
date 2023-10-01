#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* 类做友元
*/

class building;
//好朋友类
class GF
{
public:
	GF();
	void visit();//参观函数访问BUilding中的公共和私有属性
	building* b;

};
//建筑物类
class building
{
	friend class GF; //GF类是本类的好朋友，可以访问本类的私有成员
public:
	building();  //通过构造函数赋初值
	//{
	//	m_SittingRoom = "sittingroom";
	//	m_BedRoom = "bedroom";
	//}
public:
	string m_SittingRoom;

private:

	string m_BedRoom;
};

//类外写成员函数
building::building()
{
	m_SittingRoom = "sittingroom";
	m_BedRoom = "bedroom";
}

GF::GF()
{
	//创建一个建筑物的对象
	b = new building;  //在堆区创建对象，并将地址返回给对象b
}
void GF::visit()
{
	cout << "访问:" << b->m_SittingRoom << endl;
	cout << "访问:" << b->m_BedRoom << endl;
}

void test01()
{
	GF gf;
	gf.visit();
}

int main()
{
	test01();
	return 0;
}