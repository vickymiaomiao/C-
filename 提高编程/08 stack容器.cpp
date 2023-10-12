#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <stack>
using namespace std;

/*
* stack��һ���Ƚ���������ݽṹ��ֻ��һ������
* ջ��ֻ�ж��˵�Ԫ�ؿ��Ա����ʹ�ã�ջ�������б�����Ϊ
* ��ջ push
* ��ջ pop
* top()  ���ض���Ԫ��
* empty size
*/

void test01()
{
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	//�鿴ջ�е�����
	while (!s.empty())
	{
		//�鿴ջ��Ԫ��
		cout<<s.top()<<" ";
		//��ջ
		s.pop();
	}
	cout << endl;
	cout << "stack size: " << s.size() << endl;
}

int main()
{
	test01();
	return 0;
}