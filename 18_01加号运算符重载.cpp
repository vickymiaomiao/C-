#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;

/*
* �����е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������
* ʵ�������Զ�������������ӵ�����
* 1.ͨ����Ա�������ؼӺ�
* 2.ͨ��ȫ�ֺ������ؼӺ�
* ע�⣺
* 1.�������õ��������͵ı��ʽ��������ǲ����ܸı��
* 2.��Ҫ�������������
*/

class Person
{
public:
	//ͨ����Ա����ʵ�����������
	//Person operator+(Person p)
	//{
	//	Person temp;
	//	temp.m_A = this->m_A + p.m_A;
	//	temp.m_B = this->m_B + p.m_B;
	//	return temp;
	//}

	int m_A;
	int m_B;
};

//ͨ��ȫ�ֺ���ʵ�����������
Person operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
//����
Person operator+(Person& p1, int num)
{
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

void test01()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 10;
	p2.m_B = 20;
	//��Ա�������ʵ���
	Person p3 = p1 + p2;
	Person p4 = p1 + 30;
	//���������Ҳ���Է�����������
	cout << "p3.m_A=" << p3.m_A << endl;
	cout << "p3.m_B=" << p3.m_B << endl;
	cout << "p4.m_A=" << p4.m_A << endl;
	cout << "p4.m_B=" << p4.m_B << endl;
}

int main()
{
	test01();
	return 0;
}