#define _CRT_SECURE_NO_WARNINGS 1   
//#include <iostream>
#include "07_func.h"
using namespace std;

int max(int x, int y);

//�������������ڱ���֮ǰ���߱����������Ĵ���
// ��������������Σ����Ƕ���ֻ����һ��
//�ȽϺ��������ؽϴ�ֵ
int max(int x, int y)
{
	return x > y ? x : y;
}


//�����������Ҫ����ֵ��������ʱ�����дvoid,�βα仯����Ӱ��ʵ��
void swap(int x, int y)
{
	int temp = 0;
	temp = x;
	x = y;
	y = temp;
	cout << "������x" << x << endl;
	cout << "������y" << y << endl;
}

//�����ĳ�����ʽ
//1.�޲����޷���ֵ
void test01()
{
	cout << "test01" << endl;
}

//2.�в����޷���ֵ
void test02(int a)
{
	cout << "test02 " << a << endl;
}

//3.�޲����з���ֵ

int test03()
{
	return 0;
}

//4.�в����з���ֵ
//�����Ķ���,�βΣ���������ʱ����Ĳ���Ϊʵ��
int add(int num1, int num2)
{
	return num1 + num2;
}

int main07()
{
	int a = 10, b = 3;
	cout << "��ӵĺ�Ϊ��" << add(a, b) << endl;
	swap(a, b);
	test01();
	test02(4);
	int num1 = test03();
	cout << "num1 " << num1 << endl;
	cout << "���ֵΪ" << max(a, b) << endl;


	return 0;
}