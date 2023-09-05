#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;
//成员属性设置为私有
//优点1：将所有成员属性设置为私有，可以自己控制读写权限
//优点2：对于写权限，我们可以检测数据的有效性

class Person
{
public:
	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}
	//获取姓名
	string getName()
	{
		cout << "name : " << m_Name << endl;
		return m_Name;
	}
	//获取年龄
	int getAge()
	{
		//
		cout << "age : " << m_Age << endl;
		return m_Age;
	}
	void setAge(int age)
	{
		//判断年龄范围
		if (age > 100 || age < 0)
		{
			cout << "年龄超出范围" << endl;
			return;
		}
		m_Age = age;
	}

	//写爱人
	void setLover(string lover)
	{
		m_Lover = lover;
		//cout << "lover : " << m_lover << endl;
	}
	string getLover()
	{
		cout << "name : " << m_Lover << endl;
		return m_Lover;
	}

private:
	string m_Name;  //可读可写权限
	int m_Age;     //只读
	string m_Lover;   //只写
};

int main1403() 
{
	Person p;
	p.setName("vicky");
	p.getName();
	p.setAge(50);
	p.getAge();
	p.setLover("andy");
	p.getLover();

	return 0;
}