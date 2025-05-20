#include"WorkerManger.h"

WorkerManger::WorkerManger()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if(!ifs.is_open())
	{
		cout << "文件不存在" << endl;
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
		cout << "文件为空" << endl;
		this->m_num = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	int num = this->get_empnum();
	cout << "职工的人数为" << num << endl;
	this->m_num = num;

	this->m_emparray = new Worker * [this->m_num];
	this->init_emp();
	//for (int i = 0; i < this->m_num; i++)
	//{
	//	cout << "职工编号" << this->m_emparray[i]->m_id
	//		<< "姓名" << this->m_emparray[i]->m_name
	//		<< "部门编号" << this->m_emparray[i]->m_deptid << endl;
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
	cout << "菜单" << endl;
}
void WorkerManger::exit_system()
{
	cout << "欢迎下次再使用" << endl;
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
	cout << "请输入添加职工的数量" << endl;
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
			cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个新职工的岗位" << endl;
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
		cout << "成功添加" << addnum << "个新员工" << endl;
		this->m_fileisempty = false;
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
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
		cout << "文件不存在或为空" << endl;
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
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入想要删除的员工编号" << endl;
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
			cout << "删除成功" << endl;

		}
		else
		{
			cout << "删除失败，未找到该员工" << endl;
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
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入修改的编号" << endl;
		int id;
		cin >> id;
		int ret = this->isexist(id);
		if (ret != -1)
		{
			delete this->m_emparray[ret];
			int newid = 0;
			string newname = "";
			int dselect = 0;
			cout << "查到了" << id << "号职工，请输入新的职工号" << endl;
			cin >> newid;
			cout << "请输入新姓名" << endl;
			cin >> newname;
			cout << "请输入新岗位" << endl;
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
			cout << "修改成功" << endl;
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	
	}
	system("pause");
	system("cls");
}
void WorkerManger::find_emp()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入查找方式" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入查找的员工编号" << endl;
			cin >> id;
			int ret = isexist(id);
			if (ret != -1)
			{
				cout << "查找成功信息如下" << endl;
				this->m_emparray[ret]->showInfo();

			}
			else
			{
				cout << "查找失败" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找的姓名" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_num; i++)
			{
				if (name== m_emparray[i]->m_name)
				{
					cout << "判定成功;";
					cout << "查找成功，职工编号为" << this->m_emparray[i]->m_id 
						<< "号员工" << endl;
				 	this->m_emparray[i]->showInfo();
					flag = true;
					
					
				}

			}
			if (flag == false)
			{
				cout << "查找失败" << endl;
			}
		}
		else
		{
			cout << "输入的选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManger::sort_emp()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或为空" << endl;
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
				if (select == 1)//升
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
		cout << "排序成功" << endl;
		this->save();
		this->show_emp();
	}
}void WorkerManger::clean()
{
	cout << "确定清空?" << endl;
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
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}