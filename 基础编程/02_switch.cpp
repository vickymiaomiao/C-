#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
using namespace std;

int main02()
{
	//�����û�����ķ�������ʾ���Ľ��
	int score=0;
	cout << "�����Ӱ��֣�" << endl;
	cin >> score;
	cout << "����ķ���Ϊ��" << score << endl;
	//�ж�ֻ�������λ����ַ��ͣ��ṹ������ִ��Ч�ʸ�
	switch (score)  
	{
	case 10:
		cout << "����" << endl;
		break;//�˳���ǰ��֧
	case 9:
		cout << "�ܺ�" << endl;
		break;
	case 8:
		cout << "����" << endl;
		break;
	case 7:
		cout << "һ��" << endl;
		break;
	case 6:
		cout << "�ϲ�" << endl;
		break;
	default://ǰ�涼�����㣬���ִ�����
		cout << "��Ƭ" << endl;
		break;
	}
	return 0;
}