#pragma once
//������
#include <iostream>
using namespace std;
#include "worker.h"

class Manager :public Worker
{
public:
	//���캯��
	Manager(int id, string name, int did);
	//������д�����еĴ��麯��virtual��ɾ�ɲ�ɾ
	virtual void ShowInfo();
	virtual string getDeptName();
};
