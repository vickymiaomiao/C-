#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;
/*
* �̳��еĹ������������
* ����̳и���󣬵������������Ҳ����ø���Ĺ��캯��
* �ȹ��츸���ٹ������࣬������˳���빹���˳���෴
*/

class Base
{
public:
	Base()
	{
		cout << "Base�Ĺ��캯��" << endl;
	}

	~Base()
	{
		cout << "Base����������" << endl;
	}
};

class son:public Base
{
public:
	son()
	{
		cout << "son���캯��" << endl;
	}
	~son()
	{
		cout << "son��������" << endl;
	}
};

void test01()
{
	//son s1;
	//Base b;
	son s;
}

int main()
{
	test01();
	return 0;
}
