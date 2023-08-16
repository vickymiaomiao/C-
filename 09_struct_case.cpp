//#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

struct student
{
	string name;
	int score;
};

struct teacher1
{
	string name;
	struct student stu[5];
};

void allocatespace(struct teacher1 arr[], int len)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		arr[i].name = "t_";
		arr[i].name += nameSeed[i];
		for (int j = 0; j < 5; j++)
		{
			arr[i].stu[j].name = "s_";
			arr[i].stu[j].name += nameSeed[j];
			arr[i].stu[j].score = 60;
		}
		
	}
}

void printfinfo(struct teacher1 arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "  teacher name:" << arr[i].name ;
		for (int j = 0; j < 5; j++)
		{
			cout << "  student name:" << arr[i].stu[j].name ;
			cout << "  student score:" << arr[i].stu[j].score ;
		}
		cout << endl;
	}
}

int main()
{
	struct teacher1 arr[3];
	
	int len = sizeof(arr) / sizeof(arr[0]);
	allocatespace(arr, len);
	printfinfo(arr, len);
	return 0;
}