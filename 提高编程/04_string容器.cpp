#define _CRT_SECURE_NO_WARNINGS 1 
#include <string>
#include <iostream>
using namespace std;


/*
* string是C++风格的字符串
* string和char *的区别：
* 1.char *是一个指针
* 2.string是一个类，类内部封装了char *,管理这个字符串，是一个char *型的容器
* 
* string内部封装了很多成员方法，如find,copy,delete,replace,insert
* 
* 构造函数 :
* string();  默认构造，创建一个空字符串
* string(const char* s);    使用字符串初始化
* string(const string& s);    拷贝构造函数，使用一个string对象初始化另一个
* string(int n,char c);     使用N个字符初始化 字符串
*/

void test01()
{
	string s1;
	const char* str = "hello ,vicky";
	string s2(str);
	cout << s2 << endl;

	string s3(s2);
	cout << s3 << endl;

	string s4(10, 'a');
	cout << s4 << endl;
}

/*
* 赋值操作 assign  \  =
*/

void test02()
{
	string str1;
	str1 = "hello,vicky";
	cout << str1 << endl;
	//把字符串str1赋值给str2
	string str2;
	str2 = str1;
	cout << str2 << endl;
	//把字符a赋值给str3
	string str3;
	str3 = 'a';
	cout << str3 << endl;
	//把字符串s赋值给str4
	string str4;
	str4.assign("hello,c++");
	cout << str4 << endl;
	//把字符串的前N个字符赋值给s
	string str5;
	str5.assign("hello,vicky", 3);
	cout << str5 << endl;;

	string str6;
	str6.assign(str5);
	cout << str6 << endl;

	string str7;
	str7.assign(10, 's');
	cout << str7 << endl;
}

/*
* 字符串拼接,实现在末尾拼接字符串 += / append
*/

void test03()
{
	string str1 = " i ";
	str1 += "love you ";
	cout << str1 << endl;

	str1 += '!';
	cout << str1 << endl;

	string str2 = " vicky ";
	cout << str1 + str2 << endl;

	string str3 = "I";
	str3.append(" like ");
	cout << str3 << endl;
	//将前n个字符拼接到字符串尾部
	str3.append("cat", 1);
	cout << str3 << endl;
	//将字符串片拼接到尾部
	str3.append(str1);
	cout << str3 << endl;
	//将字符串从N个位置起截取多少个数据拼接到尾部
	str3.append(str2, 2, 3);  //截取ick
	cout << str3 << endl;
	

	
}

/*
* 查找和替换
* 查找：指定位置字符串是否存在
* 替换：指定位置替换字符串
*/
void test04()
{
	string str1 = "abcdefgde";
	int pos=str1.find("df");//返回出现的位置，没有返回-1
	if (pos == -1)
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}
	//rfind 和 find区别
	//rfind是从右往左查找，find是从左往右查
	pos=str1.rfind("de");
	cout << " rfind pos = " << pos << endl;
	pos = str1.find("de");
	cout << " find pos = " << pos << endl;
	//从哪个位置开始N个字符替换为什么样的字符串
	str1.replace(1, 3, "1111");//1111替换bcd
	cout << str1 << endl;
}

/*
* 字符串比较
* 字符串按照ASCII码进行比较   主要用于判断两个字符串是否相等
* = 返回0
* > 返回1
* < 返回-1
*/
void test05()
{
	string str1 = "vicky1";
	string str2 = "vicky2";
	if (str1.compare(str2) == 0)
	{
		cout << "str1==str2" << endl;
	}
	else if (str1.compare(str2) == 1)
	{
		cout << "str1>str2" << endl;
	}
	else
	{
		cout << "str1<str2" << endl;
	}
	//条件表达式写法
	//str1.compare(str2) >= 0 ? (str1.compare(str2) == 0 ? (cout << "=") : (cout << ">")) : (cout << "<");

}

/*
* 字符存取
* string中单个字符存取的方式有两种
* 1.通过[]
* 2.通过at方法获取字符
*/
void test06()
{
	string str = "hello ,vicky";
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << endl;
	}
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << endl;
	}

	//修改单个字符
	str[0] = 'x';
	cout << str << endl;

	str.at(0) = 'h';
	cout << str << endl;
}

/*
* 插入和删除
* 插入和删除的起始下标都是从0开始
*/
void test07()
{
	string str = "hello";
	//从第几个位置进行插入
	str.insert(1, "xxxx");
	cout << str << endl;
	//从哪个位置起删除多少个
	str.erase(1, 4);
	cout << str << endl;

}

/*
* 子串
* 从字符串中获取想要的子串
* string substr(int pos=0,int n=npos)const;
*/

void test08()
{
	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << subStr << endl;

	//实用操作
	string email = "vickme@163.com";
	//从邮件中获取用户明信息
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << username << endl;
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();
	return 0;
}