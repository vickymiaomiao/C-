#pragma once
#include <iostream>
using namespace std;

//声明
class Point
{
public:
	//设置点的X,Y坐标
	void setP_X(int x);

		//获取X坐标
	int getP_X();

	void setP_Y(int y);

	int getP_Y();


private:
	int p_X;
	int p_Y;
};