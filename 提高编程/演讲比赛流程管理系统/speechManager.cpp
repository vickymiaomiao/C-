#include "speechManager.h"

SpeechManager::SpeechManager()
{
	this->initSpeech();
	this->creatSpeaker();
}

//չʾ�˵�
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

//�˳�����
void SpeechManager::exitSystem()
{
	cout << "welcome next use" << endl;
	system("pause");
	exit(0);
}

//��ʼ������
void SpeechManager::initSpeech()
{
	//������֤Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->vv.clear();
	this->m_s.clear();
	//��ʼ����������
	this->m_Index = 1;
}


//����ѡ��
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
		//��ѡ�ֱ�Ų��뵽V1��
		this->v1.push_back(10001 + i);
		//����ź���Ա��Ϣ���뵽map��
		this->m_s.insert(make_pair(10001 + i, sp));
	}
}


SpeechManager::~SpeechManager()
{

}
