#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;

#define max 1000
//ͨѶ¼����
//�����ϵ��
//��ʾ��ϵ��
//ɾ�������ҡ��޸ġ���ա��˳�ͨѶ¼

void showMenu()
{
	cout << " ************************ " << endl;
	cout << " ***** 1.�����ϵ�� ***** " << endl;
	cout << " ***** 2.��ʾ��ϵ�� ***** " << endl;
	cout << " ***** 3.ɾ����ϵ�� ***** " << endl;
	cout << " ***** 4.������ϵ�� ***** " << endl;
	cout << " ***** 5.�޸���ϵ�� ***** " << endl;
	cout << " ***** 6.�����ϵ�� ***** " << endl;
	cout << " ***** 0.�˳�ͨѶ¼ ***** " << endl;
	cout << " ************************ " << endl;
}

//�����ϵ��
struct person 
{
	string m_name;
	int m_sex;  //1-�У�2-Ů
	int m_age;
	string m_phone;
	string m_addr;
};

struct addressbooks
{
	struct person personarry[max];
	int m_size;
};

//���
void addperson(addressbooks * abs)
{
//	//�ж�ͨѶ¼����
	if (abs->m_size == max)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
//		//��Ӿ�������
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarry[abs->m_size].m_name = name;
//		//�Ա�,����������1��2�����˳�ѭ��
		int sex=0;
		cout << "�������Ա�1��ʾ�У�2��ʾŮ��" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarry[abs->m_size].m_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
//		
		//����
		int age=0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personarry[abs->m_size].m_age = age;
		
		string phone;
		cout << "��������ϵ�˵绰��" << endl;
		cin >> phone;
		abs->personarry[abs->m_size].m_phone = phone;
		string addr;
		cout << "�������ͥסַ��" << endl;
		cin >> addr;
		abs->personarry[abs->m_size].m_addr = addr;
        //����ͨѶ¼����
		abs->m_size++;
		cout << "��ϵ����ӳɹ�" << endl;

		//����
		system("pause");
		system("cls");
	}
//
}

//��ʾ��ϵ��
void showperson(addressbooks * abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ0" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->personarry[i].m_name << "\t";
			cout << "�Ա�" << (abs->personarry[i].m_sex ==1?"��":"Ů" )<< "\t";
			cout << "���䣺" << abs->personarry[i].m_age << "\t";
			cout << "�绰��" << abs->personarry[i].m_phone<< "\t";
			cout << "��ַ��" << abs->personarry[i].m_addr << endl;
			
		}
	}

	system("pause");
	system("cls");
	
}

//�������������ϵ���Ƿ����,������ڷ�����ϵ�˵�λ�ã������ڷ���-1
int isexist(addressbooks* abs, string name)  //����һ��ʾ����ͨѶ¼����������ʾ������Ҫ��������
{
	for(int i=0;i<abs->m_size;i++)
	{
		if (abs->personarry->m_name == name)
		{
			return i;
		 }
	 }
	return -1;  //���������û�ҵ�������-1
}

//ɾ����ϵ��
void deleteperson(addressbooks* abs)
{
	cout << "������ɾ����ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)//�ҵ����ˣ�����ɾ��
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			//����ǰ�Ʋ���
			abs->personarry[i] = abs->personarry[i + 1];
		}
		abs->m_size--;//����ͨѶ¼�е���Ա��
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
	

}

//����ָ����ϵ����Ϣ
void findperson(addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж����Ƿ����
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personarry[ret].m_name << "\t";
		cout << "�Ա�" << (abs->personarry[ret].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personarry[ret].m_age << "\t";
		cout << "�绰��" << abs->personarry[ret].m_phone << "\t";
		cout << "��ַ��" << abs->personarry[ret].m_addr << endl;
	}
	else
	{
		cout << "��ϵ�˲�����" << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyperson(addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "�ҵ�����" << endl;
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarry[ret].m_name = name;
		//		//�Ա�,����������1��2�����˳�ѭ��
		int sex = 0;
		cout << "�������Ա�1��ʾ�У�2��ʾŮ��" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarry[ret].m_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//		
				//����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personarry[ret].m_age = age;

		string phone;
		cout << "��������ϵ�˵绰��" << endl;
		cin >> phone;
		abs->personarry[ret].m_phone = phone;
		string addr;
		cout << "�������ͥסַ��" << endl;
		cin >> addr;
		abs->personarry[ret].m_addr = addr;
		//����ͨѶ¼����
		cout << "��ϵ���޸ĳɹ�" << endl;

		//����
		system("pause");
		system("cls");

	}
	else
	{
		cout << "��ϵ�˲�����" << endl;
	}
	system("pause");
	system("cls");
}

//�����ϵ��
void cleanperson(addressbooks* abs)
{
	//�ж��Ƿ����
	cout << "��ȷ���Ƿ������գ���ѡ��yes,��ѡ��no" << endl;
	string choice;
	cin >> choice;
	if (choice == "yes")
	{
		abs->m_size = 0;//����ǰ��¼������size�޸�Ϊ0
		cout << "ͨѶ¼�����" << endl;
	}
	else
	{
		cout << "���������" << endl;
	}
	system("pause");
	system("cls");

}

int main()
{
	//����ͨѶ¼
	addressbooks abs;
	//��ʼ��ͨѶ�е���Ա����
	abs.m_size = 0;

	int select = 0;//�û�����������

	while (true)
	{
		//�˵���ʾ
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			addperson(&abs);  //���õ�ַ���ݣ������޸�ʵ��
			break;
		case 2://��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3://ɾ����ϵ��
		//{
		//	cout << "������ɾ����ϵ��������" << endl;
		//	string name;
		//	cin >> name;
		//	if (isexist(&abs, name) == -1)
		//	{
		//		cout << "���޴���" << endl;
		//	}
		//	else
		//	{
		//		cout << "�ҵ�����" << endl;
		//	}
		//}
			deleteperson(&abs);
			break;
		case 4://������ϵ��
			findperson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyperson(&abs);
			break;
		case 6://�����ϵ��
			cleanperson(&abs);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	
	system("pause");
	return 0;
}