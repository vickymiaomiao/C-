#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* ������Ԫ
*/

class building;
//��������
class GF
{
public:
	GF();
	void visit();//�ιۺ�������BUilding�еĹ�����˽������
	building* b;

};
//��������
class building
{
	friend class GF; //GF���Ǳ���ĺ����ѣ����Է��ʱ����˽�г�Ա
public:
	building();  //ͨ�����캯������ֵ
	//{
	//	m_SittingRoom = "sittingroom";
	//	m_BedRoom = "bedroom";
	//}
public:
	string m_SittingRoom;

private:

	string m_BedRoom;
};

//����д��Ա����
building::building()
{
	m_SittingRoom = "sittingroom";
	m_BedRoom = "bedroom";
}

GF::GF()
{
	//����һ��������Ķ���
	b = new building;  //�ڶ����������󣬲�����ַ���ظ�����b
}
void GF::visit()
{
	cout << "����:" << b->m_SittingRoom << endl;
	cout << "����:" << b->m_BedRoom << endl;
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