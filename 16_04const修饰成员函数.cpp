#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* ������
* 1.�ڳ�Ա���������const�ƺ���Ϊ������
* 2.�������ڲ������޸ĳ�Ա����
* 3.��Ա��������ʱ���Ϲؼ���mutable���ڳ������п����޸�
* 
* ������
* 1.��������ǰ��const�Ƹö���Ϊ������
* 2.������ֻ�ܵ��ó�����
*/

class person
{
public:
	//thisָ��ı�����ָ�볣����ָ���ָ�򲻿����޸�
	//person * const this   ָ�򲻿����޸�
	//�ڳ�Ա�����������const,���ε���this��ָ����ָ��ָ���ֵҲ�������޸�
	void showPerson() const  //ָ���ֵ���������޸� const person * const this
	{
		//this->m_A = 100;
		//this = NULL; //�������޸�ָ��
		this->m_B = 100;
	}
	void func(){}

	int m_A;
	mutable int m_B; //��������ڳ�������Ҳ�����޸�
};

void test01()
{
	person p;
	p.showPerson();
}

void test02()
{
	const person p1;//�ڶ���ǰ�����const��ʾ��Ϊ������
	//p1.m_A = 100;
	p1.m_B = 100; //����ֵ���ڳ�������Ҳ�����޸�
	//������ֻ�ܵ��ó�����
	//p1.func();
	p1.showPerson();
}

int main()
{
	return 0;
}