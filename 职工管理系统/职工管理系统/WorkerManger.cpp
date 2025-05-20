#include"WorkerManger.h"

WorkerManger::WorkerManger()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if(!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->m_num = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_num = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	int num = this->get_empnum();
	cout << "ְ��������Ϊ" << num << endl;
	this->m_num = num;

	this->m_emparray = new Worker * [this->m_num];
	this->init_emp();
	//for (int i = 0; i < this->m_num; i++)
	//{
	//	cout << "ְ�����" << this->m_emparray[i]->m_id
	//		<< "����" << this->m_emparray[i]->m_name
	//		<< "���ű��" << this->m_emparray[i]->m_deptid << endl;
	//}


}
WorkerManger::~WorkerManger()
{
	if (this->m_emparray != NULL)
	{
		delete[] this->m_emparray;
		this->m_emparray = NULL;
	}
}
void WorkerManger::show_Menu()
{
	cout << "�˵�" << endl;
}
void WorkerManger::exit_system()
{
	cout << "��ӭ�´���ʹ��" << endl;
	system("pause");
	exit(0);
}
int WorkerManger::get_empnum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}
void WorkerManger::Add_emp()
{
	cout << "���������ְ��������" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		int newsize = this->m_num + addnum;
		Worker** newspace = new Worker * [newsize];
		if (this->m_emparray != NULL)
		{
			for (int i = 0; i < this->m_num; i++)
			{
				newspace[i] = this->m_emparray[i];
			}
		}
		for (int i = 0; i < addnum; i++)
		{
			int id;

			string name;
			int dselect;
			cout << "�������" << i + 1 << "����ְ���ı��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "����ְ���ĸ�λ" << endl;
			cin >> dselect;

			Worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newspace[this->m_num + i] = worker;
		}
		
		delete[] this->m_emparray;
		this->m_emparray = newspace;
		this->m_num = newsize;
		cout << "�ɹ����" << addnum << "����Ա��" << endl;
		this->m_fileisempty = false;
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}
	
	
	system("pause");
	system("cls");
}
void WorkerManger::save()
{
	ofstream ofs;
	ofs.open(FILENAME , ios::out);
	for (int i = 0; i < m_num; i++)
	{

		ofs << this->m_emparray[i]->m_id<<" "
			<< this->m_emparray[i]->m_name<<" "
			<< this->m_emparray[i]->m_deptid << endl;
	}
	ofs.close();
}
void WorkerManger::init_emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if(did==2)
			worker = new Manager(id, name, did);
		else
			worker = new Boss(id, name, did);
		this->m_emparray[index] = worker;
		index++;
	}
	ifs.close();
}
void WorkerManger::show_emp()
{
	if (this->m_fileisempty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_num; i++)
		{
			this->m_emparray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
void WorkerManger::del_emp()
{
	if (this->m_fileisempty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫɾ����Ա�����" << endl;
		int id = 0;
		cin >> id;
		int index = this->isexist(id);
		if(index!=-1)
		{
			for (int i = index; i < this->m_num - 1; i++)
			{
				this->m_emparray[i] = this->m_emparray[i + 1];
			}
			this->m_num--;
			this->save();
			cout << "ɾ���ɹ�" << endl;

		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���Ա��" << endl;
		}
	}
	system("pause");
	system("cls");
}
int WorkerManger::isexist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_num; i++)
	{
		if (this->m_emparray[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManger::mod_emp()
{
	if (this->m_fileisempty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸ĵı��" << endl;
		int id;
		cin >> id;
		int ret = this->isexist(id);
		if (ret != -1)
		{
			delete this->m_emparray[ret];
			int newid = 0;
			string newname = "";
			int dselect = 0;
			cout << "�鵽��" << id << "��ְ�����������µ�ְ����" << endl;
			cin >> newid;
			cout << "������������" << endl;
			cin >> newname;
			cout << "�������¸�λ" << endl;
			cin >> dselect;
			Worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(newid,newname,dselect);
				break;
			case 2:
				worker = new Manager(newid, newname, dselect);
				break;
			case 3:
				worker = new Boss(newid, newname, dselect);
				break;
			default:
				break;
			}
			this->m_emparray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	
	}
	system("pause");
	system("cls");
}
void WorkerManger::find_emp()
{
	if (this->m_fileisempty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "��������ҵ�Ա�����" << endl;
			cin >> id;
			int ret = isexist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ���Ϣ����" << endl;
				this->m_emparray[ret]->showInfo();

			}
			else
			{
				cout << "����ʧ��" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "��������ҵ�����" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_num; i++)
			{
				if (name== m_emparray[i]->m_name)
				{
					cout << "�ж��ɹ�;";
					cout << "���ҳɹ���ְ�����Ϊ" << this->m_emparray[i]->m_id 
						<< "��Ա��" << endl;
				 	this->m_emparray[i]->showInfo();
					flag = true;
					
					
				}

			}
			if (flag == false)
			{
				cout << "����ʧ��" << endl;
			}
		}
		else
		{
			cout << "�����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManger::sort_emp()
{
	if (this->m_fileisempty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "sheng1  jiang2" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_num; i++)
		{
			int minormax = i;
			for (int j = i + 1; j < this->m_num; j++)
			{
				if (select == 1)//��
				{
					if (this->m_emparray[minormax]->m_id > this->m_emparray[j]->m_id)
					{
						minormax = j;
					}
				}
				else
				{
					if (this->m_emparray[minormax]->m_id < this->m_emparray[j]->m_id)
					{
						minormax = j;
					}
				}	
			}
			if (i != minormax)
			{
				Worker* temp = this->m_emparray[i];
				this->m_emparray[i] = this->m_emparray[minormax];
				this->m_emparray[minormax] = temp;
			}
		}
		cout << "����ɹ�" << endl;
		this->save();
		this->show_emp();
	}
}void WorkerManger::clean()
{
	cout << "ȷ�����?" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_emparray!= NULL)
		{
			for (int i = 0; i < this->m_num; i++)
			{
				delete this->m_emparray[i];
				this->m_emparray[i] = NULL;
			}
			delete[] this->m_emparray;
			this->m_emparray = NULL;
			this->m_num = 0;
			this->m_fileisempty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}