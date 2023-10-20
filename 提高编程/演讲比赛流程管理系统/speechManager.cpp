#include "speechManager.h"

SpeechManager::SpeechManager()
{
	this->initSpeech();
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
			sp.m_Score[i] = 0;
		}
		//将选手编号插入到V1中
		this->v1.push_back(10001 + i);
		//将编号和人员信息插入到map中
		this->m_s.insert(make_pair(10001 + i, sp));
	}
}


SpeechManager::~SpeechManager()
{

}
