#define _CRT_SECURE_NO_WARNINGS 1   
#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
* vector数据结构和数组非常相似，称为单端数组
* vector与普通数组的区别：
* 数组是静态空间（一旦定义，长度不可以更改），而vector可以动态扩展
* 动态扩展：并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝到新空间，释放原空间
* vector容器支持随机访问迭代器
*/
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it <<" ";
	}
	cout << endl;
}

//构造函数  创建vector容器
void test01()
{
	vector<int>v1;//默认无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//通过区间构造
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);
	//N个elem的方式
	vector<int>v3(10, 100);
	printVector(v3);
	//拷贝构造函数
	vector<int>v4(v3);
	printVector(v4);
}

//赋值操作 =  /  assign
void test02()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	//赋值 等号方式
	vector<int>v2;
	v2 = v1;
	printVector(v2);
	//assign
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());//前开后闭区间，v2.end()值无法取到
	printVector(v3);
	//N个elem的方式进行赋值
	vector<int> v4;
	v4.assign(10, 100);
	printVector(v4);
}

//vector容量和大小的操作  
//empty:判断是否为空
//capacity ：返回容器容量
//size ：返回元素个数
//resize：重新指定大小
//
void test03()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	//判断容器是否为空，返回值为true or false
	if (v1.empty())   //为真代表容器为空
	{
		cout << "v1 is empty" << endl;
	}
	else
	{
		cout << "v1 is not empty" << endl;
		//输出容量
		cout << "v1's capacity:" << v1.capacity() << endl;
		//输出size
		cout << "v1's size:" << v1.size() << endl;
	}
	//重新指定大小  resize 
	//若指定容量大于原来的容量，默认用0来填充
	v1.resize(15);
	printVector(v1);
	cout << "v1's capacity:" << v1.capacity() << endl;
	//也可指定填充数据
	v1.resize(20,100);  //利用重载版本指定填充值
	printVector(v1);
	//若指定数据小于原来的容量，超出的部分会被删除掉
	v1.resize(5);
	printVector(v1);
}

//插入和删除
//push_back():在尾部插入
//pop_back()：删除最后一个元素
// insert：在迭代器指向位置插入元素或者插入count个elem
// erase:删除start到end之间的位置
// clear()： 删除容器中所有元素
void test04()
{
	vector<int>v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);
	//尾删
	v1.pop_back();
	printVector(v1);
	//插入   提供迭代器来进行插入，第一个参数就是
	v1.insert(v1.begin(), 100);
	printVector(v1);
	//插入多个相同的数据
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);
	//删除 参数也是迭代器
	v1.erase(v1.begin()); 
	printVector(v1);
	//提供区间进行删除
	//v1.erase(v1.begin(), v1.end());//清空
	//清空容器
	v1.clear();
	printVector(v1);
}

//存取操作
//at [] front()：返回容器中第一个元素   back():返回容器中最后一个数据元素
void test05()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		//利用at访问
		cout << v1.at(i)<<" ";
		//利用[]访问
		cout << v1[i] ;
	}
	cout<<endl;
	//获取第一个元素
	cout << " first elem:" << v1.front() << endl;
	//最后一个元素
	cout << "end elem:" << v1.back() << endl;
}

//互换容器
//实现两个容器内元素进行互换
//swap(vec);
void test06()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);

	cout << "swap" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
	//实际用途，可以收缩内存空间
	vector<int>v3;
	for (int i = 0; i < 100000; i++)
	{
		v3.push_back(i);
	}
	cout << "v3 capacity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
	v3.resize(3);//重新指定大小后，size会改变，弹容量不变
	cout << "v3 capacity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
	//巧用swap收缩内存
	vector<int>(v3).swap(v3);//匿名对象
	cout << "v3 capacity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
}

//预留空间
//减少vector在动态扩展容量时的扩展次数
//reserve(int len),容器预留len个元素长度，预留位置不初始化，元素不可访问
void test07()
{
	vector<int>v3;
	//利用reserve预留空间
	v3.reserve(100000);
	int num = 0;//统计开辟次数   不预留空间需要开辟30次空间，预留空间只开辟一次
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v3.push_back(i);
		if (p != &v3[0])
		{
			p = &v3[0];
			num++;
		}
	}
	cout << "num : " << num << endl;
}


int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	return 0;
}