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
* 公司招聘10个员工，10名员工进入公司之后需要指派员工的部门
* 员工信息有姓名，工资；部门分为：策划美术研发
* 随机给10名员工分配部门和工资
* 通过multimap进行信息插入
* 分部门显示员工信息
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

//员工分组
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//产生随机部门编号
		int deptId = rand() % 3;
		//将员工插入到分组中
		//key代表部门编号，*IT表示具体的人
		m.insert(make_pair(deptId, *it));
	}
}
//分组显示
void showWorkerByGroup(multimap<int, Worker>&m)
{
	cout << "策划部门的信息" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int index = 0;
	int count = m.count(CEHUA);
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "name: " << pos->second.m_Name << " salary :" << pos->second.m_Salary << endl;
	}

	cout << "美术部门的信息" << endl;
	pos = m.find(MEISHU);
	index = 0;
	count = m.count(MEISHU);
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "name: " << pos->second.m_Name << " salary :" << pos->second.m_Salary << endl;
	}

	cout << "研发部门的信息" << endl;
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
	//创建员工
	vector<Worker>v;
	creatWorker(v);
	//测试
	//for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "name : " << it->m_Name << " salary: " << it->m_Salary << endl;
	//}
	//分组
	multimap<int, Worker>m;
	setGroup(v, m);
	//分组显示员工
	showWorkerByGroup(m);
	return 0;
}