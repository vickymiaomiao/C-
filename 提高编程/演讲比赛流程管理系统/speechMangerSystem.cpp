#include <iostream>
#include <string>
#include "speechManager.h"
using namespace std;

int main()
{
	//�������������
	SpeechManager sm;
	//���Դ�����12��ѡ��
	//for (map<int, Speaker>::iterator it = sm.m_s.begin(); it != sm.m_s.end(); it++)
	//{
	//	cout << "��ţ�" << it->first << "  name : " << it->second.m_Name << "  score : "
	//		<< it->second.m_Score[0] <<  endl;
	//}
	//��������������
	srand((unsigned int)time(NULL));

	int choice = 0;
	while (true)
	{
		sm.show_Menu();
		cout << "please enter your selection��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:   //��ʼ����
			sm.startSpeach();
			break;
		case 2:   //�鿴������¼
			sm.showRecord();
			break;
		case 3:    //��ձ�����¼
			sm.clearRecord();
			break;
		case 0:
			sm.exitSystem();  //�˳�app
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}