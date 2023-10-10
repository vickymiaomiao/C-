#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
#include "02_06 MyArray.hpp"
using namespace std;

/*
* ʵ��һ��ͨ�õ������࣬Ҫ�����£�
* 1.���Զ��������������Լ��Զ����������ͽ��д洢
* 2.�������е����ݴ洢������
* 3.���캯���п��Դ������������
* 4.�ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ����������
* 5.�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
* 6.����ͨ���±�ķ�ʽ���������е�Ԫ��
* 7.���Ի�ȡ�����е�ǰԪ�ظ��������������
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
		arr1.Push_Back(i); //����β�巨�������в�������
	}
	cout << "arr1�Ĵ�ӡ:" << endl;
	printIntArray(arr1);
	cout << "arr1������:" << arr1.getCapacity() << endl;
	cout << "arr1�Ĵ�С:" << arr1.getSize() << endl;
	MyArray<int> arr2(arr1);
	cout << "arr2�Ĵ�ӡ:" << endl;
	printIntArray(arr2);
	//βɾ��
	arr2.Pop_Back();
	cout << "arr2������:" << arr2.getCapacity() << endl;
	cout << "arr2�Ĵ�С:" << arr2.getSize() << endl;
	MyArray<int> arr3(100);
	arr3 = arr1;   //��ֵ����
}

//�����Զ������������
class Person
{
public:
	Person() {}; //Ĭ�Ϲ���
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
	//�����ݲ��뵽������
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4); 
	arr.Push_Back(p5);

	//��ӡ����
	printPersonArray(arr);
	//��������ʹ�С
	cout << "arr capacity:" << arr.getCapacity() << endl;
	cout << "arr size:" << arr.getSize() << endl;

}

int main()
{
	test01();
	test02();
	return 0;
}