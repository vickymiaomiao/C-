#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#include "speaker.h"

//��Ʊ���������
class SpeechManager
{
public:
	//���캯��
	SpeechManager();
	//չʾ�˵�
	void show_Menu();

	//�˳�app
	void exitSystem();


	
	//����ѡ�� ���� 12��  ���
	vector<int>v1;
	//�ڶ��ֽ������� 6��
	vector<int>v2;
	//ǰ����
	vector<int>vv;
	//��ű���Լ���Ӧ�ľ���ѡ�� ����
	map<int, Speaker> m_s;

	//��¼��������
	int m_Index;

	//��ʼ������
	void initSpeech();

	//����ѡ��
	void creatSpeaker();

	//��������
	~SpeechManager();



};