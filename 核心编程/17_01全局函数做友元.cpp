#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>

using namespace std;

/*
* ��Ԫ��Ŀ������һ�������������������һ�����е�˽�г�Ա
* ��Ԫ�Ĺؼ���Ϊfriend
* ȫ�ֺ�������Ԫ
* 
*/

//������
class building 
{
	//goodfriendȫ�ֺ�����building�ĺ����ѣ����Է���building�е�˽�г�Ա
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

//ȫ�ֺ���
void goodfriend(building *building)
{
	cout << "���ʣ�" << building->m_SittingRoom << endl;
	cout << "���ʣ�" << building->m_BedRoom << endl;
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
