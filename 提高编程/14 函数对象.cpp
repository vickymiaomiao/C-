#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;


/*
* �������ص��ò��������࣬����󳣳�Ϊ��������
* ��������ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ�����º���
* �������󣨷º�������һ���࣬Ҳ�����º���
* ����������ص㣺
* ����������ʹ��ʱ����������ͨ�����������ã����Բ����������з���ֵ
* �������󳬳���ͨ�����ĸ����������������Լ���״̬
* �������������Ϊ��������
*/

class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test01()
{
	MyAdd myadd;
	cout << myadd(10, 10) << endl;
}

class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		this->count++;
	}
	int count;//��¼�ڲ��Լ������õ�״̬
};

void test02()
{
	MyPrint myprint;
	myprint("hello");
	cout << "times:" << myprint.count << endl;
}


int main()
{
	test01();
	test02();
	return 0;
}