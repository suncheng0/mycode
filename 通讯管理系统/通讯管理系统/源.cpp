#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
struct person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;

};

struct book
{
	person personarray[MAX];
	int m_size;
};
//添加
void addperson(book* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "通讯录满了" << endl;
		return;
	}
	else 
	{
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;
		//性别
		cout << "请输入性别，1是男，2是女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[abs->m_size].m_age = age;
		//电话
		cout << "请输入电话" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;
		//住址
		cout << "请输入住址" << endl;
		string add;
		cin >> add;
		abs->personarray[abs->m_size].m_addr = add;

		abs->m_size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
//显示
void showperson(book* abs)
{
	if (abs->m_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名" << abs->personarray[i].m_name << '\t';
			cout << "性别" << (abs->personarray[i].m_sex ==1?"男":"女") << '\t';
			cout << "年龄" << abs->personarray[i].m_age << '\t';
			cout << "电话" << abs->personarray[i].m_phone << '\t';
			cout << "住址" << abs->personarray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");

}

int isexist(book* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personarray[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}

//删除
void delectperson(book* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//查找
void findperson(book* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "姓名" << abs->personarray[ret].m_name << "\t";
		cout << "性别" << abs->personarray[ret].m_sex  << '\t';
		cout << "年龄" << abs->personarray[ret].m_age << '\t';
		cout << "电话" << abs->personarray[ret].m_phone << '\t';
		cout << "住址" << abs->personarray[ret].m_addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//修改
void changeperson(book* abs)
{
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "请输入姓名" << endl;
		string name;
		cin >> name;
		abs->personarray[ret].m_name = name;

		cout << "请输入性别,1是男,2是女" << endl;
		int sex = 0;
		
		while (true)
		{
			cin >> sex;
			if(sex==1||sex==2)
			{
				abs->personarray[ret].m_sex = sex;
				break;
			}
			cout << "输入有误";
		}
		cout << "年龄" << endl;
		int age;
		cin >> age;
		abs->personarray[ret].m_age = age;
		cout << "电话" << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;
		cout << "地址" << endl;
		string addr;
		cin >> addr;
		abs->personarray[ret].m_addr = addr;

		cout << "修改成功" << endl;

	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//清空
void cleanperson(book* abs)
{
	abs->m_size = 0;
	cout << "已清空" << endl;
	system("pause");
	system("cls");
}
//菜单
void showMenu()
{
	cout << "1 添加联系人" << endl;
	cout << "2 显示联系人" << endl;
	cout << "3 删除联系人" << endl;
	cout << "4 查找联系人" << endl;
	cout << "5 修改联系人" << endl;
	cout << "6 清空联系人" << endl;
	cout << "0 退出" << endl;
}

int main()
{
	book abs;
	abs.m_size = 0;
	int select = 0;
	
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&abs);
			break;
		case 2:
			showperson(&abs);
			break;
		case 3:
		{
			/*cout << "请输入姓名" << endl;
			string name;
			cin >> name;
			if (isexist(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{

			}*/
			delectperson(&abs);
			break;
		}
		case 4:
			findperson(&abs);
			break;
		case 5:
			changeperson(&abs);
			break;
		case 6:
			cleanperson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用";
			system("pause");
			return 0;
			break;
		default:
			break;
	}
	}


	system("pause");
	return 0;
}