#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
* 二进制方式写文件主要利用刘对象调用成员函数write
* 函数原型：ostream& write(const char * buffer,int len);
* 参数解释：字符指针buffer指向内存中一段存储空间，len是读写的字节数
*/

//二进制写文件
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

//读文件

int main()
{
	test01();
	return 0;
}