#define _CRT_SECURE_NO_WARNINGS 1   
#include "14_05circle.h"


//���ð뾶
void Circle::setR(int r)
{
	m_R = r;
}
//��ȡ�뾶
int Circle::getR()
{
	return m_R;
}
void Circle::setCenter(Point center)
{
	m_center = center;
}
Point Circle::getcenter()
{
	return m_center;
}
//�жϵ��Բ�Ĺ�ϵ
void Circle::isincircle(Circle& c, Point& p)
{
	//��������֮������ƽ��
	int distance = (c.getcenter().getP_X() - p.getP_X()) * (c.getcenter().getP_X() - p.getP_X()) +
		(c.getcenter().getP_Y() - p.getP_Y()) * (c.getcenter().getP_Y() - p.getP_Y());
	int rdistance = c.getR() * c.getR();
	if (distance == rdistance)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance > rdistance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}
