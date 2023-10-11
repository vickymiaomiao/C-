#define _CRT_SECURE_NO_WARNINGS 1   
#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
* vector���ݽṹ������ǳ����ƣ���Ϊ��������
* vector����ͨ���������
* �����Ǿ�̬�ռ䣨һ�����壬���Ȳ����Ը��ģ�����vector���Զ�̬��չ
* ��̬��չ����������ԭ�ռ�֮�������¿ռ䣬�����Ҹ�����ڴ�ռ䣬Ȼ��ԭ���ݿ������¿ռ䣬�ͷ�ԭ�ռ�
* vector����֧��������ʵ�����
*/
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it <<" ";
	}
	cout << endl;
}

//���캯��  ����vector����
void test01()
{
	vector<int>v1;//Ĭ���޲ι���
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//ͨ�����乹��
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);
	//N��elem�ķ�ʽ
	vector<int>v3(10, 100);
	printVector(v3);
	//�������캯��
	vector<int>v4(v3);
	printVector(v4);
}

//��ֵ���� =  /  assign
void test02()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	//��ֵ �Ⱥŷ�ʽ
	vector<int>v2;
	v2 = v1;
	printVector(v2);
	//assign
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());//ǰ��������䣬v2.end()ֵ�޷�ȡ��
	printVector(v3);
	//N��elem�ķ�ʽ���и�ֵ
	vector<int> v4;
	v4.assign(10, 100);
	printVector(v4);
}

//vector�����ʹ�С�Ĳ���  
//empty:�ж��Ƿ�Ϊ��
//capacity ��������������
//size ������Ԫ�ظ���
//resize������ָ����С
//
void test03()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	//�ж������Ƿ�Ϊ�գ�����ֵΪtrue or false
	if (v1.empty())   //Ϊ���������Ϊ��
	{
		cout << "v1 is empty" << endl;
	}
	else
	{
		cout << "v1 is not empty" << endl;
		//�������
		cout << "v1's capacity:" << v1.capacity() << endl;
		//���size
		cout << "v1's size:" << v1.size() << endl;
	}
	//����ָ����С  resize 
	//��ָ����������ԭ����������Ĭ����0�����
	v1.resize(15);
	printVector(v1);
	cout << "v1's capacity:" << v1.capacity() << endl;
	//Ҳ��ָ���������
	v1.resize(20,100);  //�������ذ汾ָ�����ֵ
	printVector(v1);
	//��ָ������С��ԭ���������������Ĳ��ֻᱻɾ����
	v1.resize(5);
	printVector(v1);
}

//�����ɾ��
//push_back():��β������
//pop_back()��ɾ�����һ��Ԫ��
// insert���ڵ�����ָ��λ�ò���Ԫ�ػ��߲���count��elem
// erase:ɾ��start��end֮���λ��
// clear()�� ɾ������������Ԫ��
void test04()
{
	vector<int>v1;
	//β��
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);
	//βɾ
	v1.pop_back();
	printVector(v1);
	//����   �ṩ�����������в��룬��һ����������
	v1.insert(v1.begin(), 100);
	printVector(v1);
	//��������ͬ������
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);
	//ɾ�� ����Ҳ�ǵ�����
	v1.erase(v1.begin()); 
	printVector(v1);
	//�ṩ�������ɾ��
	//v1.erase(v1.begin(), v1.end());//���
	//�������
	v1.clear();
	printVector(v1);
}

//��ȡ����
//at [] front()�����������е�һ��Ԫ��   back():�������������һ������Ԫ��
void test05()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		//����at����
		cout << v1.at(i)<<" ";
		//����[]����
		cout << v1[i] ;
	}
	cout<<endl;
	//��ȡ��һ��Ԫ��
	cout << " first elem:" << v1.front() << endl;
	//���һ��Ԫ��
	cout << "end elem:" << v1.back() << endl;
}

//��������
//ʵ������������Ԫ�ؽ��л���
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
	//ʵ����;�����������ڴ�ռ�
	vector<int>v3;
	for (int i = 0; i < 100000; i++)
	{
		v3.push_back(i);
	}
	cout << "v3 capacity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
	v3.resize(3);//����ָ����С��size��ı䣬����������
	cout << "v3 capacity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
	//����swap�����ڴ�
	vector<int>(v3).swap(v3);//��������
	cout << "v3 capacity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
}

//Ԥ���ռ�
//����vector�ڶ�̬��չ����ʱ����չ����
//reserve(int len),����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ���
void test07()
{
	vector<int>v3;
	//����reserveԤ���ռ�
	v3.reserve(100000);
	int num = 0;//ͳ�ƿ��ٴ���   ��Ԥ���ռ���Ҫ����30�οռ䣬Ԥ���ռ�ֻ����һ��
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