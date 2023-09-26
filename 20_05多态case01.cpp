#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;
/*
* ���ö�̬����ʵ�ֱ��������ṩ����������Ʒ���࣬�ṩ�����������ȺͲ�Ҷ
*/
class AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSomething() = 0;
	//������Ʒ
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//��������
class Coffee :public AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil()
	{
		cout << "boil water" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "brew coffee" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "pour in cup" << endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout << "put suger and milk" << endl;
	}
};

//������Ҷ
class Tea :public AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil()
	{
		cout << "boil water" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "brew tea" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "pour in cup" << endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout << "put suger and fruit" << endl;
	}
};
//����
void doWork(AbstractDrinking *abs)
{
	abs->makeDrink();     
	delete abs;  //�ͷŶ������ݣ������ڴ�й¶
}

void test01()
{
	//��������
	doWork(new Coffee);   //����ָ��ָ���������һ���ӿ��ж�����̬
	cout << "------------------" << endl;
	doWork(new Tea);
}

int main()
{
	test01();
	return 0;
}