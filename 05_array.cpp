#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
using namespace std;

int main05()
{
	//������ص�
	//a.�����������ڴ��� b.ÿ��Ԫ��������������ͬ
	int arr[5];  //����
	arr[0] = 10; //����
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;
	//��������Ԫ��
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}


	int arr2[5] = { 10,20,30,40,50 };//ֵ������0�
	for (int i = 0; i < 5; i++) 
	{
		cout << arr2[i] << endl;
	}

	//�����������������鳤��
	int arr3[] = { 10,20,30,40,50,60 };
	for (int i = 0; i < 6; i++)
	{
		cout << arr3[i] << endl;
	}

	//һά����������;
	int arr4[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "��������ռ�õ��ڴ�ռ�Ϊ��" << sizeof(arr4)<<endl;
	cout << "ÿ��Ԫ��ռ�õ��ڴ�ռ�Ϊ��" << sizeof(arr4[0])<<endl;
	cout << "������Ԫ�صĸ���Ϊ��" << sizeof(arr4) / sizeof(arr4[0])<<endl;
	//������׵�ַ�͵�һ��Ԫ�صĵ�ַ����ͬ��
	cout << "������׵�ַ��" << arr4 << endl;
	cout << "�����е�һ��Ԫ�صĵ�ַ��" << &arr4[0] << endl;
	cout << "�����еڶ���Ԫ�صĵ�ַ��" << &arr4[1] << endl;
	
	//�������ǳ����������Խ��и�ֵ����

	//�ҳ��������ص�������ӡ���
	int pig[5] = { 300,350,200,400,250 };
	int max = 0;
	for (int n = 0; n < sizeof(pig) / sizeof(pig[0]); n++)
	{
		if (pig[n] > max)
			max = pig[n];
	}
	cout << "���ص���������ǣ�" << max << endl;

	//��Ԫ������
	int arr5[5] = {1,2,3,4,5};
	int arr6[5] = {};
	for (int x = 4; x >=0; x--)
	{
		arr6[4-x] = arr5[x];
		cout << "arr6[" << 4-x << "]" <<"=" << arr6[4 - x] << endl;
	}

	//��Ԫ�����÷�����
	int arr7[5] = { 1,2,3,4,5 };
	int start = 0;
	int end = sizeof(arr7) / sizeof(arr7[0]) - 1;
	int temp = 0;
	for (; start <= end; start++,end--)
	{
		temp = arr7[start];
		arr7[start] = arr7[end];
		arr7[end] = temp;
	}
	for (int i = 0; i < sizeof(arr7) / sizeof(arr7[0]); i++)
	{
		cout << "arr7[" << i << "]=" << arr7[i] << endl;
	}

	//ð�������������н��
	int arr8[9] = {4,2,8,0,5,7,1,3,9 };
	int temp1 = 0;
	for (int i = 0; i < sizeof(arr8) / sizeof(arr8[0]); i++)
	{
		for (int j = i; j < sizeof(arr8) / sizeof(arr8[0]); j++)
		{
			if (arr8[i] > arr8[j])
			{
				temp1 = arr8[i];
				arr8[i] = arr8[j];
				arr8[j] = temp1;
				
			}
		}
		cout << "arr8[" <<i<<"]=" << arr8[i] << endl;
	}

	return 0;
}