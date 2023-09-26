#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/*
* 文件类型分为：
* 1.文本文件：以ASCII码形式存储在计算机中
* 2.二进制文件：以二进制的方式存储在计算机中
* 
* 操作文件的三大类：
* 1.ofstream :写操作
* 2.ifstream :读操作
* 3.fstream :读写操作
* 
* 文本文件写文件步骤如下：
* 1.包含头文件 #include <fstream>
* 2.创建刘对象 ofstream ofs;
* 3.打开文件 ofs.open("文件路径","打开方式")；
* 4.ofs<<"写入的数据"；
* 5.关闭文件 ofs.close()
* 
* 文件打开方式：
* ios::in 为读文件而打开文件
* ios::out 为写文件而打开文件
* ios::ate  初始位置：文件尾部
* ios::app 追加方式写文件
* ios::trunc 如果文件存在先删除创建
* ios::binary  二进制方式
* 文件打开方式可以配合使用，利用|操作符  eg：ios::binary | ios::out
* 
* 文本文件读文件步骤如下：
* 1.包含头文件 #include <fstream>
* 2.创建刘对象 ifstream ifs;
* 3.打开文件并判断是否打开成功 ifs.open("文件路径","打开方式")；
* 4.四种读取方式
* 5.关闭文件 ifs.close()
*/

//写文件
void test210101()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "name : vicky" << endl;
	ofs << "age : 18" << endl;
	ofs.close();
}
//读文件
void test02()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) //如果文件打开不成功
	{
		cout << "open file fail" << endl;
		return;
	}
	//读数据的方式
	//1.
	//char buf[1024] = {0};
	//while (ifs>>buf)   //读数据，读不到数据后返回加的标志
	//{
	//	cout << buf << endl;
	//}
	
	//2.
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}
	
	//3.
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}

	//4.
	char c;
	while ((c = ifs.get()) != EOF)  //EOF end of file
	{
		cout << c;
	}
	ifs.close();


}


int main2101()
{
	test210101();
	test02();
	return 0;
}