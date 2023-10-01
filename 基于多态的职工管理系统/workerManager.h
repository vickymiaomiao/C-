#pragma once   //防止头文件重复包含
#include <iostream>   //包含输入输出流头文件
using namespace std;   //使用标准的命名空间
#include "worker.h"
#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager(); //构造函数

	void Show_Menu();  //展示菜单

	void exitSystem(); //退出程序

	//记录职工人数
	int m_EemNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();
	//保存文件
	void save();
	//标志文件是否为空
	bool m_FileIsEmpty;

	//统计文件中的人数
	int get_EmpNum();

	//文件中已存在员工的初始化
	void init_Emp();

	//显示职工信息
	void Show_Emp();

	//删除职工信息
	void Del_Emp();

	//判断职工是否存在
	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找员工
	void Find_Emp();

	~WorkerManager();  //析构函数


};



