#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <stack>
using namespace std;

/*
* stack是一种先进后出的数据结构，只有一个出口
* 栈中只有顶端的元素可以被外界使用，栈不允许有遍历行为
* 入栈 push
* 出栈 pop
* top()  返回顶部元素
* empty size
*/

void test01()
{
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	//查看栈中的数据
	while (!s.empty())
	{
		//查看栈顶元素
		cout<<s.top()<<" ";
		//出栈
		s.pop();
	}
	cout << endl;
	cout << "stack size: " << s.size() << endl;
}

int main()
{
	test01();
	return 0;
}