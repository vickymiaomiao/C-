#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;

//
// 1.���캯���ķ���
//���ղ������࣬�в���������޲������죨Ĭ�Ϲ��죩
//�������ͷ���  ��ͨ���캯���Ϳ������캯��
class Person
{
public:
	//���캯��  
	Person()
	{
		cout << "person ���޲ι��캯���ĵ���" << endl;
	} 
	Person(int a)
	{
		age = a;
		cout << "person int a �вι��캯���ĵ���" << endl;
	}
	//�������캯��
	Person(const Person &p)
	{
		//�����������ϵ��������Կ�������ǰ������
		age = p.age;
		cout << "person �������캯���ĵ���" << endl;
	}

	//��������
	~Person()
	{
		cout << "person���������ĵ���" << endl;
	}

	int age;
};


void test1502()
{
	//���÷���
	//1�����ŷ�
	//Person p1;   //Ĭ�Ϲ��캯���ĵ���
	//Person p2(10);  //�вκ����ĵ���
	////�������캯���ĵ���
	//Person p3(p2);

	////ע������1
	////����Ĭ�Ϲ��캯��ʱ��Ҫ�ӣ���
	////��ΪPerson p1();�ᱻ��������Ϊ�Ǻ�����������������Ϊ���ڴ�������
	//cout << "p2������Ϊ��" << p2.age << endl;
	//cout << "p3������Ϊ��" << p3.age << endl;

	//2����ʾ��
	Person p1;
	Person p2 = Person(10);   //�вι���  
	//Person(10)���������ص㣺��ǰ��ִ�н�����ϵͳ���������յ���������
	Person p3 = Person(p2);

	//ע������2
	// ��Ҫ���ÿ������캯������ʼ����������,������Person (p3)==Person p3;���������
	//
	//��ʽת����
	Person p4 = 10;  //Person p2 = Person(10);
	Person p5 = p4;   //��������


}


int main1502()
{
	test1502();
	return 0;
}