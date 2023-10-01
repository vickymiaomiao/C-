#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* �ֱ�����ͨд���Ͷ�̬���������ʵ��������������������ļ�������
* ��̬���ŵ㣺
* 1.������֯�ṹ����
* 2.�ɶ���ǿ
* 3.����ǰ�ںͺ���ά��
* 
* C++�����ᳫ���ö�̬��Ƴ���ܹ�����Ϊ��̬�е�ܶ�
*/

//��ͨд��
class Calaulator
{
public:
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		//�������չ�µĲ�������Ҫ�޸��µ�Դ��
		//����ʵ�Ŀ����У��ᳫ����ԭ��
		//����ԭ�򣺶���չ���п��ţ����޸Ľ��йر�

	}
	int m_Num1;   //������1
	int m_Num2;    //������2
};

void test01()
{
	Calaulator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << " + " << c.m_Num2 <<" = " << c.getResult("+") << endl;
	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}


//���ö�̬ʵ�ּ�����
//ʵ�ּ������Ļ���
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}

	int m_Num1;
	int m_Num2;
};

//�ӷ�����������
class AddCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_Num1 + m_Num2;
	}
};

//��������������
class SubCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_Num1 - m_Num2;
	}
};
//�˷�
class MulCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_Num1 * m_Num2;
	}
};

void test02()
{
	//��̬ʹ������
	//����ָ���������ָ���������
	
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;

	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
	//�������������������ǵ�����
	delete abc;   //���ٺ�ָ�뻹��
	//��������
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
	//�˷�����
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
}

int main()
{
	test01();
	test02();
	return 0;
}