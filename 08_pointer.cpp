#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
using namespace std;

//实现两个数据交换,值传递
void swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}


void swap02(int* p1,int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;

}

//冒泡排序函数
void bubblesort(int * arr,int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//打印数组
void printarray(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "arr[" << i << "]=" << *arr << endl;
		arr++;
	}
}

int main08()
{
	//定义指针
	int a = 10;
	int* pa;
	pa = &a;
	cout << "a的地址为" << pa << endl;
	//指针前加一个*表示解引用,可以找到a的值
	cout << "a的值为" << *pa << endl;
	*pa = 100;
	cout << "a的值为" << *pa << endl;
	cout << "sizeof (int *) = " << sizeof(pa) << endl;
	cout << "sizeof (int *) = " << sizeof(int *) << endl;

	//空指针，只想内存中编号为0的空间
	//初始化指针变量，空指针指向的内存无法访问
	//0-255之间的内存是系统占用的，因此不可以访问
	int* pb = NULL;
	//*pb=100;
	// 空指针和野指针都不是我们申请的空间，因为不要访问
	//野指针，指针变量指向非法的内存空间，在程序中尽量避免出现野指针
	//int* pc = (int*)0x1100;  //0x1100的内存没有访问权限
	
	//const修饰指针---常量指针
	int b = 10;
	const int* pc = &a;  //指针的指向可以修改，但是指针指向的值不可以修改
	//*pc=20;  //错误，指针的值不可以改
	pc = &b;//正确

	//指针常量 const 修饰常量，指针的值可以改，指向不能改
	int* const pd = &a;
	*pd = 20;
	//pd = &b; //错误指向不可以更改

	//既修饰指针又修饰常量,指向和值都不可以更改
	const int* const pe = &a;

	//指针和数组
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* parr = arr;//arr就是数组的首地址
	//cout << "第一个元素的数据:" << *parr << endl;
	//parr++;//移动四个字节
	//cout << "第二个元素的数据:" << *parr << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "第" << i << "个元素的数据是：" << *parr << endl;
		parr++;
	}

	//指针和函数，指针作为函数的形参
	int x = 10, y = 20;
	swap01(x, y);
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	//地址传递,可以修改实参
	swap02(&x, &y);
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;

	//指针和数组和函数
	//case:封装一个函数，利用冒泡排序实现对形数组的升序排序
	int arr1[10] = { 4,3,6,9,1,2,10,8,7,5 };
	int len = sizeof(arr1) / sizeof(arr1[0]);
	bubblesort(arr1, len);
	printarray(arr1, len);


	return 0;
}