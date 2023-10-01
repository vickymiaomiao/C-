#define _CRT_SECURE_NO_WARNINGS 1   
#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager() //���캯����ʵ��
{
	//�����������ʼ��
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->m_EemNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڣ����ļ�Ϊ��
	
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_EemNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
	this->m_EemNum = num;
	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EemNum];
	//���ļ��е����ݴ���������
	this->init_Emp();
	//���Դ���
	//for (int i = 0; i < this->m_EemNum; i++)
	//{
	//	cout << this->m_EmpArray[i]->m_Id << "  " << this->m_EmpArray[i]->m_Name
	//		<< "  " << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

//�ļ����ڲ���¼����ʱ�ĳ�ʼ��
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
	ifs.close();  //�ر��ļ�
}

void WorkerManager::Show_Menu() //չʾ�˵�
{
	cout << "-----------------------------------------" << endl;
	cout << "------��ӭʹ��ְ������ϵͳ��-------------" << endl;
	cout << "--------------0.�˳�����ϵͳ-------------" << endl;
	cout << "--------------1.����ְ����Ϣ-------------" << endl;
	cout << "--------------2.��ʾְ����Ϣ-------------" << endl;
	cout << "--------------3.ɾ����ְԱ��-------------" << endl;
	cout << "--------------4.�޸�ְ����Ϣ-------------" << endl;
	cout << "--------------5.����ְ����Ϣ-------------" << endl;
	cout << "--------------6.���ձ������-------------" << endl;
	cout << "--------------7.��������ĵ�-------------" << endl;
	cout << "-----------------------------------------" << endl;
	cout << endl;
}

//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������:" << endl;
	int addNum = 0;  //��¼�û�����������
	cin >> addNum;
	if (addNum > 0)
	{
		//���
		//�����µ���ӿռ������
		int newSize = this->m_EemNum + addNum;
		//�����¿ռ�
		Worker** newspace = new Worker * [newSize];
		//��ԭ���ռ��µ����ݿ������¿ռ���
		if (this->m_EemNum != NULL)
		{
			for (int i = 0; i < m_EemNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		//��ʼ���������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dselect;
			cout << "�������" << i + 1 << "��Ա���ı��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��Ա��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//��������ְ��ָ�뱣���������
			newspace[this->m_EemNum + i] = worker;
		}
		//�ͷ�ԭ�еĿռ�,�ͷ�����
		delete[] this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newspace;
		//�����µ�ְ������
		this->m_EemNum = newSize;
		//����ְ����Ϊ�յı�־λ
		this->m_FileIsEmpty = false;
		//�ɹ���Ӻ󱣴浽�ļ���
		this->save();
		cout << "�ɹ����" <<addNum<<"����ְ��" <<endl;
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}
//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->m_EemNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "  "
			<< this->m_EmpArray[i]->m_Name << "  "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}


void WorkerManager::exitSystem()  //�˳�����
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);  //ֱ���˳�����

}
//ͳ���ļ��е�����
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

//��ʾְ����Ϣ
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EemNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}
//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫɾ����ְ����ţ�" << endl;
		int del_id;
		cin >> del_id;
		int ret = this->IsExist(del_id);
		if (ret != -1)  //˵��ְ������
		{
			//����ɾ�����ʾ�������ǰ��
			for (int i = ret; i < this->m_EemNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//��������
			this->m_EemNum--;
			//����ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�ְ��������" << endl;
		}
	}
	system("pause");
	system("cls");

}
//�ж�ְ���Ƿ���ڣ������ڷ��������е�λ�ã������ڷ���-1
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

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸ĵ�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;
		int ret=this->IsExist(id);
		if (ret != -1)
		{
			//���ҵ�ְ��
			delete this->m_EmpArray[ret];

			int newid = 0;
			string newname = "";
			int newdid = 0;
			cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newid;
			cout << "�������µ�����" << endl;
			cin >> newname;
			cout << "������ְ���ĸ�λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//���µ�������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			//�������ݵ��ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}

	}
	//�����������
	system("pause");
	system("cls");

}

//����Ա��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1.����ְ����Ų���" << endl;
		cout << "2.����ְ����������" << endl;
		
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//���ձ�Ų���
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				//���ҳɹ�
				cout << "����ְ������ְ����Ϣ����" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}


		}
		else if (select == 2)
		{
			//������������
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;
			//�����Ƿ�鵽�ı�־
			bool flag = false;//Ĭ��δ�ҵ�
			for (int i = 0; i < this->m_EemNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��" << this->m_EmpArray[i]->m_Id << "��,��Ϣ����" << endl;
					this->m_EmpArray[i]->ShowInfo();
					flag = true;
				}

			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}

		}
		else
		{
			cout << "����ѡ������" << endl;
		}

	}
	system("pause");
	system("cls");
}

//Ա������
void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ:" << endl;
		cout << "1.��ְ�����Ž�������" << endl;
		cout << "2.��ְ�����Ž��н���" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EemNum; i++)
		{
			int minormax = i;//�������ֵ������Сֵ���±�
			for (int j = i+1; j < this->m_EemNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[i]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minormax = j;
					}
				}
				else   //����
				{
					if (this->m_EmpArray[i]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minormax = j;
					}
				}
			}
			
			//�ж�һ��ʼ�϶�����Сֵ�������ֵ�ǲ��Ǽ�������ֵ������Сֵ,������ǣ���������
			if (i != minormax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minormax];
				this->m_EmpArray[minormax] = temp;
			}

		}
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save(); //������浽�ļ���
		this->Show_Emp();   //չʾ���
	}
}

WorkerManager::~WorkerManager()  //����������ʵ��
{
	if (this->m_EmpArray != NULL)   //�ͷŶ�������
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}