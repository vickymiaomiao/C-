#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
using namespace std;

int main01()
{
	//逻辑运算符
	int a = 10;
	//在C++中除了0都为真
	cout << !a << endl;
	cout << !!a << endl;
	int b = 10;
	cout <<"a&&b=" << (a && b) << endl;
	int c = 0;
	cout << (a || b) << endl;
	//程序结构：顺序，选择，循环
	//选择结构
	//让用户输入分数，分数大于600，考生一本
	int score = 0;
	cout << "请输入分数：" << endl;
	cin >> score;
	cout << "您输入的分数为：" << score << endl;
	//if 条件后面不能加分号
	if (score > 600)
	{
		cout << "考上一本" << endl;
		if (score > 700)
		{
			cout << "考上清华" << endl;
		}
		else 
		{
			cout << "考上浙大" << endl;
		}
	}
	else if(score<600 && score>500)
	{
		cout << "考上二本" << endl;
	}
	else
	{
		cout << "没考上" << endl;
	}
	//求三只猪的最重的体重
	int piga = 0, pigb = 0, pigc = 0;
	int max = 0;
	cout << "请输入三只猪的体重" << endl;
	cin >> piga;
	cin >> pigb;
	cin >> pigc;
	if (piga > pigb)
	{
		max = piga;
		if (max < pigc)
			max = pigc;	
	}
	else {
		max = pigb;
		if (max < pigc)
			max = pigc;
	}
	cout << "max=" << max << endl;

	//三目运算符
	int x1 = 10, x2 = 20, y = 0;
	c = (x1 > x2) ? x1 : x2;
	cout << "c=" << c<<endl;
	return 0;

}