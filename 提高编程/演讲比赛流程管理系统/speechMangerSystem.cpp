#include <iostream>
#include <string>
#include "speechManager.h"
using namespace std;

int main()
{
	//创建管理类对象
	SpeechManager sm;
	
	int choice = 0;
	while (true)
	{
		sm.show_Menu();
		cout << "please enter your selection：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:   //开始比赛
			break;
		case 2:   //查看比赛记录
			break;
		case 3:    //清空比赛记录
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