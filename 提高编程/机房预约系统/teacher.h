#pragma once
#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
using namespace std;
#include "identity.h"

class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int empid, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void vaildOrder();

	//ѧ��ѧ��
	int m_EmpId;

};