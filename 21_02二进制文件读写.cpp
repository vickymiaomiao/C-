#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
* �����Ʒ�ʽд�ļ���Ҫ������������ó�Ա����write
* ����ԭ�ͣ�ostream& write(const char * buffer,int len);
* �������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䣬len�Ƕ�д���ֽ���
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

int main()
{
	test01();
	return 0;
}