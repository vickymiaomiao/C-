#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* �������븸�����ͬ����Ա�����ͨ�����������ʵ������Ա
* 
* ��������ͬ����Աֱ�ӷ��ʼ���
* ���ʸ���ͬ����Ա��Ҫ���������
*/

class Base
{
public:
	Base()
	{
		m_A = 100;
	}
	int m_A;

	void func()
	{
		cout << "Base - func()" << endl;
	}
	void func(int a)
	{
		cout << "son - func() - int a" << endl;
	}

};

class son :public Base
{
public:
	son()
	{
		m_A = 200;
	}
	int m_A;

	void func()
	{
		cout << "son - func()" << endl;
	}


};

void test01()
{
	son s;
	cout << "son�µ� m_A=" << s.m_A << endl;
	cout << "Base�µ� m_A=" << s.Base::m_A << endl;
}

void test02()  //ͬ����Ա�����Ĵ���
{
	son s1;
	s1.func();
	s1.Base::func();
	//��������г����˸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص����������е�ͬ����Ա����
	//���Ҫ������Ҫ���������
	s1.Base::func(100);
}

int main()
{
	test01();
	test02();
	return 0;
}