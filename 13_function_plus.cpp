#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>

using namespace std;


//�����β��б��е��βο�����Ĭ��ֵ
//����ֵ���� ������ ������=Ĭ��ֵ��{}
//��������Լ��������ݣ����ô�������ݣ����û�У�����Ĭ��ֵ
//ע������
//1.���ĳ��λ������Ĭ�ϲ�������ô�����λ�����󶼱���ҪĬ��ֵ

int defaultpara(int a, int b=20, int c=30)
{
	return a + b + c;
}
int defaultpara1(int a = 10, int b = 10);
//2.���������������Ĭ�ϲ�����������ʵ�־Ͳ�����Ĭ�ϲ���
//������ʵ��ֻ����һ����Ĭ�ϲ���
int defaultpara1(int a, int b)
{
	return a + b;
}

//����ռλ����������ռλ
//����ֵ���� ���������������ͣ�{}
//Ŀǰ�׶ε�ռλ������ʱ�ò�����ռλ����������Ĭ�ϲ���
void zhanweifunc(int a, int =10)   //�ڶ���int������ռλ����
{
	cout << "this is a func" << endl;
}

//�������أ�������������ͬ����߸�����
//1.ͬһ�������£�2.����������ͬ 3.�����������Ͳ�ͬ���߸�����ͬ����˳��ͬ
//�����ķ���ֵ��������Ϊ�������ص�����
void func1301()
{
	cout << "�����ĵ���" << endl;
}
//��������
void func1301(int a)
{
	cout << "������(int a )����" << endl;
}
void func1301(double a)
{
	cout << "������(double a )����" << endl;
}
void func1301(int a ,double b)
{
	cout << "������(int a ,double b)����" << endl;
}
void func1301( double b, int a)
{
	cout << "������(double b, int a)����" << endl;
}

//��������ע������
//������Ϊ��������
void func1302(int &a) //�ɶ���д
{
	cout << "func1302(int &a)�ĵ���" << endl;
}
//�����������Ͳ�ͬ
void func1302(const int& a) //ֻ��״̬
{
	cout << "func1302(const int &a)�ĵ���" << endl;
}

//����������������Ĭ�ϲ���
void func1303(int a )
{
	cout << "func1303(int a )�ĵ���" << endl;
}

//void func1303(int a, int b=10)    ���ֶ�����
void func1303(int a,int b)
{
	cout << "func1303(int a ,int b)�ĵ���" << endl;
}



int main13()
{
	func1303(10); //��������������Ĭ�ϲ�������ֶ�����
	func1303(10,20);
	int a = 10;
	func1302(a);
	func1302(10);
	func1301();
	func1301(10);
	func1301(3.14);
	func1301(10,3.14);
	func1301(3.14,10);
	cout << defaultpara1(1, 30) << endl;
	cout << defaultpara(1,30) << endl;
	zhanweifunc(10);
	return 0;
}