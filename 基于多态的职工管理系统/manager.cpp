#define _CRT_SECURE_NO_WARNINGS 1   
#include "manager.h"


//���캯��
Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//������д�����еĴ��麯��virtual��ɾ�ɲ�ɾ
void Manager::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲��·���Ա��" << endl;
}
string Manager::getDeptName()
{
	return string("����");
}