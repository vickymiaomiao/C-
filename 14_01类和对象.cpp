#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

//类和对象：封装、继承、多态
//C++认为万事万物皆为对象，对象上有其属性和行为

//封装，将属性和行为作为一个整体，表现为生活中的事物
//将属性和行为加以权限控制
// class 类名{访问权限：属性/行为};

//设计一个圆类，求圆的周长
const double PI = 3.14;//圆周率

class Circle
{
	//访问权限
public : //公共权限
	int m_r;//半径，//圆的属性
	//行为
	double calculatezc()
	{
		return PI * 2 * m_r;
	}
};

class student
{
public: //公共权限
	//类中的属性和行为，我们同一称为成员
	//属性 成员属性，成员变量
	//行为 成员函数 成员方法
	string m_name;
	int m_ID;
	
	void showinfo()
	{
		cout << "学生的姓名为" <<m_name<< endl;
		cout << "学生的学号为" << m_ID << endl;
	}
	void setName(string name)  //给名字赋值
	{
		m_name = name;
	}
	void setID(int id) //给学号赋值
	{
		m_ID = id;
	}
};

int main1401()
{
	//通过圆类创造对象
	Circle c1;  //实例化对象，通过类创建对象的过程
	c1.m_r = 2;
	cout << "圆的周长为" << c1.calculatezc() << endl;
	
	student s1;
	s1.m_name = "vicky";
	s1.m_ID = 123;
	s1.showinfo();
	s1.setName("alan");
	s1.setID(1);
	s1.showinfo();

	student s2;
	s1.m_name = "andy";
	s1.m_ID = 12;
	s1.showinfo();


	return 0;
}