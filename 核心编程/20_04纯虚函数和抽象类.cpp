#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/* 
*�ڶ�̬�У�ͨ���������麯����ʵ���Ǻ�������ģ���Ҫ���ǵ���������д������
*��˿��Խ��麯����Ϊ���麯��
*���麯���﷨��virtual ����ֵ���� ������ �������б�= 0;
*���������˴��麯���������Ҳ��Ϊ�˳�����
*
* �������ص㣺
* 1.�޷�ʵ��������
* 2.���������д�������еĴ��麯��������Ҳ���ڳ�����
*/

class Base
{
public:
	//ֻҪ��һ�����麯����������Ϊ������
	virtual void func() = 0;     //���麯��
};

class Son :public Base
{
public:
	void func()
	{
		cout << "func()" << endl;
	}

};


void test01()
{
	//Base b;   �������޷�ʵ��������
	//new Base   �������޷�ʵ��������
	//Son s;    ���಻��д���麯�����޷���������
	Base * b=new Son;  //��̬�ķ�ʽ����
	b->func();

}


int main()
{
	test01();
	return 0;
}