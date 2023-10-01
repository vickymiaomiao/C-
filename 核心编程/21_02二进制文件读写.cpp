#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
* �����Ʒ�ʽд�ļ���Ҫ������������ó�Ա����write
* ����ԭ�ͣ�ostream& write(const char * buffer,int len);
* �������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䣬len�Ƕ�д���ֽ���
* 
* ���ļ�
* ����ԭ�ͣ� istream& read(char *buffer,int len)
*/

//������д�ļ�
class Person
{
public:
	char m_Name[64];
	int m_Age;
};

void test01()
{
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);
	Person p = { "vicky",18 };
	ofs.write((const char*)&p, sizeof(Person));
	ofs.close();
}

//���ļ�

void test02()
{
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "open fail" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << p.m_Name << "  " << p.m_Age << endl;
	ifs.close();

}


int main()
{
	test01();
	test02();
	return 0;
}