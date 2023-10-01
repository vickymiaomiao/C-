#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* C++通过提供特殊的对象指针，this指针，解决上述问题，this指针指向被调用的成员函数所属的对象
*this指针是隐含每一个非静态成员函数内的一种指针
* this指针不需要定义，直接使用即可
* 
* this指针的用途：
* 1.当形参和成员变量同名时，可用this指针来区分
* 2.在类的非静态成员函数中返回对象本身，可使用return *this
*
*/

class person
{
public:
	person(int age)
	{
		//this指针指向被调用的成员函数所属的对象
		this->age = age;
	}

	person& personaddperson(person& p)  //引用的方式返回，不会创建新的对象
	{
		this->age += p.age;
		return *this;
	}


	int age;
};

void test02()
{
	person p1(10);

	person p2(20);
	//链式编程思想
	p2.personaddperson(p1).personaddperson(p1).personaddperson(p1);
	cout << "p2的年龄为" << p2.age << endl;
}
void test01()
{
	person p1(18);
	cout << "p1的年龄为" << p1.age << endl;
}



int main()
{
	test01();
	test02();
	return 0;
}