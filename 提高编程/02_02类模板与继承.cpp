#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* 当类模板碰到继承时，需要注意以下几点
* 1.当子类继承的父类是一个类模板时，子类需要指出父类中T的类型
* 2.如果不指定，编译器无法给子类分配内存
* 3.如果想灵活指定出父类中的T的类型，子类也需要变为类模板
*/

template<class T>
class Base
{
	T m;
};

class Son :public Base<int>
{

};

void test01()
{
	Son s1;
}

template<class T1,class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "T1的类型为" << typeid(T1).name() << endl;
		cout << "T2的类型为" << typeid(T2).name() << endl;
	}
	T1 obj;
};
void test02()
{
	Son2<int, char>s2;
}

int main()
{
	test02();
	return 0;
}