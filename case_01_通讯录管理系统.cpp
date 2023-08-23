#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;

#define max 1000
//通讯录管理
//添加联系人
//显示联系人
//删除、查找、修改、清空、退出通讯录

void showMenu()
{
	cout << " ************************ " << endl;
	cout << " ***** 1.添加联系人 ***** " << endl;
	cout << " ***** 2.显示联系人 ***** " << endl;
	cout << " ***** 3.删除联系人 ***** " << endl;
	cout << " ***** 4.查找联系人 ***** " << endl;
	cout << " ***** 5.修改联系人 ***** " << endl;
	cout << " ***** 6.清空联系人 ***** " << endl;
	cout << " ***** 0.退出通讯录 ***** " << endl;
	cout << " ************************ " << endl;
}

//添加联系人
struct person 
{
	string m_name;
	int m_sex;  //1-男，2-女
	int m_age;
	string m_phone;
	string m_addr;
};

struct addressbooks
{
	struct person personarry[max];
	int m_size;
};

//添加
void addperson(addressbooks * abs)
{
//	//判断通讯录人数
	if (abs->m_size == max)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
//		//添加具体人数
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarry[abs->m_size].m_name = name;
//		//性别,如果输入的是1或2可以退出循环
		int sex=0;
		cout << "请输入性别，1表示男，2表示女：" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarry[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
//		
		//年龄
		int age=0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personarry[abs->m_size].m_age = age;
		
		string phone;
		cout << "请输入联系人电话：" << endl;
		cin >> phone;
		abs->personarry[abs->m_size].m_phone = phone;
		string addr;
		cout << "请输入家庭住址：" << endl;
		cin >> addr;
		abs->personarry[abs->m_size].m_addr = addr;
        //更新通讯录人数
		abs->m_size++;
		cout << "联系人添加成功" << endl;

		//清屏
		system("pause");
		system("cls");
	}
//
}

//显示联系人
void showperson(addressbooks * abs)
{
	//判断通讯录中人数是否为0
	if (abs->m_size == 0)
	{
		cout << "当前记录为0" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->personarry[i].m_name << "\t";
			cout << "性别：" << (abs->personarry[i].m_sex ==1?"男":"女" )<< "\t";
			cout << "年龄：" << abs->personarry[i].m_age << "\t";
			cout << "电话：" << abs->personarry[i].m_phone<< "\t";
			cout << "地址：" << abs->personarry[i].m_addr << endl;
			
		}
	}

	system("pause");
	system("cls");
	
}

//根据姓名检测联系人是否存在,如果存在返回联系人的位置，不存在返回-1
int isexist(addressbooks* abs, string name)  //参数一表示传入通讯录，参数二表示传入需要检测的姓名
{
	for(int i=0;i<abs->m_size;i++)
	{
		if (abs->personarry->m_name == name)
		{
			return i;
		 }
	 }
	return -1;  //如果遍历都没找到，返回-1
}

//删除联系人
void deleteperson(addressbooks* abs)
{
	cout << "请输入删除联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)//找到此人，进行删除
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			//数据前移操作
			abs->personarry[i] = abs->personarry[i + 1];
		}
		abs->m_size--;//更新通讯录中的人员数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
	

}

//查找指定联系人信息
void findperson(addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	//判断人是否存在
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personarry[ret].m_name << "\t";
		cout << "性别：" << (abs->personarry[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personarry[ret].m_age << "\t";
		cout << "电话：" << abs->personarry[ret].m_phone << "\t";
		cout << "地址：" << abs->personarry[ret].m_addr << endl;
	}
	else
	{
		cout << "联系人不存在" << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyperson(addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "找到此人" << endl;
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarry[ret].m_name = name;
		//		//性别,如果输入的是1或2可以退出循环
		int sex = 0;
		cout << "请输入性别，1表示男，2表示女：" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarry[ret].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//		
				//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personarry[ret].m_age = age;

		string phone;
		cout << "请输入联系人电话：" << endl;
		cin >> phone;
		abs->personarry[ret].m_phone = phone;
		string addr;
		cout << "请输入家庭住址：" << endl;
		cin >> addr;
		abs->personarry[ret].m_addr = addr;
		//更新通讯录人数
		cout << "联系人修改成功" << endl;

		//清屏
		system("pause");
		system("cls");

	}
	else
	{
		cout << "联系人不存在" << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人
void cleanperson(addressbooks* abs)
{
	//判断是否清空
	cout << "请确认是否进行清空，是选择yes,否选择no" << endl;
	string choice;
	cin >> choice;
	if (choice == "yes")
	{
		abs->m_size = 0;//将当前记录人数的size修改为0
		cout << "通讯录已清空" << endl;
	}
	else
	{
		cout << "不进行清空" << endl;
	}
	system("pause");
	system("cls");

}

int main()
{
	//创建通讯录
	addressbooks abs;
	//初始化通讯中的人员个数
	abs.m_size = 0;

	int select = 0;//用户输入放入变量

	while (true)
	{
		//菜单显示
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addperson(&abs);  //利用地址传递，可以修改实参
			break;
		case 2://显示联系人
			showperson(&abs);
			break;
		case 3://删除联系人
		//{
		//	cout << "请输入删除联系人姓名：" << endl;
		//	string name;
		//	cin >> name;
		//	if (isexist(&abs, name) == -1)
		//	{
		//		cout << "查无此人" << endl;
		//	}
		//	else
		//	{
		//		cout << "找到此人" << endl;
		//	}
		//}
			deleteperson(&abs);
			break;
		case 4://查找联系人
			findperson(&abs);
			break;
		case 5://修改联系人
			modifyperson(&abs);
			break;
		case 6://清空联系人
			cleanperson(&abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	
	system("pause");
	return 0;
}