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
* find�����㷨 ���ص�����
* find_if(beg,end,_pred) ν��  ������������
* adjacent_find(beg,end) ���������ظ�Ԫ��
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
	//����һ�� ==�� �õײ�֪����ζԱ�person����������
	bool operator==(const Person &p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	string m_Name;
	int m_Age;
};

class GreaterFind
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

class Greater20
{
public:
	bool operator()(Person &p)
	{
		return p.m_Age > 20;
	}
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
	Person p3("tom", 30);
	Person p4("jerry", 1);

	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	//�����Ƿ����P2
	vector<Person>::iterator it1 = find(vp.begin(), vp.end(), p2);
	if (it1 == vp.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << "find it: " << it1->m_Name<<" : "<<it1->m_Age<< endl;
	}
	//find_if
	//1������������������
	vector<int>::iterator it2=find_if(v.begin(), v.end(), GreaterFind());
	if (it2 == v.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << "find it: " << *it2<< endl;
	}
	//2.���Ҷ�����������
	vector<Person>::iterator it3 = find_if(vp.begin(), vp.end(), Greater20());
	if (it3 == vp.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << "find it: " << it3->m_Name << " : " << it3->m_Age << endl;
	}

	//adjacent_find  ���������ظ�Ԫ��
	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos == v.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << "find it: " << *pos << endl;
	}


}






int main()
{
	test_for_each_transform_find();
	return 0;
}