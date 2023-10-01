#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
//添加系统时间的头文件
#include <ctime>
using namespace std;

int main03()
{
	//在屏幕中循环打印0~9这个数字
	int n = 0;
	while (n < 10)
	{
		cout << "n=" << n<<endl;
		n++;
	}

	//系统随机生成1-100数字，进行猜数字，猜对了游戏结束
	//添加随机数的种子，利用当前系统时间生成随机数，防止每次随机数相同
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;//生成1-100的随机数
	cout << "num=" << num << endl;
	//玩家进行猜测
	int guessnum = 102;
	while (guessnum != num)
	{
		cin >> guessnum;
		cout << "你猜测的数字为：" << endl;
		if (guessnum > num)
			cout << "猜大了" << endl;
		else if (guessnum < num)
			cout << "猜小了" << endl;
		else
		{
			cout << "猜对了" << endl;
			break;
		}
			
	}


	//do while ,在屏幕输出0-9
	int x = 0;
	do 
	{
		cout << "x=" << x << endl;
		x++;
	} while (x < 10);


	//水仙花数
	//找到所有的三位数
	int m = 100;
	int a = 0, b = 0, c = 0;
	do
	{
		a = m % 10;//个位
		b = (m / 10) % 10;//十位
		c = m / 100;//百位
		if ((a*a*a + b*b*b  + c *c*c) == m)
			cout << m << "是水仙花数" << endl;

		m++;
	} while (m < 1000);





	return 0;
}