#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;
//��Ա��������Ϊ˽��
//�ŵ�1�������г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
//�ŵ�2������дȨ�ޣ����ǿ��Լ�����ݵ���Ч��

class Person
{
public:
	//��������
	void setName(string name)
	{
		m_Name = name;
	}
	//��ȡ����
	string getName()
	{
		cout << "name : " << m_Name << endl;
		return m_Name;
	}
	//��ȡ����
	int getAge()
	{
		//
		cout << "age : " << m_Age << endl;
		return m_Age;
	}
	void setAge(int age)
	{
		//�ж����䷶Χ
		if (age > 100 || age < 0)
		{
			cout << "���䳬����Χ" << endl;
			return;
		}
		m_Age = age;
	}

	//д����
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
	string m_Name;  //�ɶ���дȨ��
	int m_Age;     //ֻ��
	string m_Lover;   //ֻд
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