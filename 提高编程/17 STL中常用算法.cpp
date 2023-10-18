#define _CRT_SECURE_NO_WARNINGS 1   
#include <algorithm>
#include <iostream>
#include <numeric>
#include <functional>
#include <vector>
#include <ctime>
using namespace std;


/*
* ���ñ����㷨
* for_each ��������
* transform ������������һ��������
* find�����㷨 ���ص�����
* find_if(beg,end,_pred) ν��  ������������
* adjacent_find(beg,end) ���������ظ�Ԫ��
* bool binary_search(beg,end,val) ����ָ��Ԫ���Ƿ����  ע�������������в����� ���ֲ��ҷ�
* count(beg,end,value)  ͳ��Ԫ�ظ���
* count_if(beg,end,_pred)  ��������ͳ��Ԫ�س��ִ���
* 
* ���������㷨
* sort(beg,end,_pred) ��������Ԫ�ؽ�������
* random_shuffle(beg,end)  ϴ�ƣ���������Ԫ�������������
* merge(beg1,end1,beg2,end2,dest)  ����Ԫ�غϲ������洢����һ������  ���������������
* reverse(beg,end)  ��תָ����Χ��Ԫ��
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

void test_binary_count()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//�����������Ƿ���9   ������������������
	int ret=binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "find it" << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(10);
	int num = count(v1.begin(), v1.end(), 10);
	//������������ͳ��
	cout << "num of 10 :" << num << endl;
	//�Զ�����������ͳ��  �����==���ط�ʹ��
	vector<Person>vp;
	Person p1("vicky", 30);
	Person p2("bob", 1);
	Person p3("bob", 40);
	Person p4("jerry", 1);

	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	Person p("andy", 10);
	int num1 = count(vp.begin(), vp.end(), p4);
	cout << "num of p:" << num1 << endl;
	//count_if   ������������
	num = count_if(v.begin(), v.end(), GreaterFind());
	cout << "num of greater 5 : " << num << endl;
	//�Զ�����������
	num=  count_if(vp.begin(), vp.end(), Greater20());
	cout << "num of p.age greater 20 : " << num << endl;
}

void test_sort_random()
{
	srand((unsigned int)time(NULL));
	vector<int>v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(30);
	v.push_back(60);
	v.push_back(20);
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	//�ı�Ϊ����
	//greaterΪ�ڽ���������
	//sort(v.begin(), v.end(), greater<int>());
	//for_each(v.begin(), v.end(), print01);
	//cout << endl;
	////����˳��
	//random_shuffle(v.begin(), v.end());
	//for_each(v.begin(), v.end(), print01);
	//cout << endl;
	//merge
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//Ŀ������
	vector<int>vt;
	//��Ŀ����������ռ�
	vt.resize(v.size() + v1.size());
	merge(v.begin(), v.end(), v1.begin(), v1.end(), vt.begin());
	for_each(vt.begin(), vt.end(), print01);
	cout << endl;
	//reverse   Ԫ�ؽ��з�ת
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), print01);
	cout << endl;
}


int main()
{

	//test_for_each_transform_find();
	//test_binary_count();
	test_sort_random();
	return 0;
}