#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* ��Ա�����ͳ�Ա�����ֿ��洢
* ֻ�зǾ�̬��Ա������������Ķ�����
*/

class Person
{
public:
	int m_A; //�Ǿ�̬��Ա������������Ķ�����
	static int m_B; //��̬��Ա����,��������Ķ�����
	void func() {}    //�Ǿ�̬��Ա��������������Ķ�����
	static void func2() {}   //��̬��Ա��������������Ķ�����
};

int Person::m_B = 10;
void test01()
{
	Person p;
	//�ն���ռ���ڴ�ռ�Ϊ1
	//C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout << "sizeof p=" << sizeof(p) << endl;
}


int main1601()
{
	test01();
	return 0;
}