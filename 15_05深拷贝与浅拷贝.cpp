#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* ǳ�������򵥵ĸ�ֵ��������
* ������ڶ�������ռ��ڽ��п���
* ����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ��������������
*/


class person
{
public:
	person()
	{
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	person(int age,int height)
	{
		m_Age = age;
		m_Height = new int(height);   //�ڶ������ٿռ�������
		cout << "�вι��캯��" << endl;
	}
	//�Լ�ʵ�ֿ������캯�������ǳ��������������
	person(const person& p)
	{
		m_Age = p.m_Age;
		//�������,���¿����ڴ棬��ſ��������Ե�ֵ
		m_Height = new int(*p.m_Height);

	}

	~person()
	{
		//���������ٵ��������ͷŲ���,ջ�������Ƚ����
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;       //ǳ�����ᵼ�¶����ڴ��ظ��ͷ�
		}
		cout << "��������" << endl;
	}
	int m_Age;
	int* m_Height;
};

void test01()
{
	person p1(18,160);
	cout << "p1������Ϊ" << p1.m_Age << endl;
	cout << "p1�����Ϊ" << *p1.m_Height << endl;
	person p2(p1);
	cout << "p2������Ϊ" << p2.m_Age << endl;
	cout << "p2�����Ϊ" << *p2.m_Height << endl;

}


int main1505()
{
	test01();
	return 0;
}