#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main06()
{
	//二维数组的定义
	int arr1[2][3] = 
	{ 
		{1,2,3},
		{4,5,6} 
	};
	int arr2[2][3] = { 1,2,3,4,5,6 };
	int arr3[][3] = { 1,2,3,4,5,6 };
	for(int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "arr1[" << i << "][" << j << "]=" << arr1[i][j] << " ";
			cout << "arr2[" << i << "][" << j << "]=" << arr1[i][j] << " ";
			cout << "arr3[" << i << "][" << j << "]=" << arr1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//查看二维数组的名称，可以查看占用的内存空间大小
	int arr4[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};
	cout << "二维数组占用的内存空间为：" << sizeof(arr4) << endl;
	cout << "二维数组第一行占用的内存空间为：" << sizeof(arr4[0]) << endl;
	cout << "二维数组第一个元素占用的内存空间为：" << sizeof(arr4[0][0]) << endl;
	cout << "行数为：" << sizeof(arr4) / sizeof(arr4[1]) << endl;
	cout << "列数为：" << sizeof(arr4[0]) / sizeof(arr4[0][0]) << endl;
	
	//查看二维数组的首地址
	cout << "二维数组的首地址：" << arr4 << endl;
	cout << "第一行数据的首地址：" << arr4[0] << endl;
	cout << "第二行数据的首地址：" << arr4[1] << endl;
	cout << "第一个元素数据的首地址：" << &arr4[0][0] << endl;
	cout << endl;

	//案列输出3名同学的总成绩
	int score[3][3] =
	{
		{100,100,100},
		{90,50,100},
		{60,70,80}
	};
	string names[3] = {"张三","李四","王五"};

	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum = sum + score[i][j];
		}
		cout <<  names[i] << "的成绩：" << sum << endl;
	}

	
	
	
	
	
	return 0;
}