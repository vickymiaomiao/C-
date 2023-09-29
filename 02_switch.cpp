#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
using namespace std;

int main02()
{
	//根据用户输入的分数来提示最后的结果
	int score=0;
	cout << "请给电影打分：" << endl;
	cin >> score;
	cout << "您打的分数为：" << score << endl;
	//判断只能是整形或者字符型，结构清晰，执行效率高
	switch (score)  
	{
	case 10:
		cout << "经典" << endl;
		break;//退出当前分支
	case 9:
		cout << "很好" << endl;
		break;
	case 8:
		cout << "还行" << endl;
		break;
	case 7:
		cout << "一般" << endl;
		break;
	case 6:
		cout << "较差" << endl;
		break;
	default://前面都不满足，最后执行这个
		cout << "烂片" << endl;
		break;
	}
	return 0;
}