#include<iostream>
#include<ctime>
using namespace std;
#include"speechManager.h"


int main()
{
	srand((unsigned int)time(NULL));
	SpeechManager sm;
	/*sm.show_Menu();*/
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "ѡ�ֱ��" << it->first << "����" << it->second.m_Name << "����" << it->second.m_Score[0] << endl;
	//}
	
	int choice = 0;
	while (true)
	{
		sm.show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			sm.startSpeech();
			break;
		case 2:
			sm.loadRecord();
			break;
		case 3:
			sm.clearRecord();
			break;
		case 0:
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}