#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

//��Ͷ��󣺷�װ���̳С���̬
//C++��Ϊ���������Ϊ���󣬶������������Ժ���Ϊ

//��װ�������Ժ���Ϊ��Ϊһ�����壬����Ϊ�����е�����
//�����Ժ���Ϊ����Ȩ�޿���
// class ����{����Ȩ�ޣ�����/��Ϊ};

//���һ��Բ�࣬��Բ���ܳ�
const double PI = 3.14;//Բ����

class Circle
{
	//����Ȩ��
public : //����Ȩ��
	int m_r;//�뾶��//Բ������
	//��Ϊ
	double calculatezc()
	{
		return PI * 2 * m_r;
	}
};

class student
{
public: //����Ȩ��
	//���е����Ժ���Ϊ������ͬһ��Ϊ��Ա
	//���� ��Ա���ԣ���Ա����
	//��Ϊ ��Ա���� ��Ա����
	string m_name;
	int m_ID;
	
	void showinfo()
	{
		cout << "ѧ��������Ϊ" <<m_name<< endl;
		cout << "ѧ����ѧ��Ϊ" << m_ID << endl;
	}
	void setName(string name)  //�����ָ�ֵ
	{
		m_name = name;
	}
	void setID(int id) //��ѧ�Ÿ�ֵ
	{
		m_ID = id;
	}
};

int main1401()
{
	//ͨ��Բ�ഴ�����
	Circle c1;  //ʵ��������ͨ���ഴ������Ĺ���
	c1.m_r = 2;
	cout << "Բ���ܳ�Ϊ" << c1.calculatezc() << endl;
	
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