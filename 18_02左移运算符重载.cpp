#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* "<<"������������ؿ�������Զ������������
* ��������������Ԫ����ʵ������Զ�����������
*/

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);
public:
	Person(int a,int b)
	{
		m_A = a;
		m_B = b;
	}
private:
	//�������ó�Ա����ʵ�������������������Ϊ�޷�ʵ��cout�����
	
	int m_A;
	int m_B;

};

//ֻ������ȫ�ֺ������������
ostream & operator<<(ostream &cout, Person &p) //�� cout << p
{
	cout << "m_A=" << p.m_A << " m_B=" << p.m_B;
	return cout;
}

void test01()
{
	Person p(10,10);
	//p.m_A = 10;
	//p.m_B = 20;

	cout <<p<<endl;
}



int main()
{
	test01();
	return 0;
}