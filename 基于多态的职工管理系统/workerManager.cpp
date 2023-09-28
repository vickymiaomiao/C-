#define _CRT_SECURE_NO_WARNINGS 1   
#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager() //构造函数的实现
{
	//分三种情况初始化
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EemNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在，但文件为空
	
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_EemNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.文件存在，并且记录数据
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EemNum = num;
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EemNum];
	//将文件中的数据存入数组中
	this->init_Emp();
	for (int i = 0; i < this->m_EemNum; i++)
	{
		cout << this->m_EmpArray[i]->m_Id << "  " << this->m_EmpArray[i]->m_Name
			<< "  " << this->m_EmpArray[i]->m_DeptId << endl;
	}
}

//文件存在并记录数据时的初始化
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();  //关闭文件
}

void WorkerManager::Show_Menu() //展示菜单
{
	cout << "-----------------------------------------" << endl;
	cout << "------欢迎使用职工管理系统！-------------" << endl;
	cout << "--------------0.退出管理系统-------------" << endl;
	cout << "--------------1.增加职工信息-------------" << endl;
	cout << "--------------2.显示职工信息-------------" << endl;
	cout << "--------------3.删除离职员工-------------" << endl;
	cout << "--------------4.修改职工信息-------------" << endl;
	cout << "--------------5.查找职工信息-------------" << endl;
	cout << "--------------6.按照编号排序-------------" << endl;
	cout << "--------------7.清空所有文档-------------" << endl;
	cout << "-----------------------------------------" << endl;
	cout << endl;
}

//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的数量:" << endl;
	int addNum = 0;  //记录用户的输入数量
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		//计算新的添加空间的人数
		int newSize = this->m_EemNum + addNum;
		//开辟新空间
		Worker** newspace = new Worker * [newSize];
		//将原来空间下的数据拷贝到新空间中
		if (this->m_EemNum != NULL)
		{
			for (int i = 0; i < m_EemNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		//开始添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dselect;
			cout << "请输入第" << i + 1 << "个员工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个员工的姓名" << endl;
			cin >> name;
			cout << "请选择该职工的岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dselect;
			Worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的职工指针保存的数组中
			newspace[this->m_EemNum + i] = worker;
		}
		//释放原有的空间,释放数组
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newspace;
		//更新新的职工人数
		this->m_EemNum = newSize;
		//更新职工不为空的标志位
		this->m_FileIsEmpty = false;
		//成功添加后保存到文件中
		this->save();
		cout << "成功添加" <<addNum<<"名新职工" <<endl;
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}
//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	//将每个人的数据写入到文件中
	for (int i = 0; i < this->m_EemNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "  "
			<< this->m_EmpArray[i]->m_Name << "  "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}


void WorkerManager::exitSystem()  //退出程序
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);  //直接退出程序

}
//统计文件中的人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}

WorkerManager::~WorkerManager()  //析构函数的实现
{
	if (this->m_EmpArray != NULL)   //释放堆区数据
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}