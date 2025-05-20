#pragma once
#include"device.h"




class Kon
{
public:
	Shebei real[255];//检测系统
	Shebei vir[255];//实际设备

	Kon();
	void Add();//添加一个设备
	void Show1();//显示检测系统所有的设备
	void Show2();//显示实际系统所有的设备
	void Change();//改变一个设备的实际情况
	void Look();//检查某个设备的工作情况
	void Updata();//将实际设备的工作状态更新到检测系统中
	void UpdataG();//更新故障状态到检测系统中
	void ShowG();
	void ShowD();
};


