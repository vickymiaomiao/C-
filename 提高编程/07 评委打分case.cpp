#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>  //ʹ���㷨ʱ��Ҫ������
using namespace std;

//��5��ѡ�֣�ABCDE��10����ί��ÿһ��ѡ�ֽ��д�֣�ȥ����߷֣�ȥ����ͷ֣�ȡƽ����
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


void creatPerson(vector<Person>&v)//���÷�ʽ����
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ�֣�";
		name += nameSeed[i];

		int score = 0;
		Person p(name, score);
		//��������person���뵽������
		v.push_back(p);
	}
}

void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����ί�ķ�������������
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;    //60��100����������
			d.push_back(score);
		}
		//cout << "ѡ�֣�" << it->m_Name << " ��� " << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;
		//����
		sort(d.begin(), d.end());
		//ȥ����ߺͶԵͷ�
		d.pop_front();
		d.pop_back();
		//ȡƽ����
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += (*dit);  //�ۼ�ÿ����ί�ķ���
		}
		int avg = sum / d.size();
		//��ƽ���ָ�ֵ��ѡ��
		(*it).m_Score = avg;
	}
}
//��ʾ���÷�
void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
	cout << "name : " << (*it).m_Name << " score : " << it->m_Score << endl;
	}
}

int main()
{
	//���������
	srand((unsigned int)time(NULL));
	//����5��ѡ��
	vector<Person> v;
	creatPerson(v);
	//����
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "name : " << (*it).m_Name << " score : " << it->m_Score << endl;
	//}
	//ѡ�ִ��
	setScore(v);
	//��ʾ���÷�
	showScore(v);
	return 0;
}