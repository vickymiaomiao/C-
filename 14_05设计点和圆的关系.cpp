#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
#include "14_05point.h"
#include "14_05circle.h"
using namespace std;

//设计一个圆类和一个点类，计算点和圆的关系
//1.点在园内，点在圆外，点在圆上

//class Point
//{
//public:
//	//设置点的X,Y坐标
//	void setP_X(int x)
//	{
//		p_X = x;
//	}
//	//获取X坐标
//	int getP_X()
//	{
//		return p_X;
//	}
//	void setP_Y(int y)
//	{
//		p_Y = y;
//	}
//	int getP_Y()
//	{
//		return p_Y;
//	}
//
//private:
//	int p_X;
//	int p_Y;
//};
//圆

//class Circle
//{
//public:
//	//设置半径
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	//获取半径
//	int getR()
//	{
//		return m_R;
//	}
//	void setCenter(Point center)
//	{
//		m_center = center;
//	}
//	Point getcenter()
//	{
//		return m_center;
//	}
//	//判断点和圆的关系
//	void isincircle(Circle &c,Point &p)
//	{
//		//计算两点之间距离的平方
//		int distance = (c.getcenter().getP_X() - p.getP_X()) * (c.getcenter().getP_X() - p.getP_X()) +
//			(c.getcenter().getP_Y() - p.getP_Y()) * (c.getcenter().getP_Y() - p.getP_Y());
//		int rdistance = c.getR() * c.getR();
//		if (distance == rdistance)
//		{
//			cout << "点在圆上" << endl;
//		}
//		else if (distance > rdistance)
//		{
//			cout << "点在圆外" << endl;
//		}
//		else
//		{
//			cout << "点在圆内" << endl;
//		}
//	}
//private:
//	int m_R;  //半径
//	Point m_center;  //圆心
//	
//};


int main1405()
{
	Circle c1;
	c1.setR(10);
	Point p1;
	p1.setP_X(0);
	p1.setP_Y(0);
	c1.setCenter(p1);
	Point p2;
	p2.setP_X(0);
	p2.setP_Y(10);
	c1.isincircle(c1, p2);

	return 0;
}
