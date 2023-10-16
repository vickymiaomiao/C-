#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
* ����bool���͵ķº�����Ϊν��
* ���operator�����н���һ��������ΪһԪν�ʣ���������������Ժν��
*/
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//���������Ƿ��д���5������
	//GreaterFive()  ������������
	vector<int>::iterator it=find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << "find it :" <<*it<< endl;
	}

	vector<int>v1;
	v1.push_back(40);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(50);
	v1.push_back(30);
	sort(v1.begin(), v1.end());
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//ʹ�ú������󣬸ı��㷨���ԣ���Ϊ�������Ӵ�С
	sort(v1.begin(), v1.end(), MyCompare());
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

int main()
{
	test01();
	return 0;
}