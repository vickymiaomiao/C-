#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* ���ù������£�
* 1.�������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
* 2.����ͨ����ģ���б���ǿ�Ƶ��ú���ģ��
* 3.����ģ��Ҳ���Է�������
* 4.�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
* 
* ע�⣺�ṩ����ģ��Ͳ�Ҫ�ṩ��ͨ���������ײ���������
*/

void myprint(int a, int b)
{
	cout << "normal func" << endl;
}

template<class T>
void myprint(T a, T b)
{
	cout << "template func" << endl;
}

template<class T>
void myprint(T a, T b,T c)
{
	cout << "template func ����" << endl;
}

void test01()
{
	int a = 10, b = 20;
	char c1 = 'a';
	char c2 = 'b';
	myprint(a, b);
	//ͨ����ģ������б�
	myprint<>(a, b);
	myprint(a, b, 10);//����
	myprint(c1, c2);//����ģ�壬���õ�ƥ��
}







int main()
{
	test01();
	return 0;
}