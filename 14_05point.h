#pragma once
#include <iostream>
using namespace std;

//����
class Point
{
public:
	//���õ��X,Y����
	void setP_X(int x);

		//��ȡX����
	int getP_X();

	void setP_Y(int y);

	int getP_Y();


private:
	int p_X;
	int p_Y;
};