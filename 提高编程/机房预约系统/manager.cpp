#include "manager.h"
#include "globalFile.h"
#include <fstream>

#include <iterator>


//默认构造
Manager::Manager()
{

}

//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vcom.push_back(c);
	}
	ifs.close();
}

//初始化容器
void Manager::initVector()
{
	//读取学生文件信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	vstu.clear();
	vtea.clear();
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vstu.push_back(s);
	}
	//cout << "当前学生的数量为：" << vstu.size() << endl;
	ifs.close();  //学生初始化

	//读取老师文件信息
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vtea.push_back(t);
	}
	//cout << "当前教师的数量为：" << vtea.size() << endl;
	ifs.close();  //学生初始化
}

//检测重复函数
bool Manager::checkRepeat(int id, int type)   //type 1表示学生  ，type 2表示老师
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vstu.begin(); it != vstu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vtea.begin(); it != vtea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}

//菜单界面
void Manager::operMenu()
{
	cout << "欢迎管理员"<<this->m_Name<<"登录！" << endl;
	cout << "\t\t|------------------------------------|\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|         1.添加账号                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|         2.查看账号                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|         3.查看机房                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|         4.清空预约                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|         0.注销登录                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|------------------------------------|\n";
	cout << "请输入您的选择：" << endl;
}

//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型：" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;
	string filename;
	string tip;
	ofstream ofs;
	int select = 0;
	cin >> select;

	string errortip;  //重复错误提示

	if (select == 1)
	{
		filename = STUDENT_FILE;
		tip = "请输入学号：";
		errortip = "学号重复，请重新输入";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "请输入职工编号：";
		errortip = "职工编号重复，请重新输入";
	}
	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}
	}
	
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	//写入到文件
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();

	this->initVector();  //添加成功之后立即调用初始化容器，可以将新添加的人添加
	//到容器中，避免第二次添加的人和第一次添加的人编号重复

}

//打印学生   全局函数
void printStudent(Student& s)
{
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}

//打印教师   全局函数
void printTeacher(Teacher& t)
{
	cout << "职工编号：" << t.m_EmpId << " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd << endl;
}


//查看账号
void Manager::showPerson()
{
	cout << "请输入查看账号的类型：" << endl;
	cout << "1.查看学生" << endl;
	cout << "2.查看老师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(vstu.begin(), vstu.end(), printStudent);
	}
	else
	{
		cout << "所有教师信息如下：" << endl;
		for_each(vtea.begin(), vtea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//打印机房   全局函数
void printcomputerroom(ComputerRoom& c)
{
	cout << "机房编号：" << c.m_ComId << " 最大容量：" <<c.m_MaxNum << endl;
}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for_each(vcom.begin(), vcom.end(), printcomputerroom);
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}
