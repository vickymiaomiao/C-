#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <string>

using namespace std;

/*
* ��Ա��������Ԫ
*/
class Building;

class GoodGay
{
public:
	GoodGay();

	void visit(); //visit���Է���Building�е�˽�г�Ա
	void visit2();  //visit�����Է���˽�г�Ա

	Building* building;
	
};

class Building
{
	friend void GoodGay::visit();//���߱�����goodgay�µ�visit������building����Ԫ
public:
	Building();
public:
	string m_sittingroom;
private:
	string m_bedroom;
};

//����ʵ�ֳ�Ա����
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
	cout << "visit����" << building->m_sittingroom << endl;
	cout << "visit����" << building->m_bedroom << endl;
}

void GoodGay::visit2()
{
	cout << "visit2����" << building->m_sittingroom << endl;
	//cout << "visit����" << building->m_bedroom << endl;  δ�������������Է���
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
