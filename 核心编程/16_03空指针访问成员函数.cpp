#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* C++�еĿ�ָ��Ҳ�������γ�Ա����������Ҳ��ע���Ƿ��õ�thisָ��
* ����õ�this ָ�룬��Ҫ�����жϱ�֤����Ľ�׳��
*/

class person
{
public:
	void showClassName()
	{
		cout << "this is person class" << endl;
	}
	void showPersonAge()
	{
		//����ԭ���Ǵ����ָ��Ϊ�գ������޷����ʵ�����
		if (this == NULL)
		{
			return;
		}
		cout << "age=" << m_Age << endl;    //����ǰ��Ĭ��this->m_Age
	}

	int m_Age;
};

void test01()
{
	person* p = NULL;
	p->showClassName();
	//p->showPersonAge();

}

int main()
{
	test01();
	return 0;
}