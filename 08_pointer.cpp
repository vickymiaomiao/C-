#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
using namespace std;

//ʵ���������ݽ���,ֵ����
void swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}


void swap02(int* p1,int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;

}

//ð��������
void bubblesort(int * arr,int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//��ӡ����
void printarray(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "arr[" << i << "]=" << *arr << endl;
		arr++;
	}
}

int main08()
{
	//����ָ��
	int a = 10;
	int* pa;
	pa = &a;
	cout << "a�ĵ�ַΪ" << pa << endl;
	//ָ��ǰ��һ��*��ʾ������,�����ҵ�a��ֵ
	cout << "a��ֵΪ" << *pa << endl;
	*pa = 100;
	cout << "a��ֵΪ" << *pa << endl;
	cout << "sizeof (int *) = " << sizeof(pa) << endl;
	cout << "sizeof (int *) = " << sizeof(int *) << endl;

	//��ָ�룬ֻ���ڴ��б��Ϊ0�Ŀռ�
	//��ʼ��ָ���������ָ��ָ����ڴ��޷�����
	//0-255֮����ڴ���ϵͳռ�õģ���˲����Է���
	int* pb = NULL;
	//*pb=100;
	// ��ָ���Ұָ�붼������������Ŀռ䣬��Ϊ��Ҫ����
	//Ұָ�룬ָ�����ָ��Ƿ����ڴ�ռ䣬�ڳ����о����������Ұָ��
	//int* pc = (int*)0x1100;  //0x1100���ڴ�û�з���Ȩ��
	
	//const����ָ��---����ָ��
	int b = 10;
	const int* pc = &a;  //ָ���ָ������޸ģ�����ָ��ָ���ֵ�������޸�
	//*pc=20;  //����ָ���ֵ�����Ը�
	pc = &b;//��ȷ

	//ָ�볣�� const ���γ�����ָ���ֵ���Ըģ�ָ���ܸ�
	int* const pd = &a;
	*pd = 20;
	//pd = &b; //����ָ�򲻿��Ը���

	//������ָ�������γ���,ָ���ֵ�������Ը���
	const int* const pe = &a;

	//ָ�������
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* parr = arr;//arr����������׵�ַ
	//cout << "��һ��Ԫ�ص�����:" << *parr << endl;
	//parr++;//�ƶ��ĸ��ֽ�
	//cout << "�ڶ���Ԫ�ص�����:" << *parr << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "��" << i << "��Ԫ�ص������ǣ�" << *parr << endl;
		parr++;
	}

	//ָ��ͺ�����ָ����Ϊ�������β�
	int x = 10, y = 20;
	swap01(x, y);
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	//��ַ����,�����޸�ʵ��
	swap02(&x, &y);
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;

	//ָ�������ͺ���
	//case:��װһ������������ð������ʵ�ֶ����������������
	int arr1[10] = { 4,3,6,9,1,2,10,8,7,5 };
	int len = sizeof(arr1) / sizeof(arr1[0]);
	bubblesort(arr1, len);
	printarray(arr1, len);


	return 0;
}