#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

struct hero 
{
	string name;
	int age;
	string sex;
};

//ð������ʵ��������������
void bubblesort(struct hero h[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			//���J>J+1,������������
			if (h[j].age > h[j + 1].age)
			{
				struct hero temp = h[j];
				h[j] = h[j + 1];
				h[j + 1] = temp;
			}
		}
	}
}

//��������ð�����������е�Ӣ�۰�����������
int main09case2()
{
	struct hero h[5] =
	{
		{"A",23,"MALE"},
		{"B",26,"MALE"},
		{"C",10,"MALE"},
		{"D",3,"MALE"},
		{"E",33,"FAMALE"},
	};
	int len = sizeof(h) / sizeof(h[0]);
	bubblesort(h, len);
	for (int i = 0; i < len; i++)
	{
		cout << " ������" << h[i].name <<
			" ���䣺" << h[i].age <<
			" �Ա�" << h[i].sex << endl;
	}

	return 0;

}