#define _CRT_SECURE_NO_WARNINGS 1   
#include "manager.h"


//构造函数
Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//子类重写父类中的纯虚函数virtual可删可不删
void Manager::ShowInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成老板交给的任务，并下发给员工" << endl;
}
string Manager::getDeptName()
{
	return string("经理");
}