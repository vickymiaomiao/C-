#define _CRT_SECURE_NO_WARNINGS 1   
#include "boss.h"


//���캯��
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//������д�����еĴ��麯��virtual��ɾ�ɲ�ɾ
void Boss::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ�𣺹�����������" << endl;
}
string Boss::getDeptName()
{
	return string("�ܲ�");
}