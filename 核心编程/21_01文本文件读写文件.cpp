#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/*
* �ļ����ͷ�Ϊ��
* 1.�ı��ļ�����ASCII����ʽ�洢�ڼ������
* 2.�������ļ����Զ����Ƶķ�ʽ�洢�ڼ������
* 
* �����ļ��������ࣺ
* 1.ofstream :д����
* 2.ifstream :������
* 3.fstream :��д����
* 
* �ı��ļ�д�ļ��������£�
* 1.����ͷ�ļ� #include <fstream>
* 2.���������� ofstream ofs;
* 3.���ļ� ofs.open("�ļ�·��","�򿪷�ʽ")��
* 4.ofs<<"д�������"��
* 5.�ر��ļ� ofs.close()
* 
* �ļ��򿪷�ʽ��
* ios::in Ϊ���ļ������ļ�
* ios::out Ϊд�ļ������ļ�
* ios::ate  ��ʼλ�ã��ļ�β��
* ios::app ׷�ӷ�ʽд�ļ�
* ios::trunc ����ļ�������ɾ������
* ios::binary  �����Ʒ�ʽ
* �ļ��򿪷�ʽ�������ʹ�ã�����|������  eg��ios::binary | ios::out
* 
* �ı��ļ����ļ��������£�
* 1.����ͷ�ļ� #include <fstream>
* 2.���������� ifstream ifs;
* 3.���ļ����ж��Ƿ�򿪳ɹ� ifs.open("�ļ�·��","�򿪷�ʽ")��
* 4.���ֶ�ȡ��ʽ
* 5.�ر��ļ� ifs.close()
*/

//д�ļ�
void test210101()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "name : vicky" << endl;
	ofs << "age : 18" << endl;
	ofs.close();
}
//���ļ�
void test02()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) //����ļ��򿪲��ɹ�
	{
		cout << "open file fail" << endl;
		return;
	}
	//�����ݵķ�ʽ
	//1.
	//char buf[1024] = {0};
	//while (ifs>>buf)   //�����ݣ����������ݺ󷵻ؼӵı�־
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