#include"kon.h"

Kon::Kon()
{
	int len = sizeof(vir) / sizeof(vir[0]);
	for (int i = 0; i < len; i++)
	{
		Shebei kong("NULL", "�հ�", NULL, NULL);
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
	bool repid=0;//��֤����ӵ��豸ID�Ƿ��������豸�ظ��ı�־λ
	bool repcode = 0;//��֤����ӵ��豸code�Ƿ��������豸�ظ��ı�־λ
	cout << "�������ţ�������id����ֵ,��������ѹ������״̬" << endl;
	cout << "��ţ�"; cin >> code;
	cout << "������"; cin >> name;
	cout << "id��(ӦΪ1��255������)"; cin >> id;
	cout << "��ֵ��"; cin>> mic;
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
		cout << "ID�������豸�ظ����޷����" << endl;
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
		cout << "code�������豸�ظ����޷����" << endl;
		return;
	}
	cout << "���������״̬:(0Ϊ������1Ϊ����)��";
	int m;
	cin >> m;
	if (m != 0 && m != 1)
	{
		cout << "����!���ݴ����޷�����豸" << endl;
		return;
	}
	Shebei* p1 = new Shebei(code, name, id, mic);
	this->real[id-1] = *p1;
	Shebei* p2 = new Shebei(*p1);
	this->vir[id-1] = *p2;
	cout << "������";cin >> real[id-1].mI; vir[id-1].mI = real[id-1].mI;
	cout << "��ѹ��"; cin >> real[id-1].mV; vir[id-1].mV = real[id-1].mV;

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
	bool emp = 0;//�ж��Ƿ�Ϊ�յı�־
	int j = 0;
	for (j = 0; j < len; j++)
	{
		if (vir[j].Isempity == 1)
			emp = 1;
	}
	if (emp == 0)
	{
		cout << "���ϵͳ��û���豸" << endl;
		return;
	}
	else
	{
		cout << "���ϵͳ�ڼ�¼�����豸���£�" << endl;
		for (int i = 0; i < len; i++)
		{
			if (vir[i].Isempity == 0)
			{
				continue;
			}
			else
			{
				cout << "��ţ�" << vir[i].mCode <<"\t"
				<< "������" << vir[i].mName << "\t"
				<< "ID��" << vir[i].mId << "\t"
				<< "������ֵ��" << vir[i].mIC << "\t"
				<< "��ѹ��" << vir[i].mV << "\t"
				<< "������" << vir[i].mI << "\t"
				<< "����״̬��" << vir[i].mGuzahng << "\t"
				<< endl;
			}
		}
	}

}
void Kon::Show2()
{
	int len = sizeof(real) / sizeof(real[0]);
	bool emp=0;//�ж��Ƿ�Ϊ�յı�־
	int j=0;
	for (j=0; j < len; j++)
	{
		if (real[j].Isempity == 1)
			emp = 1;
	}
	if (emp==0)
	{
		cout << "�ֳ�û���豸" << endl;
		return;
	}
	else
	{
		cout << "�ֳ�ʵ���豸���£�" << endl;
		for (int i = 0; i < len; i++)
		{
			if (real[i].Isempity == 0)
			{
				continue;
			}
			else
			{
				cout << "���룺 " << real[i].mCode << "\t"
				<< "����" << real[i].mName << "\t"
				<< "ID" << real[i].mId << "\t"
				<< "������ֵ" << real[i].mIC << "\t"
				<< "��ѹ" << real[i].mV << "\t"
				<< "����" << real[i].mI << "\t"
				<< "����״̬" << real[i].mGuzahng << "\t"
				<< endl;
			}
		
		}
	}
}
void Kon::Change()
{
	int id;
	cout << "����������Ҫ�ı���豸ID" << endl;
	cin >> id;
	if (real[id-1].Isempity==0)
	{
		cout << "��IDλ�û�û���豸���޷�����" << endl;
		return;
	}
	else
	{
	cout << "�����ʱ�Ĺ���״̬ 0Ϊ������1Ϊ���ϣ����������ݴ���"<<endl;
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
	cout << "���������ѹ������"<<endl;
	cin >> real[id-1].mI >> real[id-1].mV;
	cout << "���ĳɹ�" << endl;
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
			//cout << "�հ�" << endl;
		}
		else if (real[i].mI == 0)
		{
			real[i].mGongzuo = Tingji;
			cout << "ͣ��" << endl;
		}
		else if (real[i].mI < real[i].mIC)
		{
			real[i].mGongzuo = Daiji;
			cout << "����" << endl;
		}
		else
		{
			real[i].mGongzuo = Gongzuo;
			cout << "����" << endl;
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
			//cout << "�հ�" << endl;
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
			cout << "IDΪ"<<i+1<<"���豸���������" << endl;
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
			//cout << "�հ�" << endl;
			continue;
		}
		else
		{
			if (real[i].mGuzahng == Cuowu)
			{
				cout << "���棡IDΪ" << i + 1 << "���豸��־λ����" << endl;
				vir[i].mGuzahng = Cuowu;
			}
			else if (real[i].mGuzahng == Zhengchang)
			{
				if (vir[i].mGuzahng == Zhengchang)
				{
				cout << "IDΪ"<<i+1<<"���豸�ڼ��ϵͳ�к�ʵ���豸�������������޸�" << endl;
				}
				else
				{
				cout << "IDΪ" << i + 1 << "���豸�Ѿ��ɹ��ϻָ��������Ѹ��������ϵͳ,";
				vir[i].mGuzahng = Zhengchang;

				time_t now;
				time(&now);
				struct tm t;
				localtime_s(&t, &now);
				vir[i].Gu_end = t;
				vir[i].end = clock();
				cout << "���Ͻ�����ʱ��Ϊ:"
				<< t.tm_year + 1900<<"��"
				<< t.tm_mon + 1<< "��"
				<< t.tm_mday << "��"
				<< t.tm_hour<< "ʱ"
				<< t.tm_min<< "��"
				<< t.tm_sec << "��"<< " ";
				double con = double(this->vir[i].end - this->vir[i].start)/ CLOCKS_PER_SEC;
				vir[i].Gu_con.push_back(con);
				cout << "���豸�˴ι�������" << con << "��" << endl;
				}
			}
			else
			{
				if(vir[i].mGuzahng == Zhengchang)
				{
					cout << "IDΪ" << i + 1 << "���豸�������������ϣ��Ѹ��������ϵͳ,";
					vir[i].mGuzahng = Guzhang;
					//��ʾ���ϵ�����
					time_t now;
					time(&now);
					struct tm t;
					localtime_s(&t, &now);
					vir[i].Gu_begin = t;
					vir[i].start = clock();
					cout << "���Ͽ�ʼ��ʱ��Ϊ" 
					<< t.tm_year + 1900 << "��"
					<< t.tm_mon + 1 << "��"
					<< t.tm_mday << "��"
					<< t.tm_hour << "ʱ"
					<< t.tm_min << "��"
					<< t.tm_sec << "��" << endl;

				}
				else
				{
				cout << "IDΪ" << i + 1 << "���豸�ڼ��ϵͳ�к�ʵ���豸�����ϣ������޸�" << endl;
				}
			}
		}
	}
}
void Kon::ShowG()
{
	//ע�⣬����ID��1���豸��vir[0]
	int len = sizeof(vir) / sizeof(vir[0]);
	string index_code;
	cout << "����������鿴���豸���" << endl;
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
		cout <<"��"<<i << "�ι��ϳ���ʱ��Ϊ" << endl;
		cout << *it <<"��"<< endl;
	}
	cout << "�������" << endl;
}
void Kon::ShowD()
{
	int len = sizeof(vir) / sizeof(vir[0]);
	string index_code;
	cout << "����������鿴���豸���" << endl;
	cin >> index_code;
	int index;
	for (int j = 0; j < len; j++)
	{
		if (real[j].mCode == index_code)
		{
			index = vir[j].GetID(index_code);
		}
	}
	cout << "���豸��������£�" << endl;
	cout << "�豸���ƣ�" << real[index - 1].mName << endl;
	cout << "״̬��ֵ��" << real[index - 1].mIC << endl;
	cout << "����״̬��";
	if (real[index - 1].mI > real[index - 1].mIC)
	{
		cout << "����" << endl;
	}
	else if (real[index - 1].mI < real[index - 1].mIC&& real[index - 1].mI!=0)
	{
		cout << "����" << endl;
	}
	else
	{
		cout << "ͣ��" << endl;

	}
	cout << "����״̬��";
	if (real[index - 1].mGuzahng == Guzhang)
	{
		cout << "����" << endl;
	}
	else if (real[index - 1].mGuzahng == Zhengchang)
	{
		cout << "����" << endl;
	}
	else
	{
		cout << "����" << endl;
	}
}

