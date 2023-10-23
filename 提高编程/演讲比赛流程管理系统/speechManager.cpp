#include "speechManager.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <fstream>
#include <ctime>

SpeechManager::SpeechManager()
{
	//��ʼ������
	this->initSpeech();
	//����ѡ��
	this->creatSpeaker();
	//��ȡ�����¼
	this->loadRecord();
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
	this->m_Record.clear();
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

//����
void SpeechManager::speechContest()
{
	cout << "��<<" << this->m_Index << ">>�ֱ�����ʽ��ʼ" << endl;
	//׼����ʱ���������С��ĳɼ�
	multimap<double, int, greater<double>> groupScore;
	int num = 0;   //��¼��Ա����  6��һ��

	vector<int>v_src;//����ѡ�ֵ�����
	if (this->m_Index == 1)
	{
		v_src = v1;
	}
	else
	{
		v_src = v2;
	}
	//��������ѡ�ֽ��б���  �������Ǳ��
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600)/10.f;   //600~1000
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());  //��������
		d.pop_front();  //ȥ����߷�
		d.pop_back();   //ȥ����ͷ�
		double sum = accumulate(d.begin(), d.end(), 0.0f);//�����ܷ�
		double avg = sum / (double)d.size();//����ƽ����

		//��ƽ���ַ��뵽map������
		this->m_s[*it].m_Score[this->m_Index - 1] = avg;
		//��ӡƽ����
		//cout << "��ţ�" << *it << " ������" << this->m_s[*it].m_Name << " ƽ���֣�" << this->m_s[*it].m_Score[this->m_Index - 1] << endl;
		//����ֵ����ݷ��뵽��ʱ������
		groupScore.insert(make_pair(avg, *it));//key�ǵ÷֣�value��ѡ�ֱ��
		//ÿ6����ȥ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С���������£�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << " ������" << this->m_s[it->second].m_Name << "�����ɼ���" << this->m_s[it->second].m_Score[this->m_Index - 1] << endl;
			}
			//ȡ��ǰ����
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&& count<3; it++,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					vv.push_back(it->second);
				}
			}
			groupScore.clear();//�����ʱ����
			cout << endl;
		}
	}
	cout << "��<<" << this->m_Index << ">>�ֱ�������" << endl;
	system("pause");

}

//��ʾ�������
void SpeechManager::showScore()
{
	cout << "��<<" << this->m_Index << ">>�ֱ�������ѡ����Ϣ���£�" << endl;

	vector<int>v;//����ѡ�ֵ�����
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vv;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "��ţ�" << *it << " ������" << this->m_s[*it].m_Name
			<< "�����ɼ���" << this->m_s[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}

//�������
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);  //������ķ�ʽ���ļ�   --д�ļ�
	for (vector<int>::iterator it = vv.begin(); it != vv.end(); it++)
	{
		ofs << *it << "," << m_s[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;
	this->fileIsEmpty = false;
	system("pause");
}

//��ʼ����
void SpeechManager::startSpeach()
{
	//��һ�ֱ���
	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ�������
	this->showScore();
	//�ڶ��ֱ���
	this->m_Index++;
	//��ǩ
	this->speechDraw();
	//����
	this->speechContest();
	//��ʾ���ս��
	this->showScore();
	//�������
	this->saveRecord();
	//���ñ���
	//��ʼ������
	this->initSpeech();
	//����ѡ��
	this->creatSpeaker();
	//��ȡ�����¼
	this->loadRecord();
	
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

//��ȡ��¼
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);   //����������
	if (!ifs.is_open())//������ܴ��ļ�
	{
		this->fileIsEmpty = true;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())  //�����һ���ַ������ļ�β
	{
		this->fileIsEmpty = true;
		cout << "�ļ�Ϊ��" << endl;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	ifs.putback(ch);   //�����ߵ��ַ��Ż�ȥ

	string data;
	int index = 0;
	while (ifs >> data)
	{
		//cout << data << endl;
		vector<string>v;
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);//��0��ʼ��","
			if (pos == -1)
			{
				break;//�Ҳ���break����
			}
			string tmp = data.substr(start, pos - start);//���зָ����1��ʼλ�ã�����2����ȡ����
			v.push_back(tmp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
	//for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	//{
	//	cout << it->first << " �ھ���ţ� " << it->second[0] << " ������" << it->second[1] << endl;
	//}
}

//��ʾ����÷�
void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "��" <<
				" �ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] <<
				" �Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] <<
				" ������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

//��ռ�¼
void SpeechManager::clearRecord()
{
	cout << "ȷ�����?" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//��ģʽ��trunc��ʾ����ļ�����ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//��ʼ������
		this->initSpeech();
		//����ѡ��
		this->creatSpeaker();
		//��ȡ�����¼
		this->loadRecord();
		cout << "��ճɹ�" << endl;
	}
}


SpeechManager::~SpeechManager()
{

}
