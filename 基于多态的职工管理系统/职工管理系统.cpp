#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;


int main()
{
	//����
	//Worker* worker = NULL;
	//worker = new Employee(1, "vicky", 1);
	//worker->ShowInfo();
	//delete worker;
	//Worker* manager = NULL;
	//manager = new Manager(2, "andy", 2);
	//manager->ShowInfo();
	//delete manager;
	//Worker* boss = NULL;
	//boss = new Boss(3, "lucy", 3);
	//boss->ShowInfo();
	//delete boss;
	//ʵ���������߶���
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:    //�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1:    //����ְ��
			wm.Add_Emp();
			break;
		case 2:    //��ʾְ��
			break;
		case 3:     //ɾ��ְ��
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			system("cls");   //�����Ļ
			break;
		}
	}
	
	system("pause");
	return 0;
}
