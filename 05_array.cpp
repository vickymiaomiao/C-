#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
using namespace std;

int main05()
{
	//数组的特点
	//a.放在连续的内存中 b.每个元素内数据类型相同
	int arr[5];  //声明
	arr[0] = 10; //复制
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;
	//访问数据元素
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}


	int arr2[5] = { 10,20,30,40,50 };//值不够用0填补
	for (int i = 0; i < 5; i++) 
	{
		cout << arr2[i] << endl;
	}

	//定义数组必须给出数组长度
	int arr3[] = { 10,20,30,40,50,60 };
	for (int i = 0; i < 6; i++)
	{
		cout << arr3[i] << endl;
	}

	//一维数组名的用途
	int arr4[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "整个数组占用的内存空间为：" << sizeof(arr4)<<endl;
	cout << "每个元素占用的内存空间为：" << sizeof(arr4[0])<<endl;
	cout << "数组中元素的个数为：" << sizeof(arr4) / sizeof(arr4[0])<<endl;
	//数组的首地址和第一个元素的地址是相同的
	cout << "数组的首地址：" << arr4 << endl;
	cout << "数组中第一个元素的地址：" << &arr4[0] << endl;
	cout << "数组中第二个元素的地址：" << &arr4[1] << endl;
	
	//数组名是常量，不可以进行赋值操作

	//找出体重最重的猪，并打印输出
	int pig[5] = { 300,350,200,400,250 };
	int max = 0;
	for (int n = 0; n < sizeof(pig) / sizeof(pig[0]); n++)
	{
		if (pig[n] > max)
			max = pig[n];
	}
	cout << "最重的猪的体重是：" << max << endl;

	//将元素逆置
	int arr5[5] = {1,2,3,4,5};
	int arr6[5] = {};
	for (int x = 4; x >=0; x--)
	{
		arr6[4-x] = arr5[x];
		cout << "arr6[" << 4-x << "]" <<"=" << arr6[4 - x] << endl;
	}

	//将元素逆置方法二
	int arr7[5] = { 1,2,3,4,5 };
	int start = 0;
	int end = sizeof(arr7) / sizeof(arr7[0]) - 1;
	int temp = 0;
	for (; start <= end; start++,end--)
	{
		temp = arr7[start];
		arr7[start] = arr7[end];
		arr7[end] = temp;
	}
	for (int i = 0; i < sizeof(arr7) / sizeof(arr7[0]); i++)
	{
		cout << "arr7[" << i << "]=" << arr7[i] << endl;
	}

	//冒泡排序，升序排列结果
	int arr8[9] = {4,2,8,0,5,7,1,3,9 };
	int temp1 = 0;
	for (int i = 0; i < sizeof(arr8) / sizeof(arr8[0]); i++)
	{
		for (int j = i; j < sizeof(arr8) / sizeof(arr8[0]); j++)
		{
			if (arr8[i] > arr8[j])
			{
				temp1 = arr8[i];
				arr8[i] = arr8[j];
				arr8[j] = temp1;
				
			}
		}
		cout << "arr8[" <<i<<"]=" << arr8[i] << endl;
	}

	return 0;
}