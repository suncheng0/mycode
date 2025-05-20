#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<vector>
using namespace std;

enum GongzuoStatus { Tingji, Daiji, Gongzuo };
enum GuzhangStatus { Zhengchang, Guzhang,Cuowu };

class Shebei
{
public:

	GuzhangStatus mGuzahng;//����״̬
	GongzuoStatus mGongzuo;//����״̬
	int Curfault;
	string mCode;//����
	string mName;//����
	int mId;//ID
	double mIC;	//��ֵ		
	double mI;//����
	double mV;//��ѹ
	bool Isempity;//�Ƿ�Ϊ��
	tm Gu_begin;//���Ͽ�ʼʱ��
	tm Gu_end;//���Ͻ���ʱ��
	clock_t start,end;//��ʱ
	vector<double> Gu_con;//���豸���ι��ϳ�����ʱ��
	Shebei();//�޲ι���
	Shebei(string code, string name, int id, double mic);//�вι��죨�豸�̶���������ԣ�
	Shebei(Shebei& s);//��������
	
	string GetCode();
	int GetID(string code);
};
