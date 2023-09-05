#define _CRT_SECURE_NO_WARNINGS 1   
#include "14_05circle.h"


//设置半径
void Circle::setR(int r)
{
	m_R = r;
}
//获取半径
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
//判断点和圆的关系
void Circle::isincircle(Circle& c, Point& p)
{
	//计算两点之间距离的平方
	int distance = (c.getcenter().getP_X() - p.getP_X()) * (c.getcenter().getP_X() - p.getP_X()) +
		(c.getcenter().getP_Y() - p.getP_Y()) * (c.getcenter().getP_Y() - p.getP_Y());
	int rdistance = c.getR() * c.getR();
	if (distance == rdistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > rdistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}
