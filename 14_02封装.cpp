#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

//����Ȩ��
//1.public     ��Ա�����ڿ��Է���,������Է���
//2.protected  ���ڿ��Է��ʣ����ⲻ���Է���  ����Ҳ���Է��ʸ����б���������
//3.private    ���ڿ��Է��ʣ����ⲻ���Է���  ���Ӳ����Է��ʸ��׵�˽������


class Person
{
	//����Ȩ�޵ĳ�Ա
public:
	string m_name;
	//����Ȩ��
protected:
	string m_car;
	//˽��Ȩ��
private:
	int m_pwd;

public:
	void func140201()
	{
		m_name = "vicky";
		m_car = "BYD";
		m_pwd = 12345;
		cout << m_name << "  " << m_car << "  " << m_pwd << endl;
	}
};

//struct��class����������Ĭ�ϵķ���Ȩ�޲�ͬ��structĬ��Ȩ��Ϊ������classĬ��Ȩ��Ϊ˽��
class C1
{
	int m_A; //Ĭ��Ȩ��Ϊ˽��
};
struct C2
{
	int m_b;//Ĭ���ǹ���Ȩ��
};



int main1402()
{
	C1 c1;
	//c1.m_A = 100;˽�б����������Է���
	C2 c2;
	c2.m_b = 100;  //����Ȩ�޿��Է���
	Person p1;
	p1.m_name = "andy";
	//p1.m_car = "LX";  ����Ȩ�����������ⲻ���Է���
	//p1.m_pwd=12;˽��Ȩ�޵ĳ�Ա����Ҳ�����Է���
	p1.func140201();
	return 0;
}