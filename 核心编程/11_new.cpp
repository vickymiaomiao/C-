#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;

//new�����ڶ����������ݣ�delete���������ͷ�����
int* funcnew()
{
	int* p = new int(30);//new���ظ��������͵�ָ��,��ʾP�ı���ĵ�ַ�д�ŵ�������30
	return p;
}

void testnew()
{
	int* p = funcnew();
	cout << *p << endl;
	//�����������ɹ���Ա�����ͷ�
	//���Ҫ�ͷŶ��������ݣ���Ҫʹ��delete
	delete p;//�ͷŵ�ַ����
	//cout << *p << endl; //�ڴ��Ѿ��ͷţ��ٴη��ʾ��ǷǷ�����
}

//new ����������
void testnewaarray()
{
	//����10���������ݵ����飬�ڶ���
	int* arr = new int[10];//10������������10������
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 10;   //��ֵ10-19
	}
	for (int i = 0; i < 10; i++)
	{
		cout << "arr[" << i << "]=" << arr[i] << endl;
	}
	//�ͷŶ�������,��Ҫ���������[]
	delete[] arr;
}

int main11()
{
	testnew();
	testnewaarray();

	return 0;
}