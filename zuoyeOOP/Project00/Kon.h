#pragma once
#include"device.h"




class Kon
{
public:
	Shebei real[255];//���ϵͳ
	Shebei vir[255];//ʵ���豸

	Kon();
	void Add();//���һ���豸
	void Show1();//��ʾ���ϵͳ���е��豸
	void Show2();//��ʾʵ��ϵͳ���е��豸
	void Change();//�ı�һ���豸��ʵ�����
	void Look();//���ĳ���豸�Ĺ������
	void Updata();//��ʵ���豸�Ĺ���״̬���µ����ϵͳ��
	void UpdataG();//���¹���״̬�����ϵͳ��
	void ShowG();
	void ShowD();
};


