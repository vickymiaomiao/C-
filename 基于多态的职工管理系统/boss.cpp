#define _CRT_SECURE_NO_WARNINGS 1   
#include "boss.h"


//构造函数
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//子类重写父类中的纯虚函数virtual可删可不删
void Boss::ShowInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：管理所有事务" << endl;
}
string Boss::getDeptName()
{
	return string("总裁");
}