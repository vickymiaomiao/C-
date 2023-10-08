#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

//����ģ��ע������

template<typename T>  //typename�����滻��class
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//1.�Զ������Ƶ�������Ҫ�Ƶ���һ�µ���������T�ſ���ʹ��
void test01()
{
	int a = 10, b = 20;
	char c = 'c';
	mySwap(a, b);
	//mySwap(a, c);   �����Ƶ������������Ͳ�һ��
	cout << "a=" << a << " , " << "b=" << b << endl;
}

//2.ģ�����Ҫȷ����T���������Ͳſ���ʹ��
template<class T>
void func()
{
	cout << "func test" << endl;
}

void test02()
{
	//func();//û��ָ����������T
	func<int>();
}

int main()
{
	test01();
	test02();
	return 0;
}