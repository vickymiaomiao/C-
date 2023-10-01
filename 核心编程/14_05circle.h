#pragma once
#include <iostream>
#include "14_05point.h"
using namespace std;

class Circle
{
public:
	//设置半径
	void setR(int r);

		//获取半径
	int getR();

	void setCenter(Point center);

	Point getcenter();

		//判断点和圆的关系
	void isincircle(Circle& c, Point& p);
	
private:
	int m_R;  //半径
	Point m_center;  //圆心

};
