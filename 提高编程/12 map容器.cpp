#define _CRT_SECURE_NO_WARNINGS 1 
#include<iostream>
#include <map>
#include <string>
using namespace std;

/*
* map�����е�����Ԫ�ض���pair
* pair�е�һ��Ԫ��Ϊkey��ֵ�����������ã��ڶ���Ԫ��Ϊvalue
* map������Ч�ʸ�����
* ����Ԫ�ض�����ݼ�ֵ�Զ�����
* 
* ���ʣ�
* map/multimap���ڹ���ʽ�������ײ�ṹʹ�ö�����ʵ��
* �ŵ㣺
* ���Ը���keyֵ�����ҵ�valueֵ
* map��multimap������
* map�в��������ظ�keyֵԪ��
* multimap�������������ظ�keyֵԪ��
* mapԪ��������Ԫ�ض��ǳɶԳ��֣���������ʱҪʹ�ö���
*/
void printMap(map<int, int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		//����
		cout << "key : " << it->first << "    value : " << it->second << endl;
	}
}

//����͸�ֵ
void test01()
{
	//����map����
	map<int, int>m;
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(2, 20));
	
	printMap(m);

	//��������
	map<int, int>m2(m);
	printMap(m2);
	//��ֵ
	map<int, int>m3;
	m3 = m2;
	printMap(m3);
}

//map��С�ͽ���
//size empty swap()
void test02()
{
	map<int, int>m;
	cout << "before swap" << endl;
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(2, 20));

	printMap(m);
	if (m.empty())
	{
		cout << "map is empty" << endl;
	}
	else
	{
		cout << "map is not empty" << endl;
		cout << "map size is :" << m.size() << endl;
	}
	map<int, int>m1;
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(4, 40));
	printMap(m1);
	cout << "after swap" << endl;
	m.swap(m1);
	printMap(m);
	printMap(m1);



}

//�����ɾ��
//insert clear erase erase(key)ɾ��������Ϊkey��Ԫ��
void test03()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	//�ڶ���
	m.insert(make_pair(2, 20));
	//������
	m.insert(map<int, int>::value_type(3, 30));
	//������  ��������룬������key������value
	m[4] = 40;
	printMap(m);
	cout << m[5] << endl;   //key�������򴴽�valueֵΪ0������
	m.erase(m.begin());
	printMap(m);
	m.erase(3);//ɾ��keyΪ3������
	printMap(m);
	m.erase(m.begin(), m.end());//��ղ���
	m.clear();
	printMap(m);

}

//���Һ�ͳ��
//find ����key�Ƿ���ڣ������ڣ����ظü���Ԫ�ص��������������ڣ�����m.end()
//count ͳ��key ��Ԫ�ظ���
void test04()
{
	map<int, int>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	map<int, int>::iterator pos = m.find(4);//����Ԫ�صĵ�������������Ҫ�õ���������
	if (pos != m.end())
	{
		cout << "find it" << endl;
		cout << " key = " << pos->first << " value = " << pos->second << endl;
	}
	else
	{
		cout << "not find" << endl;
	}
	//map����������ظ���key������count���Ҫô��0Ҫô��1 multimap��count���ܴ���1
	int num = m.count(3);
	cout << num << endl;
}

class MyCompare
{
public:
	bool operator()(int v1,int v2) const
	{
		return v1 > v2;
	}
};

//����
//Ĭ���������Ϊ�������÷º����ı��������
void test05()
{
	map<int, int,MyCompare>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		//����
		cout << "key : " << it->first << "    value : " << it->second << endl;
	}
}



int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}