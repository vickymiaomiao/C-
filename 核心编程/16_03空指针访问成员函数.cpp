#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* C++中的空指针也可以修饰成员函数，但是也需注意是否用到this指针
* 如果用到this 指针，需要加以判断保证代码的健壮性
*/

class person
{
public:
	void showClassName()
	{
		cout << "this is person class" << endl;
	}
	void showPersonAge()
	{
		//报错原因是传入的指针为空，所以无法访问到属性
		if (this == NULL)
		{
			return;
		}
		cout << "age=" << m_Age << endl;    //属性前面默认this->m_Age
	}

	int m_Age;
};

void test01()
{
	person* p = NULL;
	p->showClassName();
	//p->showPersonAge();

}

int main()
{
	test01();
	return 0;
}