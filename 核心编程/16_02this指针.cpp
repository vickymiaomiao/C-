#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* C++ͨ���ṩ����Ķ���ָ�룬thisָ�룬����������⣬thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
*thisָ��������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��
* thisָ�벻��Ҫ���壬ֱ��ʹ�ü���
* 
* thisָ�����;��
* 1.���βκͳ�Ա����ͬ��ʱ������thisָ��������
* 2.����ķǾ�̬��Ա�����з��ض�������ʹ��return *this
*
*/

class person
{
public:
	person(int age)
	{
		//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
		this->age = age;
	}

	person& personaddperson(person& p)  //���õķ�ʽ���أ����ᴴ���µĶ���
	{
		this->age += p.age;
		return *this;
	}


	int age;
};

void test02()
{
	person p1(10);

	person p2(20);
	//��ʽ���˼��
	p2.personaddperson(p1).personaddperson(p1).personaddperson(p1);
	cout << "p2������Ϊ" << p2.age << endl;
}
void test01()
{
	person p1(18);
	cout << "p1������Ϊ" << p1.age << endl;
}



int main()
{
	test01();
	test02();
	return 0;
}