#include "manager.h"
#include "globalFile.h"
#include <fstream>

#include <iterator>


//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���
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

//��ʼ������
void Manager::initVector()
{
	//��ȡѧ���ļ���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	vstu.clear();
	vtea.clear();
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vstu.push_back(s);
	}
	//cout << "��ǰѧ��������Ϊ��" << vstu.size() << endl;
	ifs.close();  //ѧ����ʼ��

	//��ȡ��ʦ�ļ���Ϣ
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vtea.push_back(t);
	}
	//cout << "��ǰ��ʦ������Ϊ��" << vtea.size() << endl;
	ifs.close();  //ѧ����ʼ��
}

//����ظ�����
bool Manager::checkRepeat(int id, int type)   //type 1��ʾѧ��  ��type 2��ʾ��ʦ
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

//�˵�����
void Manager::operMenu()
{
	cout << "��ӭ����Ա"<<this->m_Name<<"��¼��" << endl;
	cout << "\t\t|------------------------------------|\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|         1.����˺�                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|         2.�鿴�˺�                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|         3.�鿴����                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|         4.���ԤԼ                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|         0.ע����¼                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|------------------------------------|\n";
	cout << "����������ѡ��" << endl;
}

//����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ����ͣ�" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;
	string filename;
	string tip;
	ofstream ofs;
	int select = 0;
	cin >> select;

	string errortip;  //�ظ�������ʾ

	if (select == 1)
	{
		filename = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errortip = "ѧ���ظ�������������";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errortip = "ְ������ظ�������������";
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
	
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	//д�뵽�ļ�
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();

	this->initVector();  //��ӳɹ�֮���������ó�ʼ�����������Խ�����ӵ������
	//�������У�����ڶ�����ӵ��˺͵�һ����ӵ��˱���ظ�

}

//��ӡѧ��   ȫ�ֺ���
void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}

//��ӡ��ʦ   ȫ�ֺ���
void printTeacher(Teacher& t)
{
	cout << "ְ����ţ�" << t.m_EmpId << " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}


//�鿴�˺�
void Manager::showPerson()
{
	cout << "������鿴�˺ŵ����ͣ�" << endl;
	cout << "1.�鿴ѧ��" << endl;
	cout << "2.�鿴��ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vstu.begin(), vstu.end(), printStudent);
	}
	else
	{
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for_each(vtea.begin(), vtea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//��ӡ����   ȫ�ֺ���
void printcomputerroom(ComputerRoom& c)
{
	cout << "������ţ�" << c.m_ComId << " ���������" <<c.m_MaxNum << endl;
}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for_each(vcom.begin(), vcom.end(), printcomputerroom);
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}
