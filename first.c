#define _CRT_SECURE_NO_WARNINGS 1   //加在源文件的第一行

#include <stdio.h>
#include <string.h>
#define max 10   //标识符常量

//enum sex
//{
//	male,
//	female,
//	secret
//};
//
//enum color 
//{
//	red,
//	yellow,
//	green,
//	black
//};

//int add(int x,int y)
//{
//	int z = x + y;
//	return z;

//}
	//结构体创建结构体类型
struct book
{
	char name[20];
	short price;
};

extern int add(int x, int y);

int main1()
{
	struct book b1 = { "Cyuyan",55 };//创建该类型的结构体变量
	strcpy(b1.name, "c++");    //字符串赋值形式都需要用到strcpy，关于字符串操作的
	//.结构体变量.成员
	//->结构体指针->成员
	struct book* pb = &b1;
	printf("%p\n", pb);
	printf("书名:%s\n", pb->name);
	printf("价格：%d\n", pb->price);
	//利用pb打印书名和价格
	printf("书名:%s\n", (*pb).name);
	printf("价格：%d\n", (*pb).price);
	printf("书名:%s\n", b1.name);
	printf("价格：%d\n", b1.price);
	b1.price = 15;
	printf("修改后价格：%d\n", b1.price);



	
	//int a = 10, b = 20;
	//int* p = &a;
	//printf("a的地址位：%p\n", &a);
	//printf("b的地址位：%p\n", &b);
	//printf("a的值为：%d", *p);
	//printf("sum=%d+%d=%d\n", a,b,add(a,b));
	//register int a = 10;//建议将a定义为寄存器变量
	//条件操作符 a?b:c，如果A为真，结果为B，否则结果为C
	//int a = 10, b = 20;
	//printf("%d", (a > b) ? a : b);
	//逗号表达式，用逗号连起来的表达式
	//int arr[10] = { 0 };
	//int sz = 0;
	////计算数组所占内存
	//printf("%d\n", sizeof(arr));
	////计算数组的元素个数
	//sz = sizeof(arr) / sizeof(arr[0]);
	//printf("%d\n", sz);
	//sizeof可以计算数据类型或者变量 所占的字节数，加变量可以省略括号，加类型不可以省略
	//单目操作符，双目操作符，三目操作符
	//int a = 1;
	//int b = 0;
	//int c = a & b;//异或：对应的二进制位相同则为0，不同则为1
	//b = a << 2;
	//printf("c=%d\n", c);
	//printf("%d\n", b);
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,20 };//连续存储，下标访问元素
	//int i = 0;
	//while (i < 10)
	//{
	//	printf("a[%d]=%d\n", i, arr[i]);
	//	i++;
	//}
	//int a = 10, b = 20;
	//printf("相加的值等于=%d\n", add(a, b));

	//int i = 0;
	//printf("加入选择\n");
	//while (i < 200)
	//{
	//	printf("敲代码行数：%d\n",i);
	//	i++;
	//}
	//if(i>200)
	//	printf("ok");
	


	//scanf("%d", &i);
	//if (i == 0)
	//	printf("ok\n");
	//else
	//	printf("no\n");
	////\t - 水平制表符，\可以用来转移\,\\表示输出\
	////ascii编码值a=97,A=65
	//char arr1[] = "abc";//字符串自带结束标志符号'\0'，不算字符内容
	//char arr2[] = { 'a','b','c',0 };//主动添加字符串结束标志


	//enum color r = red;
	//enum sex s = male;
	////const 常属性，修饰的常变量
	//const int num = 8;
	////枚举 enum
	//printf("strlen arr1=%d\n", strlen(arr1));//用来计算字符串长度
	//printf("strlen arr2=%d\n", strlen(arr2));
	//printf("%s\n", arr1);
	//printf("%s\n", arr2);
	//printf("%d\n", num);
	//printf("%d\n", max);
	//printf("%d\n", male);
	//printf("%d\n", female);
	//printf("%d\n", secret);
	////num = 10;
	////printf("%d\n",num);
	return 0;
}