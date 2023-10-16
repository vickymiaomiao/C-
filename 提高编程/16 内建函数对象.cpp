#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/*
* STL内建了一些函数对象
* 分类：
* 算数仿函数 :plus minus multiplies divides modulus negate
* 关系仿函数 :equal not_equal_to greater greater_equal less less_equal
* 逻辑仿函数 :logical_and logical_or logical_not
* 
* 用法:
* 这些仿函数所产生的对象，用法和一般函数完全相同
* 使用内建函数对象，需要引入头文件#include <functional>
* 
* nagate 一元运算 
*/

//取反仿函数
void test01()
{
	negate<int>n;
	cout << n(-10) << endl;

	//plus 二元仿函数
	plus<int>p;   //数据类型只写一个int 
	cout << p(10, 10) << endl;
}

class mycompare
{
public:
	bool operator()(int v1,int v2)
	{
		return v1 > v2;
	}
};

void test02()
{
	vector<int>v1;
	v1.push_back(40);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(50);
	v1.push_back(30);
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//降序
	//sort(v1.begin(), v1.end(), mycompare());
	//greater<int>()内建函数对象
	sort(v1.begin(), v1.end(),greater<int>());

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test03()
{
	vector<bool>v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//利用逻辑非 将容器V搬运到容器V2中，并执行取反操作
	vector<bool>v2;
	v2.resize(v1.size());   //目标容器需要提前开辟空间
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}