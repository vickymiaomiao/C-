#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
using namespace std;

int main04()
{
	//for 循环
	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
	}
	


	//敲桌子，1-100，包含数字7或者7的背书需要敲桌子
	for (int n = 1; n < 101; n++) 
	{
		int a = 0, b = 0,c=0;
		a = n % 10;
		b = n / 10;
		c = n % 7;
			if (a == 7 || b == 7 || c == 0)
			{
				cout <<  " 敲桌子" << endl;
			}
			else
				cout << n << endl;
	}


	//嵌套循环,打印10*10的*
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
			cout << "* ";
		cout << endl;
	}


	//乘法口诀表
	for (int n1 = 1; n1 < 10; n1++)//行数
	{
		for (int n2 = 1; n2 <= n1; n2++)//列数
			cout << " " << n2 << "x" << n1 << "=" << n1 * n2;
		cout << endl;
	}

	//goto可以跳转到任意想跳转的地方

	return 0;
}