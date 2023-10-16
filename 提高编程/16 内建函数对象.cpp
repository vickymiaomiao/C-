#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/*
* STL�ڽ���һЩ��������
* ���ࣺ
* �����º��� :plus minus multiplies divides modulus negate
* ��ϵ�º��� :equal not_equal_to greater greater_equal less less_equal
* �߼��º��� :logical_and logical_or logical_not
* 
* �÷�:
* ��Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ
* ʹ���ڽ�����������Ҫ����ͷ�ļ�#include <functional>
* 
* nagate һԪ���� 
*/

//ȡ���º���
void test01()
{
	negate<int>n;
	cout << n(-10) << endl;

	//plus ��Ԫ�º���
	plus<int>p;   //��������ֻдһ��int 
	cout << p(10, 10) << endl;
}

class mycompare
{
public:
	bool operator()(int v1,int v2)
	{
		return v1 > v2;
	}
};

void test02()
{
	vector<int>v1;
	v1.push_back(40);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(50);
	v1.push_back(30);
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//����
	//sort(v1.begin(), v1.end(), mycompare());
	//greater<int>()�ڽ���������
	sort(v1.begin(), v1.end(),greater<int>());

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test03()
{
	vector<bool>v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//�����߼��� ������V���˵�����V2�У���ִ��ȡ������
	vector<bool>v2;
	v2.resize(v1.size());   //Ŀ��������Ҫ��ǰ���ٿռ�
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}