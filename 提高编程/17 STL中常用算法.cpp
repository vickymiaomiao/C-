#define _CRT_SECURE_NO_WARNINGS 1   
#include <algorithm>
#include <iostream>
#include <numeric>
#include <functional>
#include <vector>
using namespace std;


/*
* ���ñ����㷨
* for_each ��������
* transform ������������һ��������
* find�����㷨
*/
//��ͨ����
void print01(int val)
{
	cout << val << " ";
}
//�º���
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

class Transform
{
public:
	int operator()(int v)
	{
		return v+100;
	}
};

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void test_for_each_transform_find()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//��ͨ���� ���뺯������
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	//�º��������뺯������
	for_each(v.begin(), v.end(), print02());
	cout << endl;

	//transform(beg1,end1,beg2,func)    ������������һ��������
    //beg1Դ������ʼ������ end1Դ�������������� beg2Ŀ��������ʼ������ �������ߺ�������

	vector<int>vt;
	vt.resize(v.size()); //Ŀ������������ǰ���ٿռ�
	transform(v.begin(), v.end(), vt.begin(), Transform());
	for_each(vt.begin(), vt.end(), print02());
	cout << endl;

	//����Ԫ�� find ��������Ϊ������
	vector<int>::iterator it=find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << "find it: " << *it << endl;
	}
	//�Զ����������Ͳ���
	vector<Person>vp;
	Person p1("vicky", 1);
	Person p2("bob", 1);
	Person p3("tom", 1);
	Person p4("jerry", 1);

}






int main()
{
	test_for_each_transform_find();
	return 0;
}