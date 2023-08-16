#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>
#include <string>
using namespace std;

//结构体定义
struct student
{
	string name;
	int age;
	int score;
} s3;

//结构体嵌套
struct teacher
{
	int id;
	string name;
	int age;
	struct student stu;
};

//打印学生信息的函数值传递
void printstudent1(struct student s)
{
	cout << "子函数中值传递" << endl;
	cout << "姓名：" << s.name << " 年龄：" << s.age << " 成绩：" << s.score << endl;
}
//地址传递
void printstudent2(struct student *p)
{
	cout << "子函数中地址传递" << endl;
	cout << "姓名：" << p->name << " 年龄：" << p->age << " 成绩：" << p->score << endl;
}

int main09()
{
	//struct student s1
	struct student s1;  //创建变量时struct关键字可以省略，定义时不可以省略
	s1.name = "李四";
	s1.age = 10;
	s1.score = 100;
	cout << "姓名：" << s1.name << " 年龄：" << s1.age << " 成绩：" << s1.score << endl;
	struct student s2 = {"张三",14,60};
	cout << "姓名：" << s2.name << " 年龄：" << s2.age << " 成绩：" << s2.score << endl;
	s3.name = "王五";
	s3.age = 10;
	s3.score = 90;
	cout << "姓名：" << s3.name << " 年龄：" << s3.age << " 成绩：" << s3.score << endl;
	cout << endl;

	//结构体数组
	struct student s4[3] =
	{
		{"张三",14,60},
		{"王五", 10, 100},
		{"李六",13,99},
	};
	s4[2].name = "小明";
	s4[2].age = 80;
	s4[2].score = 60;
	for (int i = 0; i < 3; i++)
	{
		cout << "姓名：" << s4[i].name << " 年龄：" << s4[i].age << " 成绩：" << s4[i].score << endl;
	}

	//结构体指针，通过指针访问结构体成员，利用操作符->可以通过结构体指针访问结构体属性
	struct student s5 = { "vicky",18,100 };
	struct student * ps = &s5;   //结构体指针
	//访问变量中的数据
	cout <<"name:" << ps->name << endl;
	cout << "age:" << ps->age << endl;
	cout << "score:"<<ps->score << endl;

	//嵌套结构体
	struct teacher t;
	t.id = 10000;
	t.name = "mike";
	t.age = 50;
	t.stu.name = "andy";
	t.stu.age = 10;
	t.stu.score = 100;

	//结构体做函数的参数
	//case将学生传入到一个参数中，打印学生身上的信息
	struct student s6 = { "mike",10,70 };
	printstudent1(s6);
	printstudent2(&s6);

	//结构体中的const ,用const来防止误操作
	//加入const之后只能读，不能进行修改
	

	return 0;
}