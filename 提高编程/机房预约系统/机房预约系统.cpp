#include <iostream>
#include <string>
using namespace std;

#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include <fstream>

//����Ա�˵�
void managerMenu(Identity* &manager)
{
	while (true)
	{
		//����Ա�˵�
		manager->operMenu();

		Manager* man = (Manager*)manager;
		
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;

		}
	}
}

////ѧ���˵�
void studentMenu(Identity*& student)
{
	while (true)
	{
		//����Ա�˵�
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			cout << "����ԤԼ" << endl;
			stu->applyOrder();
		}
		else if (select == 2)
		{
			cout << "�鿴ԤԼ" << endl;
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			cout << "�鿴����ԤԼ" << endl;
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;

		}
	}
}


//ȫ�ֺ���ʵ�ֵ�¼
void LoginIn(string filename, int type)
{
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);
	//�ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	if (type == 1)//ѧ����¼
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)  //��ʦ��¼
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "����������:" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ����¼��֤
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ������Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤int fid;
		int empfid;
		string fname;
		string fpwd;
		while (ifs >> empfid && ifs >> fname && ifs >> fpwd)
		{
			if (empfid == id && fname == name && fpwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ����Ӳ˵�
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��½��֤
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if ( fname == name && fpwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager( name, pwd);
				//�������Ա����Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;

}



int main()
{
	int select = 0;
	while (true)
	{
		cout << "------------��ӭ��������ԤԼϵͳ---------------" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t|------------------------------------|\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|         1.ѧ������                 |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|         2.��    ʦ                 |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|         3.�� �� Ա                 |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|         0.��    ��                 |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|------------------------------------|\n";

		cout << "��������ѡ��:";
		cin >> select;    //�����û�ѡ��
		switch (select)
		{
		case 1: //ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2: //��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:   //����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:   //�˳�
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
		
	}


	system("pause");
	return 0;
}