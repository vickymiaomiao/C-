#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
/*
* �̳��еĶ���ģ��
* �Ӹ���̳й����ĳ�Ա����Щ������������У�
* ���������еķǾ�̬��Ա���ᱻ����̳�����
* ������˽�г�ԱҲ������̳У����Ǳ������������ˣ������޷�����
*/

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class son :public Base
{
public:
	int m_D;
};

//���ÿ�����Ա������ʾ���߲鿴����ģ��
//��ת�̷� F��
// ��ת�ļ�·�� cd ����·��
// �鿴����
// cl /d1 reportSingleClassLayout���� �ļ���
//

void test01()
{
	son s1;
	cout << sizeof(son) << endl; //16���ֽ�
	cout << sizeof(s1) << endl;  //16���ֽ�
}


int main()
{
	test01();
	return 0;
}