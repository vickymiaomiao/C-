#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <string>
using namespace std;
/*
* ����������̳�ͬһ������
* ����ĳ����ͬʱ�̳�������������
* ���ּ̳б���Ϊ���μ̳У�������ʯ�̳�
*/

//������
class Animal
{
public:
	int m_Age;
};

//������̳п��Խ�����μ̳е�����
// �̳�֮ǰ���Ϲؼ���virtual ��Ϊ��̳�
// Animal���Ϊ�����,��Ӹùؼ��ֺ�����ֻ�̳�һ��
// vbptr ��̳�ָ��  ָ��vbtable
// v-virtual
// b-base
// ptr-pointer
// ��ָ��ͬһ������
//����
class Sheep :virtual public Animal
{};

//����
class Tuo :virtual public Animal
{};

//������
class SheepTuo :public Sheep, public Tuo
{};

void test01()
{
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 20;
	//�����μ̳У���������ӵ����ͬ���ݣ���Ҫ������������������
	cout << "Sheep::m_Age=" << st.Sheep::m_Age << endl;
	cout << "Tuo::m_Age=" << st.Tuo::m_Age << endl;
	cout << "st.m_Age=" << st.m_Age << endl;
	//

}


int main()
{
	test01();
	return 0;
}