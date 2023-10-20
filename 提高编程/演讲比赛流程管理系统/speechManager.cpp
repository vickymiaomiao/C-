#include "speechManager.h"
#include <algorithm>

SpeechManager::SpeechManager()
{
	//初始化属性
	this->initSpeech();
	//创建选手
	this->creatSpeaker();
}

//展示菜单
void SpeechManager::show_Menu()
{
	cout << "--------------------------------------" << endl;
	cout << "--- welcome to the speech contest-----" << endl;
	cout << "---------1.opening speech ------------" << endl;
	cout << "---------2.view past records ---------" << endl;
	cout << "---------3.clear the record-----------" << endl;
	cout << "---------0.quit app-------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << endl;
}

//退出程序
void SpeechManager::exitSystem()
{
	cout << "welcome next use" << endl;
	system("pause");
	exit(0);
}

//初始化属性
void SpeechManager::initSpeech()
{
	//容器保证为空
	this->v1.clear();
	this->v2.clear();
	this->vv.clear();
	this->m_s.clear();
	//初始化比赛轮数
	this->m_Index = 1;
}


//创建选手
void SpeechManager::creatSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "speaker ";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		//将选手编号插入到V1中
		this->v1.push_back(10001 + i);
		//将编号和人员信息插入到map中
		this->m_s.insert(make_pair(10001 + i, sp));
	}
}

//开始比赛
void SpeechManager::startSpeach()
{
	//第一轮比赛
	//1.抽签
	this->speechDraw();

	//2.比赛


	//3.显示晋级结果


	//第二轮比赛

	//抽签


	//比赛


	//显示最终结果

	//保存分数



}

//抽签
void SpeechManager::speechDraw()
{
	cout << "第<<" << this->m_Index << ">>轮比赛选手正在抽签" << endl;
	cout << "--------------------" << endl;
	cout << "抽签后的顺序如下：" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------" << endl;
	system("pause");
	cout << endl;
}



SpeechManager::~SpeechManager()
{

}
