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

	//�ļ�Ϊ�յı�־
	bool fileIsEmpty;

	//�����¼
	map<int, vector<string>> m_Record;


	//��ȡ��¼
	void loadRecord();


	//��ʼ������
	void initSpeech();

	//����ѡ��
	void creatSpeaker();

	//��ʼ����
	void startSpeach();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�������
	void showScore();

	//�������
	void saveRecord();

	//��ʾ����÷�
	void showRecord();

	//��ռ�¼
	void clearRecord();


	//��������
	~SpeechManager();



};