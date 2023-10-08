#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;


/*
* ��Ҫ��Է��ͱ�̺�STL����
* ģ�壺����ͨ�õ�ģ�ߣ�������߸�����
* �ص㣺ģ�岻����ֱ��ʹ�ã���ֻ��һ�����
* ģ���ͨ�ò��������ܵ�
* 
* �ṩ����ģ����ƣ�����ģ�����ģ��
* 
* ����ģ�����ã�
* ����һ��ͨ�ú������亯������ֵ���ͺ��β����Ϳ��Բ������ƶ�����һ�����������������
* �﷨��template<typename T>  ���������Ͷ���
* template --- ��������ģ��
* typename --- ���������ķ�����һ���������ͣ�������class����
* T --- ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ
* 
*/

//�����������ͺ���
void swapint(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//�������������ͺ���
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//����ģ��
template<typename T>  //����һ��ģ�壬���߱�������������н����ŵ�T��Ҫ����
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10, b = 20;
	swapint(a, b);
	//���ú���ģ����н���
	//�����ַ�ʽ
	//1.�Զ������Ƶ�
	mySwap(a, b);
	//2.��ʾָ������ʹ��<>ָ����������
	mySwap<int>(a, b);
	cout << "a=" << a << " , " << "b=" << b << endl;

	double c = 3.14, d = 2.34;
	swapDouble(c, d);
	cout << "c=" << c << " , " << "d=" << d << endl;
}

int main()
{
	test01();
	return 0;
}