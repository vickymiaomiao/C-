#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
#include "02_06 MyArray.hpp"
using namespace std;

/*
* 实现一个通用的数组类，要求如下：
* 1.可以对内置数据类型以及自定义数据类型进行存储
* 2.将数组中的数据存储到堆区
* 3.构造函数中可以传入数组的容量
* 4.提供对应的拷贝构造函数以及operator=防止浅拷贝的问题
* 5.提供尾插法和尾删法对数组中的数据进行增加和删除
* 6.可以通过下标的方式访问数组中的元素
* 7.可以获取数组中当前元素个数和数组的容量
*/
void printIntArray(MyArray<int> &arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}

void test01()
{
	MyArray<int> arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(i); //利用尾插法像数组中插入数据
	}
	cout << "arr1的打印:" << endl;
	printIntArray(arr1);
	cout << "arr1的容量:" << arr1.getCapacity() << endl;
	cout << "arr1的大小:" << arr1.getSize() << endl;
	MyArray<int> arr2(arr1);
	cout << "arr2的打印:" << endl;
	printIntArray(arr2);
	//尾删法
	arr2.Pop_Back();
	cout << "arr2的容量:" << arr2.getCapacity() << endl;
	cout << "arr2的大小:" << arr2.getSize() << endl;
	MyArray<int> arr3(100);
	arr3 = arr1;   //赋值调用
}

//测试自定义的数据类型
class Person
{
public:
	Person() {}; //默认构造
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "name: " << arr[i].m_Name << " age: " << arr[i].m_Age << endl;
	}
}

void test02()
{
	MyArray<Person> arr(10);
	Person p1("vicky", 18);
	Person p2("tom", 18);
	Person p3("bob", 18);
	Person p4("andy", 18);
	Person p5("lucy", 18);
	//将数据插入到数组中
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4); 
	arr.Push_Back(p5);

	//打印数组
	printPersonArray(arr);
	//输出容量和大小
	cout << "arr capacity:" << arr.getCapacity() << endl;
	cout << "arr size:" << arr.getSize() << endl;

}

int main()
{
	test01();
	test02();
	return 0;
}