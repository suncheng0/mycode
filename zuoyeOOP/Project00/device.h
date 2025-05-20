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

	GuzhangStatus mGuzahng;//故障状态
	GongzuoStatus mGongzuo;//工作状态
	int Curfault;
	string mCode;//编码
	string mName;//名字
	int mId;//ID
	double mIC;	//阈值		
	double mI;//电流
	double mV;//电压
	bool Isempity;//是否为空
	tm Gu_begin;//故障开始时间
	tm Gu_end;//故障结束时间
	clock_t start,end;//计时
	vector<double> Gu_con;//该设备历次故障持续的时间
	Shebei();//无参构造
	Shebei(string code, string name, int id, double mic);//有参构造（设备固定不变的属性）
	Shebei(Shebei& s);//拷贝构造
	
	string GetCode();
	int GetID(string code);
};
