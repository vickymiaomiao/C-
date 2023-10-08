#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

//利用函数模板封装一个排序函数，可以对不同类型的数组进行排序
//排序规则为从大到小，排序算法为选择排序
//分别用char数组和int数组进行测试
//
//实现交换模板
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//排序模板
template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;//认定i为最大值
		for (int j = i+1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j; //更新最大值的下标
			}
		}
		if (max != i)
		{
			//交换max和i的元素
			mySwap(arr[max], arr[i]);
		}

	}
}

//打印数组的模板
template<typename T>
void printArrary(T arr[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
}

void test01()
{
	char chararr[] = "badcfe";
	int num = sizeof(chararr) / sizeof(chararr[0]);
	mySort(chararr, num);
	printArrary(chararr, num);

	int intarr[] = { 2,5,7,3,1,8,0,9 };
	int num1 = sizeof(intarr) / sizeof(intarr[0]);
	mySort(intarr, num1);
	printArrary(intarr, num1);
}

int main()
{
	test01();
	return 0;
}