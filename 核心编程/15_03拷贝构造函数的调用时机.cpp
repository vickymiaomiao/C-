#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

//�������캯���ĵ���ʱ��


class person
{
public:
	person()
	{
		cout << "Ĭ�Ϲ��캯���ĵ���" << endl;
	}

	person(int a)
	{
		m_Age = a;
		cout << "�вι��캯���ĵ���" << endl;
	}

	person(const person& p)
	{
		m_Age = p.m_Age;
		cout << "�������캯���ĵ���" << endl;
	}

	~person()
	{
		cout << "���������ĵ���" << endl;
	}

	int m_Age;
};

//1.ʹ��һ��������ϵĶ�������ʼ��һ���¶���
//void test01()
//{
//	person p1(20);
//	person p2(p1);
//	cout << "p2�����䣺" << p2.m_Age << endl;
//}

//2.ֵ���ݵĵ�ʱ������������ֵ
void dowork(person p)
{}
void test02()
{
	person p;
	dowork(p);

}
// 
//3.ֵ��ʽ���ؾֲ�����

person dowork2()
{
	person p1;
	return p1;
	//����ʱ����p1�����µĶ���
}
void test03()
{
	person p = dowork2();
}

int main1503()
{
	/*test01();*/
	test02();
	return 0;
}