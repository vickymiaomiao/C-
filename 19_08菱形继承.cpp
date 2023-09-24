#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <string>
using namespace std;
/*
* 两个派生类继承同一个基类
* 又有某个类同时继承这两个派生类
* 这种继承被称为菱形继承，或者钻石继承
*/

//动物类
class Animal
{
public:
	int m_Age;
};

//利用虚继承可以解决菱形继承的问题
// 继承之前加上关键字virtual 变为虚继承
// Animal类称为虚基类,添加该关键字后数据只继承一份
// vbptr 虚继承指针  指向vbtable
// v-virtual
// b-base
// ptr-pointer
// 都指向同一份数据
//羊类
class Sheep :virtual public Animal
{};

//驼类
class Tuo :virtual public Animal
{};

//羊驼类
class SheepTuo :public Sheep, public Tuo
{};

void test01()
{
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 20;
	//当菱形继承，两个父类拥有相同数据，需要加以作用域用来区分
	cout << "Sheep::m_Age=" << st.Sheep::m_Age << endl;
	cout << "Tuo::m_Age=" << st.Tuo::m_Age << endl;
	cout << "st.m_Age=" << st.m_Age << endl;
	//

}


int main()
{
	test01();
	return 0;
}