#include "speechManager.h"
#include <algorithm>

SpeechManager::SpeechManager()
{
	//��ʼ������
	this->initSpeech();
	//����ѡ��
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
			sp.m_Score[j] = 0;
		}
		//��ѡ�ֱ�Ų��뵽V1��
		this->v1.push_back(10001 + i);
		//����ź���Ա��Ϣ���뵽map��
		this->m_s.insert(make_pair(10001 + i, sp));
	}
}

//��ʼ����
void SpeechManager::startSpeach()
{
	//��һ�ֱ���
	//1.��ǩ
	this->speechDraw();

	//2.����


	//3.��ʾ�������


	//�ڶ��ֱ���

	//��ǩ


	//����


	//��ʾ���ս��

	//�������



}

//��ǩ
void SpeechManager::speechDraw()
{
	cout << "��<<" << this->m_Index << ">>�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "--------------------" << endl;
	cout << "��ǩ���˳�����£�" << endl;
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
