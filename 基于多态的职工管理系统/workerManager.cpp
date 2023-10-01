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
	//cout << "职工人数为：" << num << endl;
	this->m_EemNum = num;
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EemNum];
	//将文件中的数据存入数组中
	this->init_Emp();
	//测试代码
	//for (int i = 0; i < this->m_EemNum; i++)
	//{
	//	cout << this->m_EmpArray[i]->m_Id << "  " << this->m_EmpArray[i]->m_Name
	//		<< "  " << this->m_EmpArray[i]->m_DeptId << endl;
	//}
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

//显示职工信息
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EemNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}
//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空" << endl;
	}
	else
	{
		cout << "请输入需要删除的职工编号：" << endl;
		int del_id;
		cin >> del_id;
		int ret = this->IsExist(del_id);
		if (ret != -1)  //说明职工存在
		{
			//数组删除本质就是数据前移
			for (int i = ret; i < this->m_EemNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新人数
			this->m_EemNum--;
			//数据同步更新到文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，职工不存在" << endl;
		}
	}
	system("pause");
	system("cls");

}
//判断职工是否存在，若存在返回数组中的位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EemNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空" << endl;
	}
	else
	{
		cout << "请输入修改的职工的编号：" << endl;
		int id;
		cin >> id;
		int ret=this->IsExist(id);
		if (ret != -1)
		{
			//查找到职工
			delete this->m_EmpArray[ret];

			int newid = 0;
			string newname = "";
			int newdid = 0;
			cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newid;
			cout << "请输入新的姓名" << endl;
			cin >> newname;
			cout << "请输入职工的岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> newdid;
			Worker* worker = NULL;
			switch (newdid)
			{
			case 1:
				worker = new Employee(newid, newname, 1);
				break;
			case 2:
				worker = new Manager(newid, newname, 2);
				break;
			case 3:
				worker = new Boss(newid,newname, 3);
				break;
			default:
				break;
			}
			//更新到数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << endl;
			//保存数据到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}

	}
	//按任意键清屏
	system("pause");
	system("cls");

}

//查找员工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1.按照职工编号查找" << endl;
		cout << "2.按照职工姓名查找" << endl;
		
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//按照编号查找
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				//查找成功
				cout << "查找职工，该职工信息如下" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}


		}
		else if (select == 2)
		{
			//按照兴姓名查
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;
			//加入是否查到的标志
			bool flag = false;//默认未找到
			for (int i = 0; i < this->m_EemNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为：" << this->m_EmpArray[i]->m_Id << "号,信息如下" << endl;
					this->m_EmpArray[i]->ShowInfo();
					flag = true;
				}

			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}

		}
		else
		{
			cout << "输入选项有误" << endl;
		}

	}
	system("pause");
	system("cls");
}

//员工排序
void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式:" << endl;
		cout << "1.按职工工号进行升序" << endl;
		cout << "2.按职工工号进行降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EemNum; i++)
		{
			int minormax = i;//声明最大值或者最小值的下标
			for (int j = i+1; j < this->m_EemNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[i]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minormax = j;
					}
				}
				else   //降序
				{
					if (this->m_EmpArray[i]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minormax = j;
					}
				}
			}
			
			//判断一开始认定的最小值或者最大值是不是计算的最大值或者最小值,如果不是，交换数据
			if (i != minormax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minormax];
				this->m_EmpArray[minormax] = temp;
			}

		}
		cout << "排序成功！排序后的结果为：" << endl;
		this->save(); //结果保存到文件中
		this->Show_Emp();   //展示结果
	}
}

WorkerManager::~WorkerManager()  //析构函数的实现
{
	if (this->m_EmpArray != NULL)   //释放堆区数据
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}