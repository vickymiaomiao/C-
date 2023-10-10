#define _CRT_SECURE_NO_WARNINGS 1 
#include <string>
#include <iostream>
using namespace std;


/*
* string��C++�����ַ���
* string��char *������
* 1.char *��һ��ָ��
* 2.string��һ���࣬���ڲ���װ��char *,��������ַ�������һ��char *�͵�����
* 
* string�ڲ���װ�˺ܶ��Ա��������find,copy,delete,replace,insert
* 
* ���캯�� :
* string();  Ĭ�Ϲ��죬����һ�����ַ���
* string(const char* s);    ʹ���ַ�����ʼ��
* string(const string& s);    �������캯����ʹ��һ��string�����ʼ����һ��
* string(int n,char c);     ʹ��N���ַ���ʼ�� �ַ���
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
* ��ֵ���� assign  \  =
*/

void test02()
{
	string str1;
	str1 = "hello,vicky";
	cout << str1 << endl;
	//���ַ���str1��ֵ��str2
	string str2;
	str2 = str1;
	cout << str2 << endl;
	//���ַ�a��ֵ��str3
	string str3;
	str3 = 'a';
	cout << str3 << endl;
	//���ַ���s��ֵ��str4
	string str4;
	str4.assign("hello,c++");
	cout << str4 << endl;
	//���ַ�����ǰN���ַ���ֵ��s
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
* �ַ���ƴ��,ʵ����ĩβƴ���ַ��� += / append
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
	//��ǰn���ַ�ƴ�ӵ��ַ���β��
	str3.append("cat", 1);
	cout << str3 << endl;
	//���ַ���Ƭƴ�ӵ�β��
	str3.append(str1);
	cout << str3 << endl;
	//���ַ�����N��λ�����ȡ���ٸ�����ƴ�ӵ�β��
	str3.append(str2, 2, 3);  //��ȡick
	cout << str3 << endl;
	

	
}

/*
* ���Һ��滻
* ���ң�ָ��λ���ַ����Ƿ����
* �滻��ָ��λ���滻�ַ���
*/
void test04()
{
	string str1 = "abcdefgde";
	int pos=str1.find("df");//���س��ֵ�λ�ã�û�з���-1
	if (pos == -1)
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}
	//rfind �� find����
	//rfind�Ǵ���������ң�find�Ǵ������Ҳ�
	pos=str1.rfind("de");
	cout << " rfind pos = " << pos << endl;
	pos = str1.find("de");
	cout << " find pos = " << pos << endl;
	//���ĸ�λ�ÿ�ʼN���ַ��滻Ϊʲô�����ַ���
	str1.replace(1, 3, "1111");//1111�滻bcd
	cout << str1 << endl;
}

/*
* �ַ����Ƚ�
* �ַ�������ASCII����бȽ�   ��Ҫ�����ж������ַ����Ƿ����
* = ����0
* > ����1
* < ����-1
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
	//�������ʽд��
	//str1.compare(str2) >= 0 ? (str1.compare(str2) == 0 ? (cout << "=") : (cout << ">")) : (cout << "<");

}

/*
* �ַ���ȡ
* string�е����ַ���ȡ�ķ�ʽ������
* 1.ͨ��[]
* 2.ͨ��at������ȡ�ַ�
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

	//�޸ĵ����ַ�
	str[0] = 'x';
	cout << str << endl;

	str.at(0) = 'h';
	cout << str << endl;
}

/*
* �����ɾ��
* �����ɾ������ʼ�±궼�Ǵ�0��ʼ
*/
void test07()
{
	string str = "hello";
	//�ӵڼ���λ�ý��в���
	str.insert(1, "xxxx");
	cout << str << endl;
	//���ĸ�λ����ɾ�����ٸ�
	str.erase(1, 4);
	cout << str << endl;

}

/*
* �Ӵ�
* ���ַ����л�ȡ��Ҫ���Ӵ�
* string substr(int pos=0,int n=npos)const;
*/

void test08()
{
	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << subStr << endl;

	//ʵ�ò���
	string email = "vickme@163.com";
	//���ʼ��л�ȡ�û�����Ϣ
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