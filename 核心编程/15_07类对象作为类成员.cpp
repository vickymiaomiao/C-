#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <string>
using namespace std;

/*
* C++���еĳ�Ա��������һ����Ķ������ǳƸó�ԱΪ�����Ա
* ��������Ķ�����Ϊ����ĳ�Աʱ���ȹ���������Ķ����ڹ�������
* ������˳�������������������������࣬�빹���෴
*/
//�ֻ���
class phone
{
public:
	//���캯�����г�ʼ��
	phone(string name)
	{
		m_PName = name;
		cout << "phone" << endl;
	}
	string m_PName;

	~phone()
	{
		cout << "phone����" << endl;
	}
};

//����
class person 
{
public:
	//��ʼ���б�ķ�ʽ���и�ֵ
	//phone m_phone=pname;
	person(string name,string pname):m_name(name),m_phone(pname)
	{
		cout << "person" << endl;
	}
	string m_name;
	phone m_phone;

	~person()
	{
		cout << "person����" << endl;
	}
};

void test01()
{
	person p("vicky", "iphone 13");
	cout << p.m_name << " takes " << p.m_phone.m_PName << endl;

}

int main()
{
	test01();
	return 0;
}