#pragma once
//�ϰ�
#include <iostream>
using namespace std;
#include "worker.h"

class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int did);
	//������д�����еĴ��麯��virtual��ɾ�ɲ�ɾ
	virtual void ShowInfo();
	virtual string getDeptName();
};

