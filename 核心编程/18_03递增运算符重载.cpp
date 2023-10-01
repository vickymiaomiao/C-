#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>

using namespace std;

/*
* ͨ�����ص����������ʵ���Լ�����������
* ǰ�õ����������ã����õ�������ֵ
*/

//�Զ�������
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);

public:
	MyInteger()
	{
		m_Num = 0;
	}
	//����ǰ��++�����
	MyInteger& operator++()  //����������Ϊ��һֱ��һ�����ݽ��в���
	{
		m_Num++;
		return *this;
	}

	//���غ���++�����
	//int����ռλ������������������ǰ�úͺ��õ���
	MyInteger operator++(int)  //
	{
		//�ȼ�¼��ʱ���
		MyInteger temp = *this; //���ò�������ֵ����Ϊ�Ǿֲ�����
		//�����
		m_Num++;
		//��󽫼�¼�Ľ��������
		return temp;
	}

private:
	int m_Num;
};

//�������������
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num;
	return cout;
}


void test01()
{
	MyInteger myint;
	cout << ++myint << endl;
}

void test02()
{
	MyInteger myint1;
	cout << myint1++ << endl;
	cout << myint1 << endl;
}


int main()
{
	test01();
	test02();
	return 0;
}