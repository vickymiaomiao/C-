#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
using namespace std;

int main04()
{
	//for ѭ��
	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
	}
	


	//�����ӣ�1-100����������7����7�ı�����Ҫ������
	for (int n = 1; n < 101; n++) 
	{
		int a = 0, b = 0,c=0;
		a = n % 10;
		b = n / 10;
		c = n % 7;
			if (a == 7 || b == 7 || c == 0)
			{
				cout <<  " ������" << endl;
			}
			else
				cout << n << endl;
	}


	//Ƕ��ѭ��,��ӡ10*10��*
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
			cout << "* ";
		cout << endl;
	}


	//�˷��ھ���
	for (int n1 = 1; n1 < 10; n1++)//����
	{
		for (int n2 = 1; n2 <= n1; n2++)//����
			cout << " " << n2 << "x" << n1 << "=" << n1 * n2;
		cout << endl;
	}

	//goto������ת����������ת�ĵط�

	return 0;
}