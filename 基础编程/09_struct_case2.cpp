#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

struct hero 
{
	string name;
	int age;
	string sex;
};

//冒泡排序实现年龄升序排列
void bubblesort(struct hero h[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			//如果J>J+1,交换两个数据
			if (h[j].age > h[j + 1].age)
			{
				struct hero temp = h[j];
				h[j] = h[j + 1];
				h[j + 1] = temp;
			}
		}
	}
}

//根据利用冒泡排序将数组中的英雄按照年龄排序
int main09case2()
{
	struct hero h[5] =
	{
		{"A",23,"MALE"},
		{"B",26,"MALE"},
		{"C",10,"MALE"},
		{"D",3,"MALE"},
		{"E",33,"FAMALE"},
	};
	int len = sizeof(h) / sizeof(h[0]);
	bubblesort(h, len);
	for (int i = 0; i < len; i++)
	{
		cout << " 姓名：" << h[i].name <<
			" 年龄：" << h[i].age <<
			" 性别：" << h[i].sex << endl;
	}

	return 0;

}