#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* ��ͨ�����뺯��ģ�������
* 1.��ͨ��������ʱ���Է����Զ�����ת������ʽ����ת����
* 2.����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
* 3.���������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��
*/
int myadd01(int a, int b)
{
	return a + b;
}

//����ģ��
template<class T>
T myadd02(T a, T b)
{
	return a + b;
}

void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	cout << myadd01(a, b) << endl;
	cout << myadd01(a, c) << endl; //��ʽ����ת��

	//�Զ������Ƶ�
	cout << myadd02(a, b) << endl;
	//cout << myadd02(a, c) << endl;
	//��ʾָ������
	cout << myadd02<int>(a, c) << endl;
	

}

int main()
{
	test01();
	return 0;
}