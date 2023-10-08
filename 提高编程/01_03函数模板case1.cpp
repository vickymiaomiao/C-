#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

//���ú���ģ���װһ�������������ԶԲ�ͬ���͵������������
//�������Ϊ�Ӵ�С�������㷨Ϊѡ������
//�ֱ���char�����int������в���
//
//ʵ�ֽ���ģ��
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//����ģ��
template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;//�϶�iΪ���ֵ
		for (int j = i+1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j; //�������ֵ���±�
			}
		}
		if (max != i)
		{
			//����max��i��Ԫ��
			mySwap(arr[max], arr[i]);
		}

	}
}

//��ӡ�����ģ��
template<typename T>
void printArrary(T arr[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
}

void test01()
{
	char chararr[] = "badcfe";
	int num = sizeof(chararr) / sizeof(chararr[0]);
	mySort(chararr, num);
	printArrary(chararr, num);

	int intarr[] = { 2,5,7,3,1,8,0,9 };
	int num1 = sizeof(intarr) / sizeof(intarr[0]);
	mySort(intarr, num1);
	printArrary(intarr, num1);
}

int main()
{
	test01();
	return 0;
}