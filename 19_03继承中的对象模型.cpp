#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
/*
* 继承中的对象模型
* 从父类继承过来的成员，哪些属于子类对象中？
* 父类中所有的非静态成员都会被子类继承下午
* 父类中私有成员也被子类继承，但是被编译器隐藏了，所以无法访问
*/

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class son :public Base
{
public:
	int m_D;
};

//利用开发人员命令提示工具查看对象模型
//跳转盘符 F：
// 跳转文件路径 cd 具体路径
// 查看命令
// cl /d1 reportSingleClassLayout类名 文件名
//

void test01()
{
	son s1;
	cout << sizeof(son) << endl; //16个字节
	cout << sizeof(s1) << endl;  //16个字节
}


int main()
{
	test01();
	return 0;
}