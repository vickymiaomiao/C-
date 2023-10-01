#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

/*
* �̳еĺô��������ظ��Ĵ���
* �﷨��class ���ࣺ�̳з�ʽ ����
* ����ҲΪ������
* ����Ҳ��Ϊ����
* 
* ������ĳ�Ա���������󲿷�
* һ���Ǵӻ���̳й����ģ�һ�����Լ����ӵĳ�Ա
* �ӻ���̳й����ı����乲�ԣ��������ĳ�Ա�����������
*/
//����ҳ�����
class BasePage
{
public:
	void header()
	{
		cout << "header" << endl;
	}
	void footer()
	{
		cout << "footer" << endl;
	}
	void left()
	{
		cout << "left" << endl;
	}
};

//javaҳ��
class Java :public BasePage
{
public:
	void content()
	{
		cout << "Java" << endl;
	}
};

//pythonҳ��
class Python :public BasePage
{
public:
	void content()
	{
		cout << "python" << endl;
	}
};

class Cpp :public BasePage
{
public:
	void content()
	{
		cout << "Cpp" << endl;
	}
};

void test01()
{
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "------------------------" << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "------------------------" << endl;
	Cpp cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
	cout << "------------------------" << endl;

}

int main()
{
	test01();
	return 0;
}