#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* ��̬��Ա�����ڳ�Ա����ǰ���Ϲؼ���static
* 1.��̬��Ա������
* ���ж�����ͬһ������
* �ڱ���׶η����ڴ�
* �������������ڳ�ʼ��
* 2.��̬��Ա����
* ���ж�����ͬһ������
* ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
*/

class person
{
public:
	//��̬��Ա����Ҳ�з���Ȩ��
	static int m_A; 
	int m_C;

	static void func()
	{
		m_A = 500;
		//m_C = 300;   �Ǿ�̬��Ա��������̬�����޷����ʣ��޷����ֵ������ĸ����������
		cout << "static func ����" << endl;
	}
private:
	static int m_B;   //˽�����������ⲻ���Է���
	//��̬��Ա����Ҳ�з���Ȩ��
	static void func2()
	{
		cout << "private static func����" << endl;
	}
};

int person::m_A = 100; //�����ʼ��
int person::m_B = 200;

void test01()
{
	person p;
	cout << p.m_A << endl;

	person p2;
	p2.m_A = 200;
	cout << p.m_A << endl;
}

void test02()
{
	//��̬��Ա����������ĳ�������ϣ����ж��󶼹���ͬһ������
	//��˾�̬��Ա���������ַ��ʷ�ʽ
	//1.ͨ���������
	person p1;
	cout << p1.m_A << endl;
	p1.func();
	//2.ͨ���������з���
	cout << person::m_A << endl;
	person::func();
	//cout << person::m_B << endl;    �����޷�����˽�г�Ա����
	//person::func2();   �����޷����ʾ�̬��Ա����
}

int main()
{
	test01();
	test02();
	return 0;
}