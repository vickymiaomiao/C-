#define _CRT_SECURE_NO_WARNINGS 1   
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

/*
* ��˾��Ƹ10��Ա����10��Ա�����빫˾֮����Ҫָ��Ա���Ĳ���
* Ա����Ϣ�����������ʣ����ŷ�Ϊ���߻������з�
* �����10��Ա�����䲿�ź͹���
* ͨ��multimap������Ϣ����
* �ֲ�����ʾԱ����Ϣ
*/

class Worker
{
public:
	string m_Name;
	int m_Salary;
};
void creatWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "worker-";
		worker.m_Name += nameSeed[i];
		worker.m_Salary = rand() % 10000 + 10000;//10000~19999
		v.push_back(worker);
	}
}

//Ա������
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����������ű��
		int deptId = rand() % 3;
		//��Ա�����뵽������
		//key�����ű�ţ�*IT��ʾ�������
		m.insert(make_pair(deptId, *it));
	}
}
//������ʾ
void showWorkerByGroup(multimap<int, Worker>&m)
{
	cout << "�߻����ŵ���Ϣ" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int index = 0;
	int count = m.count(CEHUA);
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "name: " << pos->second.m_Name << " salary :" << pos->second.m_Salary << endl;
	}

	cout << "�������ŵ���Ϣ" << endl;
	pos = m.find(MEISHU);
	index = 0;
	count = m.count(MEISHU);
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "name: " << pos->second.m_Name << " salary :" << pos->second.m_Salary << endl;
	}

	cout << "�з����ŵ���Ϣ" << endl;
	pos = m.find(YANFA);
	index = 0;
	count = m.count(YANFA);
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "name: " << pos->second.m_Name << " salary :" << pos->second.m_Salary << endl;
	}
	

}

int main()
{
	srand((unsigned int)time(NULL));
	//����Ա��
	vector<Worker>v;
	creatWorker(v);
	//����
	//for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "name : " << it->m_Name << " salary: " << it->m_Salary << endl;
	//}
	//����
	multimap<int, Worker>m;
	setGroup(v, m);
	//������ʾԱ��
	showWorkerByGroup(m);
	return 0;
}