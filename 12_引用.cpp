#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;


//���õ����ã������������
//int a=10;
//�﷨���������� &����=ԭ��
//���ñ���Ҫ��ʼ��
//����һ����ʼ����Ͳ����Ը���

//������������������������ʱ�������������ü������β�����ʵ��
//��������

//ֵ����
void myswap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "swap01_a= " << a << endl;
	cout << "swap01_b= " << b << endl;
}
//��ַ����
void myswap02(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
//���ô���
void myswap03(int& a, int& b)
{
	int temp = a;
	a = b; 
	b = temp;

}

//�����������ķ���ֵ
//1.��Ҫ���ؾֲ�����������
//2.�����ĵ��ÿ�����Ϊ��ֵ
int& yinyong01()  //��������
{
	static int a = 300;//�ֲ������������ջ��������static֮������ȫ����
	//ȫ�����ϵ������ڳ��������ϵͳ�ͷ�
	return a;  //����a�����ã�a�ı���
}

//���õı�����c++�ڲ�ʵ����һ��ָ�볣��
//int * const ref = &a;ָ�볣����ָ�򲻿ɸ���

//��ӡ���ݵĺ���
void showvalue(const int &val)  //�����βΣ����ܽ����޸�
{
	//val = 1000;
	cout <<"val=" << val << endl;
}
 


int main12()
{
	//�������ã������βΣ���ֹ�����
	int x = 90;
	//����const֮�󣬱������������޸�Ϊint temp=10;int &ref=temp;����const֮���Ϊֻ���������޸�
	//const int& y = x;//���ñ�����һ��Ϸ����ڴ�
	showvalue(x);
	
	//int a = 10;
	//int &b = a;//����Ϊb
	//b = 20;
	//cout << a << endl;
	int& ref = yinyong01();
	cout << "ref=" <<  ref << endl;
	yinyong01() = 1000;  //��������ķ���ֵ�����ã�����������ÿ�����Ϊ��ֵ
	cout << "ref=" << ref << endl;
	int a = 10;
	int b = 20;
	myswap01(a, b);  //ֵ���ݣ��ββ�������ʵ��
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	myswap02(&a, &b);  //��ַ���ݣ��βλ�����ʵ��
	cout << "swap02 a= " << a << endl;
	cout << "swap02 b= " << b << endl;
	myswap03(a, b); //���ô��ݣ��βλ�����ʵ��
	cout << "swap03 a= " << a << endl;
	cout << "swap03 b= " << b << endl;

	return 0;
}