#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <string>
using namespace std;

//�ṹ�嶨��
struct student
{
	string name;
	int age;
	int score;
} s3;

//�ṹ��Ƕ��
struct teacher
{
	int id;
	string name;
	int age;
	struct student stu;
};

//��ӡѧ����Ϣ�ĺ���ֵ����
void printstudent1(struct student s)
{
	cout << "�Ӻ�����ֵ����" << endl;
	cout << "������" << s.name << " ���䣺" << s.age << " �ɼ���" << s.score << endl;
}
//��ַ����
void printstudent2(struct student *p)
{
	cout << "�Ӻ����е�ַ����" << endl;
	cout << "������" << p->name << " ���䣺" << p->age << " �ɼ���" << p->score << endl;
}

int main09()
{
	//struct student s1
	struct student s1;  //��������ʱstruct�ؼ��ֿ���ʡ�ԣ�����ʱ������ʡ��
	s1.name = "����";
	s1.age = 10;
	s1.score = 100;
	cout << "������" << s1.name << " ���䣺" << s1.age << " �ɼ���" << s1.score << endl;
	struct student s2 = {"����",14,60};
	cout << "������" << s2.name << " ���䣺" << s2.age << " �ɼ���" << s2.score << endl;
	s3.name = "����";
	s3.age = 10;
	s3.score = 90;
	cout << "������" << s3.name << " ���䣺" << s3.age << " �ɼ���" << s3.score << endl;
	cout << endl;

	//�ṹ������
	struct student s4[3] =
	{
		{"����",14,60},
		{"����", 10, 100},
		{"����",13,99},
	};
	s4[2].name = "С��";
	s4[2].age = 80;
	s4[2].score = 60;
	for (int i = 0; i < 3; i++)
	{
		cout << "������" << s4[i].name << " ���䣺" << s4[i].age << " �ɼ���" << s4[i].score << endl;
	}

	//�ṹ��ָ�룬ͨ��ָ����ʽṹ���Ա�����ò�����->����ͨ���ṹ��ָ����ʽṹ������
	struct student s5 = { "vicky",18,100 };
	struct student * ps = &s5;   //�ṹ��ָ��
	//���ʱ����е�����
	cout <<"name:" << ps->name << endl;
	cout << "age:" << ps->age << endl;
	cout << "score:"<<ps->score << endl;

	//Ƕ�׽ṹ��
	struct teacher t;
	t.id = 10000;
	t.name = "mike";
	t.age = 50;
	t.stu.name = "andy";
	t.stu.age = 10;
	t.stu.score = 100;

	//�ṹ���������Ĳ���
	//case��ѧ�����뵽һ�������У���ӡѧ�����ϵ���Ϣ
	struct student s6 = { "mike",10,70 };
	printstudent1(s6);
	printstudent2(&s6);

	//�ṹ���е�const ,��const����ֹ�����
	//����const֮��ֻ�ܶ������ܽ����޸�
	

	return 0;
}