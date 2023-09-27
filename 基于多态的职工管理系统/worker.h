#pragma once
#include <iostream>
#include <string>
using namespace std;

//职工抽象类
//纯虚函数

class Worker
{
public:
	//显示个人信息
	virtual void ShowInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;
	//属性
	int m_Id;
	string m_Name;
	int m_DeptId;  //职工编号
};


