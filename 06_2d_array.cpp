#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main06()
{
	//��ά����Ķ���
	int arr1[2][3] = 
	{ 
		{1,2,3},
		{4,5,6} 
	};
	int arr2[2][3] = { 1,2,3,4,5,6 };
	int arr3[][3] = { 1,2,3,4,5,6 };
	for(int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "arr1[" << i << "][" << j << "]=" << arr1[i][j] << " ";
			cout << "arr2[" << i << "][" << j << "]=" << arr1[i][j] << " ";
			cout << "arr3[" << i << "][" << j << "]=" << arr1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//�鿴��ά��������ƣ����Բ鿴ռ�õ��ڴ�ռ��С
	int arr4[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};
	cout << "��ά����ռ�õ��ڴ�ռ�Ϊ��" << sizeof(arr4) << endl;
	cout << "��ά�����һ��ռ�õ��ڴ�ռ�Ϊ��" << sizeof(arr4[0]) << endl;
	cout << "��ά�����һ��Ԫ��ռ�õ��ڴ�ռ�Ϊ��" << sizeof(arr4[0][0]) << endl;
	cout << "����Ϊ��" << sizeof(arr4) / sizeof(arr4[1]) << endl;
	cout << "����Ϊ��" << sizeof(arr4[0]) / sizeof(arr4[0][0]) << endl;
	
	//�鿴��ά������׵�ַ
	cout << "��ά������׵�ַ��" << arr4 << endl;
	cout << "��һ�����ݵ��׵�ַ��" << arr4[0] << endl;
	cout << "�ڶ������ݵ��׵�ַ��" << arr4[1] << endl;
	cout << "��һ��Ԫ�����ݵ��׵�ַ��" << &arr4[0][0] << endl;
	cout << endl;

	//�������3��ͬѧ���ܳɼ�
	int score[3][3] =
	{
		{100,100,100},
		{90,50,100},
		{60,70,80}
	};
	string names[3] = {"����","����","����"};

	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum = sum + score[i][j];
		}
		cout <<  names[i] << "�ĳɼ���" << sum << endl;
	}

	
	
	
	
	
	return 0;
}