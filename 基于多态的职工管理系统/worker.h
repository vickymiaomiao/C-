#pragma once
#include <iostream>
#include <string>
using namespace std;

//ְ��������
//���麯��

class Worker
{
public:
	//��ʾ������Ϣ
	virtual void ShowInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;
	//����
	int m_Id;
	string m_Name;
	int m_DeptId;  //ְ�����
};


