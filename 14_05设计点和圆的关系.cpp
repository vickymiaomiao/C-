#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
#include "14_05point.h"
#include "14_05circle.h"
using namespace std;

//���һ��Բ���һ�����࣬������Բ�Ĺ�ϵ
//1.����԰�ڣ�����Բ�⣬����Բ��

//class Point
//{
//public:
//	//���õ��X,Y����
//	void setP_X(int x)
//	{
//		p_X = x;
//	}
//	//��ȡX����
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
//Բ

//class Circle
//{
//public:
//	//���ð뾶
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	//��ȡ�뾶
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
//	//�жϵ��Բ�Ĺ�ϵ
//	void isincircle(Circle &c,Point &p)
//	{
//		//��������֮������ƽ��
//		int distance = (c.getcenter().getP_X() - p.getP_X()) * (c.getcenter().getP_X() - p.getP_X()) +
//			(c.getcenter().getP_Y() - p.getP_Y()) * (c.getcenter().getP_Y() - p.getP_Y());
//		int rdistance = c.getR() * c.getR();
//		if (distance == rdistance)
//		{
//			cout << "����Բ��" << endl;
//		}
//		else if (distance > rdistance)
//		{
//			cout << "����Բ��" << endl;
//		}
//		else
//		{
//			cout << "����Բ��" << endl;
//		}
//	}
//private:
//	int m_R;  //�뾶
//	Point m_center;  //Բ��
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
