#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <string>

using namespace std;
/*
* �̳з�ʽ
* 1.�����̳�
* 2.�����̳�
* 3.˽�м̳�
*/
//�����̳�
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class son1 :public Base1
{
	void func()
	{
		m_A = 10; //�����еĹ���Ȩ�޳�Ա�������������ǹ���Ȩ��
		m_B = 10;//�����еı���Ȩ�޳�Ա����������Ȼ�Ǳ���Ȩ�޳�Ա
		//m_C = 10;  �����е�˽�г�Ա�����޷�����
	}
};

void test01()
{
	son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100;����son1���Ǳ���Ȩ��������ʲ���
}
//�����̳�
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class son2 :protected Base2
{
public:
	void func()
	{
		m_A = 100; //���๫����Ա�������б�Ϊ������Ա
		m_B = 100;//�����еı�����Ա�������б�Ϊ������Ա
		//m_C = 100;//�����е�˽�г�Ա������ʲ���
	}
};

void test02()
{
	son2 s2;
	//s2.m_A = 100;  �������б�Ϊ����Ȩ���޷�����
	//s2.m_B = 100;  �������б�Ϊ����Ȩ���޷�����
	//s2.m_C = 100;  �������б�Ϊ����Ȩ���޷�����
}

//˽�м̳�
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class son3 :private Base3
{
	void func()
	{
		m_A = 100; //����->˽��
		m_B = 100;//����->˽��
		//m_C=100;  ���಻���Է��ʸ����е�˽�г�Ա
	}
};

void test03()
{
	son3 s3;
	//s3.m_A = 100;  �����еĹ�����Ա�������б�Ϊ˽�г�Ա��˽�г�Ա���ⲻ���Է���
	//s3.m_B = 100;
	//s3.m_C = 100;
}
//�����࣬����son3�е�˽�м̳�
class Grandson3 :public son3
{
public:
	void func()
	{
		//ȫ����˽�г�Ա�������Լ̳�
	/*	m_A = 100;
		m_B = 100;
		m_C = 100;*/
	}
};

int main()
{
	test01();
	return 0;
}