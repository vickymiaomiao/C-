#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* ����ģ�������̳�ʱ����Ҫע�����¼���
* 1.������̳еĸ�����һ����ģ��ʱ��������Ҫָ��������T������
* 2.�����ָ�����������޷�����������ڴ�
* 3.��������ָ���������е�T�����ͣ�����Ҳ��Ҫ��Ϊ��ģ��
*/

template<class T>
class Base
{
	T m;
};

class Son :public Base<int>
{

};

void test01()
{
	Son s1;
}

template<class T1,class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "T1������Ϊ" << typeid(T1).name() << endl;
		cout << "T2������Ϊ" << typeid(T2).name() << endl;
	}
	T1 obj;
};
void test02()
{
	Son2<int, char>s2;
}

int main()
{
	test02();
	return 0;
}