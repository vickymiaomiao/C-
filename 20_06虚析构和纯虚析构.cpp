#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;

/*
* ��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������
* �����ʽ���������е�����������Ϊ���������ߴ�������
* 
* �������ʹ��������Ĺ��ԣ�
* 1.���Խ������ָ���ͷ��������
* 2.����Ҫ�о���ĺ���ʵ��
* 
* �������ʹ�������������
* ����Ǵ����������������ڳ����࣬�޷�ʵ��������
* 
* �������﷨��
* virtual ~����(){}
* ����������
* virtual ~��������=0��
* ����::����(){}
*/

class Animal
{
public:
	Animal()
	{
		cout << "animal" << endl;
	}
	//���麯��
	virtual void speak() = 0;
	//�������������Խ������ָ���ͷ��������ʱ���ɾ�������
	virtual ~Animal() = 0;  //������������
	//virtual ~Animal()
	//{
	//	cout << "~animal" << endl;
	//}
};

//������������ʵ��
Animal::~Animal()
{
	cout << "animal ��������" << endl;
}


class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "cat" << endl;
		m_Name = new string(name);
	}
	virtual void speak()
	{
		cout << *m_Name<<" cat speak" << endl;
	}
	string* m_Name;

	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "~cat " << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
};

void test01()
{
	Animal* animal = new Cat("vicky");
	animal->speak();
	delete animal;

}


int main()
{
	test01();
	return 0;
}