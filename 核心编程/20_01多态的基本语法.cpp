#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;

/*
* ��̬��C++���������������֮һ
* ��̬��Ϊ����
* 1.��̬��̬���������غ�������������ھ�̬��̬�����ú�����
* 2.��̬��̬����������麯��ʵ������ʱ��̬
* 
* ��̬��̬�Ͷ�̬��̬����
* ��̬��̬�ĺ�����ַ���-����׶�ȷ��������ַ
* ��̬��̬�ĺ�����ַ���-���н׶�ȷ��������ַ
* 
* ��̬��̬��������
* 1.�м̳й�ϵ
* 2.����Ҫ��д������麯��
* 
* ��д����������ֵ���� ������ �����б� ��ȫ����
* 
* ��̬��̬��ʹ�ã�
* �����ָ��������� ָ���������
*/

class Animal
{
public:
	//�麯����ʵ�ֵ�ַ���
	virtual void speak()
	{
		cout << "Animal speak" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "cat speak" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "dog speak" << endl;
	}
};
//ִ��˵���ĺ���
//��ַ��󶨣��ڱ���׶�ȷ���˺����ĵ�ַ
//�����ִ����è˵������ô��������ĵ�ַ������ǰ�󶨣���Ҫ��ַ���
void doSpeak(Animal& animal) // Animal& animal = cat ���������ָ���������
{
	animal.speak();
}

void test01()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}


int main()
{
	test01();
	return 0;
}

