#define _CRT_SECURE_NO_WARNINGS 1   
#include <algorithm>
#include <iostream>
#include <numeric>
#include <functional>
#include <vector>
#include <ctime>
#include <numeric>
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
* 
* ����copy���滻�㷨
* copy  ����
* replace(beg,end,oldv,newv) �滻
* replace_if(beg,end,_pred,newv)  ����������Ԫ�ؽ����滻
* swap �������������е�Ԫ��
* 
* �������������㷨
* ���������㷨����С���㷨��ʹ��ʱ������ͷ�ļ�Ϊ #include <numeric>
* accumulate(beg,end,value) ��������Ԫ���ۼ��ܺ�  valueΪ��ʼ�ۼ�ֵ
* fill(beg,end,value) �����������Ԫ�� valueΪ����ֵ
* 
* ���õļ����㷨
* set_intersection(beg1,end1,beg2,end2,dest)  �����������Ľ���  ����������������������
* set_union(beg1,end1,beg2,end2,dest) �����������Ĳ���  Ҳ��������������
* set_difference �����������Ĳ
* 
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

void test_copy_replace()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	v2.resize(v1.size());  //Ŀ��������ǰ���ٿռ�
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), print01);
	cout << endl;
	//�滻
	replace(v1.begin(), v1.end(), 4, 100);
	for_each(v1.begin(), v1.end(), print01);
	cout << endl;
	//����������ȫ���滻
	replace_if(v1.begin(), v1.end(), GreaterFind(), 200);
	for_each(v1.begin(), v1.end(), print01);
	cout << endl;
	//������������
	swap(v1, v2);
	cout << "after swap------------------" << endl;
	for_each(v1.begin(), v1.end(), print01);
	cout << endl;
	for_each(v2.begin(), v2.end(), print01);
	cout << endl;

}

void test_accumulate_fill()
{
	vector<int>v1;
	for (int i = 0; i <= 100; i++)
	{
		v1.push_back(i);
	}
	//�ۼ�
	int total = accumulate(v1.begin(), v1.end(), 0);  //����3Ϊ��ʼ���ۼ�ֵ
	cout << "total = " << total << endl;
	//���
	vector<int>v2;
	v2.resize(10);
	fill(v2.begin(), v2.end(), 200);
	for_each(v2.begin(), v2.end(), print01);
	cout << endl;
}

void test_set()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i <= 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>vt;
	//Ŀ��������ǰ���ٿռ�
	//��������������������������С���������ٿռ�ȡС������size
	vt.resize(min(v1.size(), v2.size()));//����Сֵ
	//��ȡ����   ���ؽ������һ����������λ��
	vector<int>::iterator itend=set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vt.begin());
	for_each(vt.begin(), itend, print01);
	cout << endl;
	
	//��ȡ����
	//��������ڴ�ռ�
	vt.resize(v1.size() + v2.size());
	vector<int>::iterator itend1 = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vt.begin());
	for_each(vt.begin(), itend1, print01);
	cout << endl;

	//��ȡ�  �������һ��Ԫ�ص�������λ��
	//Ŀ�������Ŀռ�Ϊ����������size
	vt.resize(max(v1.size() , v2.size()));
	cout << "v1��v2�Ĳ��" << endl;
	vector<int>::iterator itend2 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vt.begin());
	for_each(vt.begin(), itend2, print01);
	cout << endl;

	cout << "v2��v1�Ĳ��" << endl;
	vector<int>::iterator itend3 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vt.begin());
	for_each(vt.begin(), itend3, print01);
	cout << endl;

}


int main()
{
	//test_for_each_transform_find();
	//test_binary_count();
	//test_sort_random();
	//test_copy_replace();
	//test_accumulate_fill();
	test_set();
	return 0;
}