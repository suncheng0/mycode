#include"kon.h"

Kon::Kon()
{
	int len = sizeof(vir) / sizeof(vir[0]);
	for (int i = 0; i < len; i++)
	{
		Shebei kong("NULL", "空白", NULL, NULL);
		kong.mI = -1;
		kong.mV = -1;
		kong.mGuzahng = Zhengchang;
		kong.mGongzuo = Tingji;
		kong.Isempity = 0;
		real[i] = kong;
		vir[i] = kong;
	}
}
void Kon::Add()
{
	string code;
	string name;
	int id;
	double mic;
	bool repid=0;//验证新添加的设备ID是否与现有设备重复的标志位
	bool repcode = 0;//验证新添加的设备code是否与现有设备重复的标志位
	cout << "请输入编号，姓名，id，阈值,电流，电压，故障状态" << endl;
	cout << "编号："; cin >> code;
	cout << "姓名："; cin >> name;
	cout << "id：(应为1到255的整数)"; cin >> id;
	cout << "阈值："; cin>> mic;
	int len = sizeof(vir) / sizeof(vir[0]);
	for (int i = 0; i <len; i++)//
	{
		if (vir[i].mId == id)
		{
			repid = 1;
		}
	}
	if (repid == 1)
	{
		cout << "ID与现有设备重复，无法添加" << endl;
		return;
	}
	for (int i = 0; i < len; i++)//
	{
		if (vir[i].mCode == code)
		{
			repcode = 1;
		}
	}
	if (repcode == 1)
	{
		cout << "code与现有设备重复，无法添加" << endl;
		return;
	}
	cout << "请输入故障状态:(0为正常，1为故障)：";
	int m;
	cin >> m;
	if (m != 0 && m != 1)
	{
		cout << "警告!数据错误，无法添加设备" << endl;
		return;
	}
	Shebei* p1 = new Shebei(code, name, id, mic);
	this->real[id-1] = *p1;
	Shebei* p2 = new Shebei(*p1);
	this->vir[id-1] = *p2;
	cout << "电流：";cin >> real[id-1].mI; vir[id-1].mI = real[id-1].mI;
	cout << "电压："; cin >> real[id-1].mV; vir[id-1].mV = real[id-1].mV;

	if (m == 0)
	{
		vir[id-1].mGuzahng=real[id-1].mGuzahng = Zhengchang;
	}
	else
	{
		vir[id-1].mGuzahng = real[id-1].mGuzahng = Guzhang;
		vir[id-1].start = clock();
	}
	
	real[id-1].Isempity = 1;
	vir[id-1].Isempity = 1;

}
void Kon::Show1()
{
	int len = sizeof(vir) / sizeof(vir[0]);
	bool emp = 0;//判断是否为空的标志
	int j = 0;
	for (j = 0; j < len; j++)
	{
		if (vir[j].Isempity == 1)
			emp = 1;
	}
	if (emp == 0)
	{
		cout << "检测系统里没有设备" << endl;
		return;
	}
	else
	{
		cout << "检测系统内记录到的设备如下：" << endl;
		for (int i = 0; i < len; i++)
		{
			if (vir[i].Isempity == 0)
			{
				continue;
			}
			else
			{
				cout << "编号：" << vir[i].mCode <<"\t"
				<< "姓名：" << vir[i].mName << "\t"
				<< "ID：" << vir[i].mId << "\t"
				<< "电流阈值：" << vir[i].mIC << "\t"
				<< "电压：" << vir[i].mV << "\t"
				<< "电流：" << vir[i].mI << "\t"
				<< "故障状态：" << vir[i].mGuzahng << "\t"
				<< endl;
			}
		}
	}

}
void Kon::Show2()
{
	int len = sizeof(real) / sizeof(real[0]);
	bool emp=0;//判断是否为空的标志
	int j=0;
	for (j=0; j < len; j++)
	{
		if (real[j].Isempity == 1)
			emp = 1;
	}
	if (emp==0)
	{
		cout << "现场没有设备" << endl;
		return;
	}
	else
	{
		cout << "现场实际设备如下：" << endl;
		for (int i = 0; i < len; i++)
		{
			if (real[i].Isempity == 0)
			{
				continue;
			}
			else
			{
				cout << "编码： " << real[i].mCode << "\t"
				<< "姓名" << real[i].mName << "\t"
				<< "ID" << real[i].mId << "\t"
				<< "电流阈值" << real[i].mIC << "\t"
				<< "电压" << real[i].mV << "\t"
				<< "电流" << real[i].mI << "\t"
				<< "故障状态" << real[i].mGuzahng << "\t"
				<< endl;
			}
		
		}
	}
}
void Kon::Change()
{
	int id;
	cout << "请输入您想要改变的设备ID" << endl;
	cin >> id;
	if (real[id-1].Isempity==0)
	{
		cout << "此ID位置还没有设备，无法更改" << endl;
		return;
	}
	else
	{
	cout << "输入此时的故障状态 0为正常，1为故障，其余是数据错误"<<endl;
	int m;
	cin >> m;
	if (m == 0)
	{
		real[id-1].mGuzahng = Zhengchang;
	}
	else if (m == 1)
	{
		real[id-1].mGuzahng = Guzhang;
	}
	else
	{
		
		real[id - 1].mGuzahng = Cuowu;
		return;
	}
	cout << "依次输入电压，电流"<<endl;
	cin >> real[id-1].mI >> real[id-1].mV;
	cout << "更改成功" << endl;
	}
}
void Kon::Look()
{
	int len = sizeof(vir) / sizeof(vir[0]);
	for (int i = 0; i < len; i++)
	{
		if (real[i].mCode == "NULL")
		{
			continue;
			//cout << "空白" << endl;
		}
		else if (real[i].mI == 0)
		{
			real[i].mGongzuo = Tingji;
			cout << "停机" << endl;
		}
		else if (real[i].mI < real[i].mIC)
		{
			real[i].mGongzuo = Daiji;
			cout << "待机" << endl;
		}
		else
		{
			real[i].mGongzuo = Gongzuo;
			cout << "工作" << endl;
		}
	}	
}
void Kon::Updata()
{
	int len = sizeof(vir) / sizeof(vir[0]);
	for (int i = 0; i < len; i++)
	{
		if (real[i].mCode == "NULL")
		{
			continue;
			//cout << "空白" << endl;
		}
		else
		{
			vir[i].Isempity = real[i].Isempity;
			vir[i].mI = real[i].mI;
			vir[i].mIC = real[i].mIC;
			vir[i].mV = real[i].mV;
			vir[i].mId = real[i].mId;
			vir[i].mName = real[i].mName;
			vir[i].mGongzuo = real[i].mGongzuo;
			cout << "ID为"<<i+1<<"的设备检测更新完成" << endl;
		}
		
	}
}
void Kon::UpdataG()
{
	int len = sizeof(vir) / sizeof(vir[0]);
	for (int i = 0; i < len; i++)
	{
		if (real[i].Isempity == 0)
		{
			//cout << "空白" << endl;
			continue;
		}
		else
		{
			if (real[i].mGuzahng == Cuowu)
			{
				cout << "警告！ID为" << i + 1 << "的设备标志位出错" << endl;
				vir[i].mGuzahng = Cuowu;
			}
			else if (real[i].mGuzahng == Zhengchang)
			{
				if (vir[i].mGuzahng == Zhengchang)
				{
				cout << "ID为"<<i+1<<"的设备在检测系统中和实际设备均正常，无需修改" << endl;
				}
				else
				{
				cout << "ID为" << i + 1 << "的设备已经由故障恢复正常，已更新至检测系统,";
				vir[i].mGuzahng = Zhengchang;

				time_t now;
				time(&now);
				struct tm t;
				localtime_s(&t, &now);
				vir[i].Gu_end = t;
				vir[i].end = clock();
				cout << "故障结束的时间为:"
				<< t.tm_year + 1900<<"年"
				<< t.tm_mon + 1<< "月"
				<< t.tm_mday << "日"
				<< t.tm_hour<< "时"
				<< t.tm_min<< "分"
				<< t.tm_sec << "秒"<< " ";
				double con = double(this->vir[i].end - this->vir[i].start)/ CLOCKS_PER_SEC;
				vir[i].Gu_con.push_back(con);
				cout << "该设备此次共故障了" << con << "秒" << endl;
				}
			}
			else
			{
				if(vir[i].mGuzahng == Zhengchang)
				{
					cout << "ID为" << i + 1 << "的设备由正常发生故障，已更新至检测系统,";
					vir[i].mGuzahng = Guzhang;
					//显示故障的日期
					time_t now;
					time(&now);
					struct tm t;
					localtime_s(&t, &now);
					vir[i].Gu_begin = t;
					vir[i].start = clock();
					cout << "故障开始的时间为" 
					<< t.tm_year + 1900 << "年"
					<< t.tm_mon + 1 << "月"
					<< t.tm_mday << "日"
					<< t.tm_hour << "时"
					<< t.tm_min << "分"
					<< t.tm_sec << "秒" << endl;

				}
				else
				{
				cout << "ID为" << i + 1 << "的设备在检测系统中和实际设备均故障，无需修改" << endl;
				}
			}
		}
	}
}
void Kon::ShowG()
{
	//注意，这里ID是1的设备是vir[0]
	int len = sizeof(vir) / sizeof(vir[0]);
	string index_code;
	cout << "请输入您想查看的设备编号" << endl;
	cin >> index_code;
	int index;
	for (int j = 0; j < len; j++)
	{
		if (vir[j].mCode == index_code)
		{
			index = vir[j].GetID(index_code);
		}
	}
	int i = 1;
	for (vector<double>::iterator it = vir[index-1].Gu_con.begin(); it != vir[index-1].Gu_con.end(); it++)
	{
		cout <<"第"<<i << "次故障持续时间为" << endl;
		cout << *it <<"秒"<< endl;
	}
	cout << "检索完成" << endl;
}
void Kon::ShowD()
{
	int len = sizeof(vir) / sizeof(vir[0]);
	string index_code;
	cout << "请输入您想查看的设备编号" << endl;
	cin >> index_code;
	int index;
	for (int j = 0; j < len; j++)
	{
		if (real[j].mCode == index_code)
		{
			index = vir[j].GetID(index_code);
		}
	}
	cout << "该设备的情况如下：" << endl;
	cout << "设备名称：" << real[index - 1].mName << endl;
	cout << "状态阈值：" << real[index - 1].mIC << endl;
	cout << "工作状态：";
	if (real[index - 1].mI > real[index - 1].mIC)
	{
		cout << "工作" << endl;
	}
	else if (real[index - 1].mI < real[index - 1].mIC&& real[index - 1].mI!=0)
	{
		cout << "待机" << endl;
	}
	else
	{
		cout << "停机" << endl;

	}
	cout << "故障状态：";
	if (real[index - 1].mGuzahng == Guzhang)
	{
		cout << "故障" << endl;
	}
	else if (real[index - 1].mGuzahng == Zhengchang)
	{
		cout << "正常" << endl;
	}
	else
	{
		cout << "错误" << endl;
	}
}

