#define _CRT_SECURE_NO_WARNINGS 1  
#include <set>
#include <string>
#include <iostream>
using namespace std;

/*
* set ����
* ����Ԫ���ڲ���ʱ�����Զ�������
* ����set/multiset���ڹ���ʽ�������ײ�ṹ��ʹ�ö�����ʵ��
* ��������
* set���������������ظ���Ԫ��
* multiset�������������ظ���Ԫ��
* 
*/

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//����͸�ֵ
void test01()
{
	set<int>s1;
	//��������ֻ��insert��ʽ
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//��������   �Զ����򣬲��Ҳ������ظ���ֵ
	printSet(s1);

	set<int>s2(s1);
	printSet(s2);

	set<int>s3;
	s3 = s2;
	printSet(s3);
}

//��С�ͽ�������
//size empty swap
void test02()
{
	set<int>s1;
	//��������ֻ��insert��ʽ
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//��������   �Զ����򣬲��Ҳ������ظ���ֵ
	cout << "before change:" << endl;
	printSet(s1);
	if (s1.empty())
	{
		cout << "s1 is empty" << endl;
	}
	else
	{
		cout << "s1 is not empty" << endl;
		cout << "s1 size : " << s1.size() << endl;
	}
	set<int>s2;
	s2.insert(100);
	s2.insert(200);
	s2.insert(300);
	s2.insert(400);
	printSet(s2);
	cout << "after change" << endl;
	s1.swap(s2);
	printSet(s1); 
	printSet(s2);
	//��֧��resize

}

//�����ɾ��
//insert erase(���԰��յ�����Ҳ����ɾ��ָ��Ԫ��) clear 
void test03()
{
	set<int>s1;
	//��������ֻ��insert��ʽ
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//��������   �Զ����򣬲��Ҳ������ظ���ֵ

	printSet(s1);
	//ɾ��
	s1.erase(s1.begin());
	printSet(s1);
	//s1.erase(s1.begin(),s1.end());
	//printSet(s1);
	s1.erase(30);//ɾ��ָ��Ԫ��
	printSet(s1);
	//��� clear
	s1.clear();
	printSet(s1);
}

//���Һ�ͳ��
//��set�������в������ݺ�ͳ������
//find ����key�Ƿ���ڣ������ڣ����ظ�Ԫ�صĵ��������������ڣ�����set.end()
//count ͳ��key�е�Ԫ�ظ���
void test04()
{
	set<int>s1;
	//��������ֻ��insert��ʽ
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//����Ԫ��λ��
	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end())
	{
		cout << "find elem:" << *pos << endl;
	}
	else
	{
		cout << "not find" << endl;
	}
	//ͳ��Ԫ�ظ���
	//����set���ԣ�ͳ�ƵĽ��Ҫô��0��Ҫô��1
	cout << "30 count:" << s1.count(30) << endl;
}

//set�����Բ����ظ�����
//set��������ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ�
//multiset���������ݣ���˿��Բ����ظ�������
void test05()
{
	set<int> s;
	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second)
	{
		cout << "first insert success" << endl;
	}
	else
	{
		cout << "first insert fail" << endl;
	}
	ret=s.insert(10);
	if (ret.second)
	{
		cout << "second insert success" << endl;
	}
	else
	{
		cout << "second insert fail" << endl;
	}
	multiset<int>ms;
	//��������ظ���ֵ
	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

//pair ���鴴��
//�ɶԳ��ֵ����ݣ����ö�����Է�����������
//pair<type,type> p(value1,value2)
//pair<type,type> p=make_pair(value1,value2)
void test06()
{
	//��һ�ַ�ʽ
	pair<string, int> p("vicky", 18);
	cout << "name : " << p.first << "    age : " << p.second << endl;

	//�ڶ��ַ�ʽ
	pair<string, int> p2 = make_pair("bob", 18);
	cout << "name : " << p2.first << "    age : " << p2.second << endl;
}

//�º���  ������һ����������
class MyCompare
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};

//set����Ĭ�ϵ��������Ϊ����������θı��������
//��Ҫ�����㣺���÷º��������Ըı��������
void test07()
{
	set<int>s1;
	s1.insert(80);
	s1.insert(10);
	s1.insert(30);
	s1.insert(50);
	s1.insert(40);
	printSet(s1);
	//ָ���������Ϊ�Ӵ�С
	//set<int, MyCompare>s2;
	//s2.insert(80);
	//s2.insert(10);
	//s2.insert(30);
	//s2.insert(50);
	//s2.insert(40);
	//for (set<int,MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;
	
}

//set��������Զ�����������
class Person
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

class compareperson
{
public:
	bool operator()(const Person& p1,const Person& p2) const
	{
		//�������併��
		return p1.m_Age > p2.m_Age;
	}
};

void test08()
{
	//�Զ�����������ͣ�����ָ���������
	set<Person, compareperson>s;
	//����person
	Person p1("tom", 20);
	Person p2("vicky", 22);
	Person p3("bob", 30);
	Person p4("andy", 8);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, compareperson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << it->m_Name << " : " << it->m_Age << endl;
	}
	

}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();
	return 0;
}