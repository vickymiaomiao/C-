#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
using namespace std;

int main01()
{
	//�߼������
	int a = 10;
	//��C++�г���0��Ϊ��
	cout << !a << endl;
	cout << !!a << endl;
	int b = 10;
	cout <<"a&&b=" << (a && b) << endl;
	int c = 0;
	cout << (a || b) << endl;
	//����ṹ��˳��ѡ��ѭ��
	//ѡ��ṹ
	//���û������������������600������һ��
	int score = 0;
	cout << "�����������" << endl;
	cin >> score;
	cout << "������ķ���Ϊ��" << score << endl;
	//if �������治�ܼӷֺ�
	if (score > 600)
	{
		cout << "����һ��" << endl;
		if (score > 700)
		{
			cout << "�����廪" << endl;
		}
		else 
		{
			cout << "�������" << endl;
		}
	}
	else if(score<600 && score>500)
	{
		cout << "���϶���" << endl;
	}
	else
	{
		cout << "û����" << endl;
	}
	//����ֻ������ص�����
	int piga = 0, pigb = 0, pigc = 0;
	int max = 0;
	cout << "��������ֻ�������" << endl;
	cin >> piga;
	cin >> pigb;
	cin >> pigc;
	if (piga > pigb)
	{
		max = piga;
		if (max < pigc)
			max = pigc;	
	}
	else {
		max = pigb;
		if (max < pigc)
			max = pigc;
	}
	cout << "max=" << max << endl;

	//��Ŀ�����
	int x1 = 10, x2 = 20, y = 0;
	c = (x1 > x2) ? x1 : x2;
	cout << "c=" << c<<endl;
	return 0;

}