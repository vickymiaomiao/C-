#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

//
// Ĭ������£�C++���ٸ�һ�������3������
// 1.Ĭ�Ϲ��캯������ʵ�֣�
// 2.Ĭ��������������ʵ�֣�
// 3.Ĭ�Ͽ������캯�����������Խ���ֵ����
//
/*
* ���캯�����ù�������
*1.����û������вι��캯����C++�����ṩĬ���޲ι��캯�� ������Ȼ�ṩ�������캯��
2.�������д�˿������캯�����������Ͳ��ṩ�����Ĺ��캯��
*/

class person
{
public:
	person()
	{
		cout << "person��Ĭ�Ϲ��캯������" << endl;
	}
	person(int age)
	{
		m_Age = age;
		cout << "person���вι��캯���ĵ���" << endl;
	}
	person(const person& p)
	{
		m_Age = p.m_Age;
		cout << "person �Ŀ��������ĵ���" << endl;
	}
	~person()
	{
		cout << "person�����������ĵ���" << endl;
	}
	int m_Age;
};

void test150401()
{
	person p;
	p.m_Age = 18;

	person p2(p);
	cout << "p2������Ϊ" << p2.m_Age << endl;
}

int main1504()
{
	test150401();
	return 0;
}