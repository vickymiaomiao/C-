#include <iostream>
#include <string>
#include "speechManager.h"
using namespace std;

int main()
{
	//创建管理类对象
	SpeechManager sm;
	//测试创建的12名选手
	//for (map<int, Speaker>::iterator it = sm.m_s.begin(); it != sm.m_s.end(); it++)
	//{
	//	cout << "编号：" << it->first << "  name : " << it->second.m_Name << "  score : "
	//		<< it->second.m_Score[0] <<  endl;
	//}
	//添加随机数的种子
	srand((unsigned int)time(NULL));

	int choice = 0;
	while (true)
	{
		sm.show_Menu();
		cout << "please enter your selection：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:   //开始比赛
			sm.startSpeach();
			break;
		case 2:   //查看比赛记录
			sm.showRecord();
			break;
		case 3:    //清空比赛记录
			sm.clearRecord();
			break;
		case 0:
			sm.exitSystem();  //退出app
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}