#define _CRT_SECURE_NO_WARNINGS 1   //����Դ�ļ��ĵ�һ��

#include <stdio.h>
#include <string.h>
#define max 10   //��ʶ������

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
	//�ṹ�崴���ṹ������
struct book
{
	char name[20];
	short price;
};

extern int add(int x, int y);

int main1()
{
	struct book b1 = { "Cyuyan",55 };//���������͵Ľṹ�����
	strcpy(b1.name, "c++");    //�ַ�����ֵ��ʽ����Ҫ�õ�strcpy�������ַ���������
	//.�ṹ�����.��Ա
	//->�ṹ��ָ��->��Ա
	struct book* pb = &b1;
	printf("%p\n", pb);
	printf("����:%s\n", pb->name);
	printf("�۸�%d\n", pb->price);
	//����pb��ӡ�����ͼ۸�
	printf("����:%s\n", (*pb).name);
	printf("�۸�%d\n", (*pb).price);
	printf("����:%s\n", b1.name);
	printf("�۸�%d\n", b1.price);
	b1.price = 15;
	printf("�޸ĺ�۸�%d\n", b1.price);



	
	//int a = 10, b = 20;
	//int* p = &a;
	//printf("a�ĵ�ַλ��%p\n", &a);
	//printf("b�ĵ�ַλ��%p\n", &b);
	//printf("a��ֵΪ��%d", *p);
	//printf("sum=%d+%d=%d\n", a,b,add(a,b));
	//register int a = 10;//���齫a����Ϊ�Ĵ�������
	//���������� a?b:c�����AΪ�棬���ΪB��������ΪC
	//int a = 10, b = 20;
	//printf("%d", (a > b) ? a : b);
	//���ű��ʽ���ö����������ı��ʽ
	//int arr[10] = { 0 };
	//int sz = 0;
	////����������ռ�ڴ�
	//printf("%d\n", sizeof(arr));
	////���������Ԫ�ظ���
	//sz = sizeof(arr) / sizeof(arr[0]);
	//printf("%d\n", sz);
	//sizeof���Լ����������ͻ��߱��� ��ռ���ֽ������ӱ�������ʡ�����ţ������Ͳ�����ʡ��
	//��Ŀ��������˫Ŀ����������Ŀ������
	//int a = 1;
	//int b = 0;
	//int c = a & b;//��򣺶�Ӧ�Ķ�����λ��ͬ��Ϊ0����ͬ��Ϊ1
	//b = a << 2;
	//printf("c=%d\n", c);
	//printf("%d\n", b);
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,20 };//�����洢���±����Ԫ��
	//int i = 0;
	//while (i < 10)
	//{
	//	printf("a[%d]=%d\n", i, arr[i]);
	//	i++;
	//}
	//int a = 10, b = 20;
	//printf("��ӵ�ֵ����=%d\n", add(a, b));

	//int i = 0;
	//printf("����ѡ��\n");
	//while (i < 200)
	//{
	//	printf("�ô���������%d\n",i);
	//	i++;
	//}
	//if(i>200)
	//	printf("ok");
	


	//scanf("%d", &i);
	//if (i == 0)
	//	printf("ok\n");
	//else
	//	printf("no\n");
	////\t - ˮƽ�Ʊ����\��������ת��\,\\��ʾ���\
	////ascii����ֵa=97,A=65
	//char arr1[] = "abc";//�ַ����Դ�������־����'\0'�������ַ�����
	//char arr2[] = { 'a','b','c',0 };//��������ַ���������־


	//enum color r = red;
	//enum sex s = male;
	////const �����ԣ����εĳ�����
	//const int num = 8;
	////ö�� enum
	//printf("strlen arr1=%d\n", strlen(arr1));//���������ַ�������
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