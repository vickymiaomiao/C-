#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;
/*
* ��������Ԫ�������Ҳ��������
* �������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
* �º���û�й̶�д�����ǳ����
* 
* ������������
*/
class MyPrint
{
public:
	//���غ������������
	void operator()(string test)
	{
		cout << test << endl;
	}
};
//�ӷ���
class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void myprint02(string test)
{
	cout << test << endl;
}

void test01()
{
	MyPrint myprint;
	myprint("hello world");
	myprint02("hello,vicky");
}

void test02()
{
	MyAdd m1;
	int ret = m1(100, 100);
	cout << "ret=" << ret << endl;
	//������������
	cout << MyAdd()(100, 200) << endl;

}


int main()
{
	test01();
	test02();
	return 0;
}