#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;

//
// 1.构造函数的分类
//按照参数分类，有参数构造和无参数构造（默认构造）
//按照类型分类  普通构造函数和拷贝构造函数
class Person
{
public:
	//构造函数  
	Person()
	{
		cout << "person 的无参构造函数的调用" << endl;
	} 
	Person(int a)
	{
		age = a;
		cout << "person int a 有参构造函数的调用" << endl;
	}
	//拷贝构造函数
	Person(const Person &p)
	{
		//将传入人身上的所有属性拷贝到当前人身上
		age = p.age;
		cout << "person 拷贝构造函数的调用" << endl;
	}

	//析构函数
	~Person()
	{
		cout << "person析构函数的调用" << endl;
	}

	int age;
};


void test1502()
{
	//调用方法
	//1，括号法
	//Person p1;   //默认构造函数的调用
	//Person p2(10);  //有参函数的调用
	////拷贝构造函数的调用
	//Person p3(p2);

	////注意事项1
	////调用默认构造函数时不要加（）
	////因为Person p1();会被编译器认为是函数的声明，不会认为是在创建对象
	//cout << "p2的年龄为：" << p2.age << endl;
	//cout << "p3的年龄为：" << p3.age << endl;

	//2。显示法
	Person p1;
	Person p2 = Person(10);   //有参构造  
	//Person(10)匿名对象，特点：当前行执行结束后，系统会立即回收掉匿名对象
	Person p3 = Person(p2);

	//注意事项2
	// 不要利用拷贝构造函数来初始化匿名对象,编译器Person (p3)==Person p3;对象的声明
	//
	//隐式转换法
	Person p4 = 10;  //Person p2 = Person(10);
	Person p5 = p4;   //拷贝构造


}


int main1502()
{
	test1502();
	return 0;
}