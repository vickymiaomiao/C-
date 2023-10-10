#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <string>
using namespace std;

/*
* ȫ�ֺ�������ʵ��--ֱ��������������Ԫ����
* ȫ�ֺ�������ʵ��---��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
*/
template<class T1, class T2>   //��ǰ�ñ�����֪��ģ��Ĵ���
class Person;

template<class T1, class T2>
void printPerson2(Person<T1, T2> p)
{
	cout << p.m_Name << endl;
	cout << p.m_Age << endl;
	cout << "����ʵ��" << endl;
}

//ͨ��ȫ�ֺ�����ӡperson����Ϣ

template<class T1, class T2>
class Person
{
	//ȫ�ֺ�������ʵ��
	friend void printPerson(Person<T1,T2> p)
	{
		cout << p.m_Name << endl;
		cout << p.m_Age << endl;
		cout << "����ʵ��" << endl;
	}
	//ȫ�ֺ�������ʵ��
	friend void printPerson2<>(Person<T1, T2> p);//��ӿ�ģ��Ĳ����б�


public:
	//���캯��
	Person(T1 name, T2 age);

private:
	T1 m_Name;
	T2 m_Age;
};



//����ʵ�֣�����ֻд����
//���캯��
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)   //��ʾ��ģ��ĳ�Ա����ʵ��
{
	this->m_Name = name;
	this->m_Age = age;
}
////��Ա����
//template<class T1, class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << this->m_Name << endl;
//	cout << this->m_Age << endl;
//}

void test01()
{
	Person<string, int> p("vicky", 18);
	printPerson(p);
	printPerson2<string,int>(p);
	
}


int main()
{
	test01();
	return 0;
}