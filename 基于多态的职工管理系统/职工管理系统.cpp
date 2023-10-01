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
	//测试
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
	//实例化管理者对象
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "请输入请的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:    //退出系统
			wm.exitSystem();
			break;
		case 1:    //增加职工
			wm.Add_Emp();
			break;
		case 2:    //显示职工
			wm.Show_Emp();
			break;
		case 3:     //删除职工
			wm.Del_Emp();
			break;
		case 4:
			wm.Mod_Emp(); //修改职工
			break;
		case 5:      //查找职工
			wm.Find_Emp();
			break;
		case 6:
			break;
		default:
			system("cls");   //清空屏幕
			break;
		}
	}
	
	system("pause");
	return 0;
}
