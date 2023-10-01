#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

//�����������

class Cube
{
public:
	//��Ϊ
	//���ó����
	// ��ȡ�����
	void setm_L(int l)
	{
		m_L = l;
	}
	int getm_L()
	{
		return m_L;
	}
	void setm_W(int w)
	{
		m_W = w;
	}
	int getm_W()
	{
		return m_W;
	}
	void setm_H(int h)
	{
		m_H = h;
	}
	int getm_H()
	{
		return m_H;
	}
	
	//��ȡ���������
	int calculateS()
	{
		return 2 * m_L * m_H + 2 * m_L * m_W + 2 * m_W * m_H;
	}
	//��ȡ���������
	int calculateV()
	{
		return m_L * m_H * m_W;
	}
	//���ó�Ա�����ж������������Ƿ����,����������
	bool isSameByClass(Cube &c)
	{
		if (getm_L() == c.getm_L() &&getm_H() == c.getm_H() && getm_W() == c.getm_W())
		{
			return true;
		}
		return false;

	}
	

private:
	int m_L;
	int m_H;
	int m_W;
};


//����ȫ�ֺ����ж������������Ƿ����
bool isSame(Cube& c1, Cube& c2)
{
	if (c1.getm_L() == c2.getm_L() && c1.getm_H() == c2.getm_H() && c1.getm_W() == c2.getm_W())
	{
		return true;
	}
	return false;
}



int main1404()
{
	Cube c1;
	c1.setm_L(10);
	c1.setm_W(10);
	c1.setm_H(10);
	cout << "�����" << c1.calculateS()<< endl;
	cout << "�����" << c1.calculateV() << endl;
	
	//�����ڶ���������
	Cube c2;
	c2.setm_L(10);
	c2.setm_W(10);
	c2.setm_H(1);
	//����ȫ�ֺ����жϽ��
	bool ret = isSame(c1, c2);
	if (ret)
	{
		cout << "ȫ�ֺ����ж��������������" << endl;
	}
	else 
	{
		cout << "ȫ�ֺ����жϲ����" << endl;
	}
	//���ó�Ա�����ж�
	ret = c1.isSameByClass(c2);
	if (ret)
	{
		cout << "��Ա�����ж��������������" << endl;
	}
	else
	{
		cout << "��Ա�����жϲ����" << endl;
	}

	return 0;
}