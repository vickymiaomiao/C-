#pragma once   //��ֹͷ�ļ��ظ�����
#include <iostream>   //�������������ͷ�ļ�
using namespace std;   //ʹ�ñ�׼�������ռ�
#include "worker.h"
#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager(); //���캯��

	void Show_Menu();  //չʾ�˵�

	void exitSystem(); //�˳�����

	//��¼ְ������
	int m_EemNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();
	//�����ļ�
	void save();
	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ��е�����
	int get_EmpNum();

	//�ļ����Ѵ���Ա���ĳ�ʼ��
	void init_Emp();

	//��ʾְ����Ϣ
	void Show_Emp();

	//ɾ��ְ����Ϣ
	void Del_Emp();

	//�ж�ְ���Ƿ����
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����Ա��
	void Find_Emp();

	~WorkerManager();  //��������


};



