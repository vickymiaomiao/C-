#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* C++�ṩ�˳�ʼ���б�������������ʼ������
* �﷨�����캯������������1��ֵ1��������2��ֵ2��������{}
*/

class person
{
public:
	//��ͳ��ʼ������
	//person(int a, int b, int c)
	//{
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	//��ʼ���б�����
	person(int a,int b,int c):m_A(a),m_B(b),m_C(c)
	{}

	int m_A;
	int m_B;
	int m_C;
};

void test01()
{
	//person p(10, 20, 30);
	person p(30,20,10);
	cout << " m_A=" << p.m_A << " m_B=" << p.m_B << " m_C=" << p.m_C << endl;
}

int main()
{
	test01();
	return 0;
}