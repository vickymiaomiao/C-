#pragma once
//管理类
#include <iostream>
using namespace std;
#include "worker.h"

class Manager :public Worker
{
public:
	//构造函数
	Manager(int id, string name, int did);
	//子类重写父类中的纯虚函数virtual可删可不删
	virtual void ShowInfo();
	virtual string getDeptName();
};
