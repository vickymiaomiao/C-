#pragma once
//��ͨԱ��
#include <iostream>
using namespace std;
#include "worker.h"

class Employee :public Worker
{
public:
	//���캯��
	Employee(int id, string name, int did);
	//������д�����еĴ��麯��virtual��ɾ�ɲ�ɾ
	virtual void ShowInfo();
	virtual string getDeptName();
};

