#pragma once
#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
using namespace std;
#include "identity.h"
#include "orderFile.h"
#include <vector>

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

	//���ԤԼ
	void vaildOrder();

	//ѧ��ѧ��
	int m_EmpId;

};