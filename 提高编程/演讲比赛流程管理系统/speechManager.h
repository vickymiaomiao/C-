#pragma once
#include <iostream>
#include <string>
using namespace std;

//设计比赛管理类
class SpeechManager
{
public:
	//构造函数
	SpeechManager();
	//展示菜单
	void show_Menu();

	//退出app
	void exitSystem();


	//析构函数
	~SpeechManager();
};