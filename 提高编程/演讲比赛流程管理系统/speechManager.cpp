#include "speechManager.h"

SpeechManager::SpeechManager()
{

}

//չʾ�˵�
void SpeechManager::show_Menu()
{
	cout << "--------------------------------------" << endl;
	cout << "--- welcome to the speech contest-----" << endl;
	cout << "---------1.opening speech ------------" << endl;
	cout << "---------2.view past records ---------" << endl;
	cout << "---------3.clear the record-----------" << endl;
	cout << "---------0.quit app-------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << endl;
}

//�˳�����
void SpeechManager::exitSystem()
{
	cout << "welcome next use" << endl;
	system("pause");
	exit(0);
}


SpeechManager::~SpeechManager()
{

}
