#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>  //使用算法时需要包含的
using namespace std;

//有5名选手：ABCDE，10个评委对每一名选手进行打分，去除最高分，去除最低分，取平均分
class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;
	int m_Score;
};


void creatPerson(vector<Person>&v)//引用方式传入
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手：";
		name += nameSeed[i];

		int score = 0;
		Person p(name, score);
		//将创建的person放入到容器中
		v.push_back(p);
	}
}

void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的分数放入容器中
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;    //60到100区间的随机数
			d.push_back(score);
		}
		//cout << "选手：" << it->m_Name << " 打分 " << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;
		//排序
		sort(d.begin(), d.end());
		//去除最高和对低分
		d.pop_front();
		d.pop_back();
		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += (*dit);  //累加每个评委的分数
		}
		int avg = sum / d.size();
		//将平均分赋值给选手
		(*it).m_Score = avg;
	}
}
//显示最后得分
void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
	cout << "name : " << (*it).m_Name << " score : " << it->m_Score << endl;
	}
}

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//创建5名选手
	vector<Person> v;
	creatPerson(v);
	//测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "name : " << (*it).m_Name << " score : " << it->m_Score << endl;
	//}
	//选手打分
	setScore(v);
	//显示最后得分
	showScore(v);
	return 0;
}