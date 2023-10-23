#include "speechManager.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <fstream>
#include <ctime>

SpeechManager::SpeechManager()
{
	//初始化属性
	this->initSpeech();
	//创建选手
	this->creatSpeaker();
	//获取往届记录
	this->loadRecord();
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
	this->m_Record.clear();
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

//比赛
void SpeechManager::speechContest()
{
	cout << "第<<" << this->m_Index << ">>轮比赛正式开始" << endl;
	//准备临时的容器存放小组的成绩
	multimap<double, int, greater<double>> groupScore;
	int num = 0;   //记录人员个数  6人一组

	vector<int>v_src;//比赛选手的容器
	if (this->m_Index == 1)
	{
		v_src = v1;
	}
	else
	{
		v_src = v2;
	}
	//遍历所有选手进行比赛  遍历的是编号
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
	{
		num++;
		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600)/10.f;   //600~1000
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());  //降序排序
		d.pop_front();  //去除最高分
		d.pop_back();   //去除最低分
		double sum = accumulate(d.begin(), d.end(), 0.0f);//计算总分
		double avg = sum / (double)d.size();//计算平均分

		//将平均分放入到map容器中
		this->m_s[*it].m_Score[this->m_Index - 1] = avg;
		//打印平均分
		//cout << "编号：" << *it << " 姓名：" << this->m_s[*it].m_Name << " 平均分：" << this->m_s[*it].m_Score[this->m_Index - 1] << endl;
		//将打分的数据放入到临时容器中
		groupScore.insert(make_pair(avg, *it));//key是得分，value是选手编号
		//每6个人去除前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组名次如下：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << " 姓名：" << this->m_s[it->second].m_Name << "比赛成绩：" << this->m_s[it->second].m_Score[this->m_Index - 1] << endl;
			}
			//取走前三名
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
			groupScore.clear();//清空临时容器
			cout << endl;
		}
	}
	cout << "第<<" << this->m_Index << ">>轮比赛结束" << endl;
	system("pause");

}

//显示比赛结果
void SpeechManager::showScore()
{
	cout << "第<<" << this->m_Index << ">>轮比赛晋级选手信息如下：" << endl;

	vector<int>v;//比赛选手的容器
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
		cout << "编号：" << *it << " 姓名：" << this->m_s[*it].m_Name
			<< "比赛成绩：" << this->m_s[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}

//保存分数
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);  //用输出的方式打开文件   --写文件
	for (vector<int>::iterator it = vv.begin(); it != vv.end(); it++)
	{
		ofs << *it << "," << m_s[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "记录已经保存" << endl;
	this->fileIsEmpty = false;
	system("pause");
}

//开始比赛
void SpeechManager::startSpeach()
{
	//第一轮比赛
	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示晋级结果
	this->showScore();
	//第二轮比赛
	this->m_Index++;
	//抽签
	this->speechDraw();
	//比赛
	this->speechContest();
	//显示最终结果
	this->showScore();
	//保存分数
	this->saveRecord();
	//重置比赛
	//初始化比赛
	this->initSpeech();
	//创建选手
	this->creatSpeaker();
	//获取往届记录
	this->loadRecord();
	
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

//读取记录
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);   //输入流对象
	if (!ifs.is_open())//如果不能打开文件
	{
		this->fileIsEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())  //如果读一个字符读到文件尾
	{
		this->fileIsEmpty = true;
		cout << "文件为空" << endl;
		ifs.close();
		return;
	}
	//文件不为空
	this->fileIsEmpty = false;
	ifs.putback(ch);   //将读走的字符放回去

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
			pos = data.find(",", start);//从0开始找","
			if (pos == -1)
			{
				break;//找不到break返回
			}
			string tmp = data.substr(start, pos - start);//进行分割，参数1起始位置，参数2，截取长度
			v.push_back(tmp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
	//for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	//{
	//	cout << it->first << " 冠军编号： " << it->second[0] << " 分数：" << it->second[1] << endl;
	//}
}

//显示往届得分
void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届" <<
				" 冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] <<
				" 亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] <<
				" 季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

//清空记录
void SpeechManager::clearRecord()
{
	cout << "确认清空?" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//打开模式，trunc表示如果文件存在删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//初始化属性
		this->initSpeech();
		//创建选手
		this->creatSpeaker();
		//获取往届记录
		this->loadRecord();
		cout << "清空成功" << endl;
	}
}


SpeechManager::~SpeechManager()
{

}
