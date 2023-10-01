#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

//设计立方体类

class Cube
{
public:
	//行为
	//设置长宽高
	// 获取长宽高
	void setm_L(int l)
	{
		m_L = l;
	}
	int getm_L()
	{
		return m_L;
	}
	void setm_W(int w)
	{
		m_W = w;
	}
	int getm_W()
	{
		return m_W;
	}
	void setm_H(int h)
	{
		m_H = h;
	}
	int getm_H()
	{
		return m_H;
	}
	
	//获取立方体面积
	int calculateS()
	{
		return 2 * m_L * m_H + 2 * m_L * m_W + 2 * m_W * m_H;
	}
	//获取立方体体积
	int calculateV()
	{
		return m_L * m_H * m_W;
	}
	//利用成员函数判断两个立方体是否相等,传入立方体
	bool isSameByClass(Cube &c)
	{
		if (getm_L() == c.getm_L() &&getm_H() == c.getm_H() && getm_W() == c.getm_W())
		{
			return true;
		}
		return false;

	}
	

private:
	int m_L;
	int m_H;
	int m_W;
};


//利用全局函数判断两个立方体是否相等
bool isSame(Cube& c1, Cube& c2)
{
	if (c1.getm_L() == c2.getm_L() && c1.getm_H() == c2.getm_H() && c1.getm_W() == c2.getm_W())
	{
		return true;
	}
	return false;
}



int main1404()
{
	Cube c1;
	c1.setm_L(10);
	c1.setm_W(10);
	c1.setm_H(10);
	cout << "面积：" << c1.calculateS()<< endl;
	cout << "体积：" << c1.calculateV() << endl;
	
	//创建第二个立方体
	Cube c2;
	c2.setm_L(10);
	c2.setm_W(10);
	c2.setm_H(1);
	//利用全局函数判断结果
	bool ret = isSame(c1, c2);
	if (ret)
	{
		cout << "全局函数判断两个立方体相等" << endl;
	}
	else 
	{
		cout << "全局函数判断不相等" << endl;
	}
	//利用成员函数判断
	ret = c1.isSameByClass(c2);
	if (ret)
	{
		cout << "成员函数判断两个立方体相等" << endl;
	}
	else
	{
		cout << "成员函数判断不相等" << endl;
	}

	return 0;
}