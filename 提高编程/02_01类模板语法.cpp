#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* ����һ��ͨ���࣬���еĳ�Ա�������Ϳ��Բ����嶨�ƣ���һ����������������
*����ģ�����ģ�������
* 1.��ģ��û���Զ������Ƶ�ʹ�÷�ʽ
* 2.��ģ����ģ������б��п�����Ĭ�ϲ���
* 
* ��ģ���еĳ�Ա��������ͨ���еĳ�Ա��������ʱ��������
* 1.��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
* 2.��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���
* 
* ��ģ������������Ĳ����������ִ��뷽ʽ��
* 1.ָ�����������---�Ƚϳ���
* 2.����ģ�廯
* 3.������ģ�廯
* 
*/

template<class NameType,class AgeType=int>
class Person
{
public:
	Person(NameType name,AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "m_Name = " << this->m_Name << endl;
		cout << "m_Age = " << this->m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

//1.ָ�����ʹ���
void printPerson1(Person<string, int>&p)
{
	p.showPerson();
}
void test01()
{
	Person<string, int>p("vicky", 18);
	printPerson1(p);
}

//2.����ģ�廯
template<class T1,class T2>
void printPerson2(Person<T1, T2>&p)
{
	p.showPerson();
	//��ӡT1,T2����������
	cout << "T1����������Ϊ��" << typeid(T1).name() << endl;
	cout << "T2����������Ϊ��" << typeid(T2).name() << endl;
}
void test02()
{
	Person<string, int>p("tom", 18);
	printPerson2(p);
}

//3.������ģ�廯

template<class T>
void printPerson3(T &p)
{
	p.showPerson();
	//��ӡT1,T2����������
	cout << "T1����������Ϊ��" << typeid(T).name() << endl;
	
}
void test03()
{
	Person<string, int>p("andy", 18);
	printPerson3(p);
}

int main()
{
	//Person<string> p1("vicky", 18);  //ֻ����ʾ����ת��
	//p1.showPerson();
	test01();
	test02();
	test03();
	return 0;
}