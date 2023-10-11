#define _CRT_SECURE_NO_WARNINGS 1   
#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>  //ʹ���㷨ʱ��Ҫ������
using namespace std;

/*
* ˫�����飬���Զ�ͷ�˽��в���ɾ������
* deque��vector������
* 1.vectorͷ������Ч�ʵ�
* 2.dequeͷ������ɾ���ٶȿ�
* 3.vector����Ԫ��ʱ���ٶȻ��deque�죬�����ߺ��ڲ�ʵ���й�
*
* deque�����ĵ�����Ҳ��֧��������ʵ�
* 
* deque����ԭ��
*�ڲ��и��п�����ά��ÿ�λ������е����ݣ��������д����ʵ������
* �п���ά������ÿ������ȴ�ĵ�ַ��ʹ��ʹ��dequeʱ��һƬ�������ڴ�ռ�
*/

void printDeque(const deque<int>& d) //����ֻ�� ��ֹ���޸�
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it<<" ";
	}
	cout << endl;
}

//deque�Ĺ��캯��
void test01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	//ʹ������ķ�ʽ����
	deque<int>d2(d1.begin(),d1.end());
	printDeque(d2);
	//n��elem
	deque<int>d3(10, 100);
	printDeque(d3);
	//��������
	deque<int>d4(d3);
	printDeque(d4);
}

//��ֵ����
// = assign
void test02()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	//��ֵ����
	deque<int>d2;
	d2 = d1;
	printDeque(d2);
	//assign
	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printDeque(d3);
	deque<int>d4;
	d4.assign(10, 100);
	printDeque(d4);
}

//������С
//empty size
//resize����ָ�����������ȱ�ԭ��������Ĭ��ֵ��䣬����ԭ���̣�ɾ������Ԫ��
void test03()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	if (d1.empty())
	{
		cout << "d1 is empty" << endl;
	}
	else
	{
		cout << "d1 is not empty" << endl;
		cout << "d1 size:" << d1.size() << endl;
		//deque����û����������
	}
	//����ָ����С
	d1.resize(15);
	printDeque(d1);
	//���ذ汾����ָ�����ݽ������
	d1.resize(20, 3);
	printDeque(d1);
	d1.resize(5);
	printDeque(d1);
}

//�����ɾ������
//�����ɾ���ṩ��λ���ǵ�����
void test04()
{
	deque<int>d1;
	//β��
	d1.push_back(10);
	d1.push_back(20);
	//ͷ��
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);
	//βɾ
	d1.pop_back();
	d1.pop_front();
	printDeque(d1);

	//insert ���ĸ�λ�ý��в���
	d1.insert(d1.begin(), 1000);
	d1.insert(d1.begin(),2,10000);
	printDeque(d1);
	//����������в���
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d1.insert(d1.begin(), d2.begin(), d2.end());
	printDeque(d1);
	//ɾ������,�����������ɾ��
	d1.erase(d1.begin());
	d1.erase(d1.begin(),d1.end());   //�������
	//clear ���
	d1.clear();
	printDeque(d1);
}

//��ȡ
//at [] front() back()
void test05()
{
	deque<int>d1;
	//β��
	d1.push_back(10);
	d1.push_back(20);
	//ͷ��
	d1.push_front(100);
	d1.push_front(200);
	for (int i = 0; i < d1.size(); i++)
	{
		//����Ԫ��
		cout << d1[i] << " ";
		cout << d1.at(i);
	}
	cout << endl;
	cout << "first elem: " << d1.front() << endl;
	cout << "end elem: " << d1.back() << endl;

}

//�����㷨ʵ�ֶ�deque����������
//sort(beg,end),�������ڵ����ݽ�������
void test06()
{
	deque<int>d1;
	//β��
	d1.push_back(10);
	d1.push_back(20);
	//ͷ��
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);
	//����֧��������ʵ�����������������������sort�㷨ֱ�Ӷ����������
	//vector����Ҳ��������sort��������
	sort(d1.begin(), d1.end());  //Ĭ���������������
	cout << "after sort" << endl;
	printDeque(d1);
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

