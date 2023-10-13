#define _CRT_SECURE_NO_WARNINGS 1   
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

/*
* ���������ݽ�����ʽ�洢
* ������һ������洢��Ԫ�Ϸ������Ĵ洢�ṹ������Ԫ�ص��߼�˳����ͨ�������е�ָ������ʵ�ֵ�
* 
* ������һϵ�н�����
* ������ɣ�һ���Ǵ洢����Ԫ�ص���������һ���Ǵ洢��һ������ַ��ָ����
* �ŵ㣬���Զ�����λ�ý��п��ٲ������ɾ��Ԫ�أ����ö�̬�洢���䣬��������ڴ��˷�
* ȱ�㣺���������ٶ�û������죬ռ�ÿռ�������
* 
* ˫��ѭ������ÿ�����������ָ�루ָ����һ������һ����
* ����ĵ�������˫���������ֻ֧��ǰ�ƺͺ���
* 
* list�����ɾ�����������ᵼ��ԭ�е�list��������ʧЧ������vector�ǲ�������
* vector��list�������ʹ�õ�����
*/

//��������
void printList(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//���캯��
void test01()
{
	list<int>l1;
	//�������
	l1.push_back(10);
	l1.push_back(10); 
	l1.push_back(10); 
	l1.push_back(10);
	//��������
	printList(l1);

	//��������
	list<int>l2(l1.begin(),l1.end());
	printList(l2);
	//��������
	list<int>l3(l1);
	printList(l3);
	//N��elem
	list<int>l4(10, 100);
	printList(l4);
}

//��ֵ�ͽ���  assign = swap
void test02()
{
	list<int>l1;
	//�������
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);
	list<int>l2;
	l2 = l1;
	printList(l2);
	list<int>l3;
	l3.assign(l2.begin(), l2.end());
	printList(l3);
	list<int>l4;
	l4.assign(10,100);
	printList(l4);

	//swap
	l4.swap(l1);
	cout << "after swap" << endl;
	printList(l1);
	printList(l4);

}

//��С  empty size resize
void test03()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);
	//�ж������Ƿ�Ϊ��
	if (l1.empty())
	{
		cout << "l1 is empty" << endl;
	}
	else
	{
		cout << "l1 is not empty" << endl;
		cout << "l1 size is : " << l1.size() << endl;
	}
	//����ָ����С
	l1.resize(6);
	printList(l1);
	l1.resize(10,100);
	printList(l1);
	l1.resize(4);
	printList(l1);
}

//�����ɾ��
void test04()
{
	list<int>L;
	//β��
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//ͷ��
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);
	printList(L);
	//βɾ
	L.pop_back();
	//ͷɾ
	L.pop_front();
	printList(L);
	//����
	list<int>::iterator it = L.begin();
	L.insert(++it, 1000);
	printList(L);
	//ɾ��  clear���
	it = L.begin();
	L.erase(it);
	printList(L);
	//remove�Ƴ�  ���������е�ƥ��Ԫ��
	L.push_back(10000);
	printList(L);
	L.remove(10000);
	printList(L);
	//���
	L.clear();
	printList(L);
}

//��ȡ front back
void test05()
{
	list<int>L;
	//β��
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	//��������[]����at��ʽ�ṩ��ȡ��ʽ
	//list ���������������������Կռ�洢���ݣ�������Ҳ��֧����Ծ����
	cout << "first elem : " << L.front() << endl;
	cout << "last elem : " << L.back() << endl;

	//��֤��������֧���������
	list<int>::iterator it = L.begin();
	it++; //��֧��it=it+1  ֧��˫��
}


bool myCompare(int val1,int val2)
{
	//���� ��һ�������ڵڶ�����
	return val1 > val2;

}

//��ת������
//�������е�Ԫ�ط�ת���Լ��������е����ݽ�������
//reverse()  sort()
void test06()
{
	list<int>L;
	//β��
	L.push_back(20);
	L.push_back(10);
	L.push_back(40);
	L.push_back(30);
	cout << "before reverse" << endl;
	printList(L);

	L.reverse();
	cout << "after reverse" << endl;
	printList(L);
	//���в�֧��������ʵ��������������������ñ�׼�㷨
	//��֧��������ʵ����������ݣ��ڲ����ṩ��ӦһЩ�㷨
	cout << "after sort" << endl;
	L.sort();     //������������
	printList(L);

	//����ʵ��
	L.sort(myCompare);
	printList(L);

}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	return 0;
}