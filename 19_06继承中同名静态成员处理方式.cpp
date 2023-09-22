#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

/*
* �̳���ͬ���ľ�̬��Ա�������������ν��з��ʣ�
* ��̬��Ա�ͷǾ�̬��Ա����ͬ��������ʽһ��
* ��������ͬ����Աֱ�ӷ��ʼ���
* ���ʸ���ͬ����Ա����Ҫ���������
*/

class Base
{
public:
	static void func()
	{
		cout << "base static func" << endl;
	}
	static void func(int a)
	{
		cout << "base static func int a" << endl;
	}
	static int m_A;
};

int Base::m_A = 100;

class Son :public Base
{
public:
	static void func()
	{
		cout << "son static func" << endl;
	}
	static int m_A;
};

int Son::m_A = 200;

//ͬ����̬��Ա������
void test01()
{
	//1.ͨ������������
	Son s;
	cout << "ͨ������������" << endl;
	cout << " son m_A=" << s.m_A << endl;
	cout << " base m_A=" << s.Base::m_A << endl;
	//2.ͨ������������
	cout << "ͨ������������" << endl;
	cout << " son m_A=" << Son::m_A << endl;
	//��һ��ð�ű�ʾͨ��������ʽ���ڶ�����ʾ������
	cout << " base m_A=" << Son::Base::m_A << endl;
}

//ͬ����Ա��̬����
void test02()
{
	Son s1;
	cout << "ͨ������������" << endl;
	s1.func();
	s1.Base::func();
	cout << "ͨ������������" << endl;
	Son::func();
	Son::Base::func();
	Son::Base::func(100);
}

int main()
{
	test01();
	test02();
	return 0;
}