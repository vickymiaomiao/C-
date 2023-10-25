#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerRoom.h"

class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student> vstu;

	//��ʦ����
	vector<Teacher> vtea;

	//���Ի�������
	vector<ComputerRoom> vcom;

	//����ظ�����
	bool checkRepeat(int id, int type);

	////��ӡѧ��
	//void printStudent(Student& s);

	////��ӡ��ʦ
	//void printTeacher(Teacher& t);


};