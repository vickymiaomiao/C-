#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#include "speaker.h"

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


	
	//比赛选手 容器 12人  编号
	vector<int>v1;
	//第二轮晋级容器 6人
	vector<int>v2;
	//前三名
	vector<int>vv;
	//存放编号以及对应的具体选手 容器
	map<int, Speaker> m_s;

	//记录比赛轮数
	int m_Index;

	//初始化属性
	void initSpeech();

	//创建选手
	void creatSpeaker();

	//析构函数
	~SpeechManager();



};