#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
//���ϵͳʱ���ͷ�ļ�
#include <ctime>
using namespace std;

int main03()
{
	//����Ļ��ѭ����ӡ0~9�������
	int n = 0;
	while (n < 10)
	{
		cout << "n=" << n<<endl;
		n++;
	}

	//ϵͳ�������1-100���֣����в����֣��¶�����Ϸ����
	//�������������ӣ����õ�ǰϵͳʱ���������������ֹÿ���������ͬ
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;//����1-100�������
	cout << "num=" << num << endl;
	//��ҽ��в²�
	int guessnum = 102;
	while (guessnum != num)
	{
		cin >> guessnum;
		cout << "��²������Ϊ��" << endl;
		if (guessnum > num)
			cout << "�´���" << endl;
		else if (guessnum < num)
			cout << "��С��" << endl;
		else
		{
			cout << "�¶���" << endl;
			break;
		}
			
	}


	//do while ,����Ļ���0-9
	int x = 0;
	do 
	{
		cout << "x=" << x << endl;
		x++;
	} while (x < 10);


	//ˮ�ɻ���
	//�ҵ����е���λ��
	int m = 100;
	int a = 0, b = 0, c = 0;
	do
	{
		a = m % 10;//��λ
		b = (m / 10) % 10;//ʮλ
		c = m / 100;//��λ
		if ((a*a*a + b*b*b  + c *c*c) == m)
			cout << m << "��ˮ�ɻ���" << endl;

		m++;
	} while (m < 1000);





	return 0;
}