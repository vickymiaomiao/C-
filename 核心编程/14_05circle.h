#pragma once
#include <iostream>
#include "14_05point.h"
using namespace std;

class Circle
{
public:
	//���ð뾶
	void setR(int r);

		//��ȡ�뾶
	int getR();

	void setCenter(Point center);

	Point getcenter();

		//�жϵ��Բ�Ĺ�ϵ
	void isincircle(Circle& c, Point& p);
	
private:
	int m_R;  //�뾶
	Point m_center;  //Բ��

};
