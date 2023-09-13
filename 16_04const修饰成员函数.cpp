#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* 常函数
* 1.在成员函数后加上const称函数为常函数
* 2.常函数内不可以修改成员属性
* 3.成员属性声明时加上关键字mutable后，在常函数中可以修改
* 
* 常对象
* 1.声明对象前加const称该对象为常对象
* 2.常对象只能调用常函数
*/

class person
{
public:
	//this指针的本质是指针常量，指针的指向不可以修改
	//person * const this   指向不可以修改
	//在成员函数后面添加const,修饰的是this的指向，让指针指向的值也不可以修改
	void showPerson() const  //指向和值均不可以修改 const person * const this
	{
		//this->m_A = 100;
		//this = NULL; //不可以修改指向
		this->m_B = 100;
	}
	void func(){}

	int m_A;
	mutable int m_B; //特殊变量在常函数中也可以修改
};

void test01()
{
	person p;
	p.showPerson();
}

void test02()
{
	const person p1;//在对象前面加上const表示变为常对象
	//p1.m_A = 100;
	p1.m_B = 100; //特殊值，在常对象下也可以修改
	//常对象只能调用常函数
	//p1.func();
	p1.showPerson();
}

int main()
{
	return 0;
}