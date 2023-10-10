#define _CRT_SECURE_NO_WARNINGS 1   
#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//�вι���
	MyArray(int capacity)
	{
		//cout << "�вι���" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];//����������������
	}
	//�������캯��
	MyArray(const MyArray& arr)
	{
		//cout << "��������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//�����������
		this->pAddress=new T[arr.m_Capacity];
		//��arr�е����ݶ�copy����
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator=  ��ֹǳ�������� ���������
	MyArray& operator=(const MyArray& arr)  //����������������=
	{
		//cout << "operator=" << endl;
		//���ж�ԭ�������Ƿ������ݣ��еĻ����ͷ�
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//�����������
		this->pAddress = new T[arr.m_Capacity];
		//��arr�е����ݶ�copy����
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//β�巨
	void Push_Back(const T &val)
	{
		//�ж������Ƿ���ڴ�С
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;  //����ĩβ��������
		this->m_Size++;//���������С
	}
	//βɾ����
	void Pop_Back()
	{
		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ���߼��ϵ�ɾ��
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}
	//ͨ���±귽ʽ����Ԫ��  ��������ķ�����Ҫ��Ϊ��������ֵ���ڣ���Ҫ��������
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	//�������������
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//���������С
	int getSize()
	{
		return this->m_Size;
	}

	//�������� �ͷŶ�������
	~MyArray()
	{
		//cout << "����" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T* pAddress; //ָ��ָ��������ٵ���ʵ������
	int m_Capacity;   //��������
	int m_Size;    //�����С

};