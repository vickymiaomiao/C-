#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;

//new用来在堆区开辟数据，delete可以用来释放数据
int* funcnew()
{
	int* p = new int(30);//new返回改数据类型的指针,表示P的保存的地址中存放的数据是30
	return p;
}

void testnew()
{
	int* p = funcnew();
	cout << *p << endl;
	//堆区的数据由管理员开辟释放
	//如果要释放堆区的数据，需要使用delete
	delete p;//释放地址即可
	//cout << *p << endl; //内存已经释放，再次访问就是非法操作
}

//new 来开辟数组
void testnewaarray()
{
	//创建10个整形数据的数组，在堆区
	int* arr = new int[10];//10代表数组中有10个数据
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 10;   //赋值10-19
	}
	for (int i = 0; i < 10; i++)
	{
		cout << "arr[" << i << "]=" << arr[i] << endl;
	}
	//释放堆区数组,需要添加中括号[]
	delete[] arr;
}

int main11()
{
	testnew();
	testnewaarray();

	return 0;
}