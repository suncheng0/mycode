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
//���
void addperson(book* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else 
	{
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;
		//�Ա�
		cout << "�������Ա�1���У�2��Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "����������" << endl;
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[abs->m_size].m_age = age;
		//�绰
		cout << "������绰" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;
		//סַ
		cout << "������סַ" << endl;
		string add;
		cin >> add;
		abs->personarray[abs->m_size].m_addr = add;

		abs->m_size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
//��ʾ
void showperson(book* abs)
{
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "����" << abs->personarray[i].m_name << '\t';
			cout << "�Ա�" << (abs->personarray[i].m_sex ==1?"��":"Ů") << '\t';
			cout << "����" << abs->personarray[i].m_age << '\t';
			cout << "�绰" << abs->personarray[i].m_phone << '\t';
			cout << "סַ" << abs->personarray[i].m_addr << endl;
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

//ɾ��
void delectperson(book* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
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
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//����
void findperson(book* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "����" << abs->personarray[ret].m_name << "\t";
		cout << "�Ա�" << abs->personarray[ret].m_sex  << '\t';
		cout << "����" << abs->personarray[ret].m_age << '\t';
		cout << "�绰" << abs->personarray[ret].m_phone << '\t';
		cout << "סַ" << abs->personarray[ret].m_addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�޸�
void changeperson(book* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "����������" << endl;
		string name;
		cin >> name;
		abs->personarray[ret].m_name = name;

		cout << "�������Ա�,1����,2��Ů" << endl;
		int sex = 0;
		
		while (true)
		{
			cin >> sex;
			if(sex==1||sex==2)
			{
				abs->personarray[ret].m_sex = sex;
				break;
			}
			cout << "��������";
		}
		cout << "����" << endl;
		int age;
		cin >> age;
		abs->personarray[ret].m_age = age;
		cout << "�绰" << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;
		cout << "��ַ" << endl;
		string addr;
		cin >> addr;
		abs->personarray[ret].m_addr = addr;

		cout << "�޸ĳɹ�" << endl;

	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//���
void cleanperson(book* abs)
{
	abs->m_size = 0;
	cout << "�����" << endl;
	system("pause");
	system("cls");
}
//�˵�
void showMenu()
{
	cout << "1 �����ϵ��" << endl;
	cout << "2 ��ʾ��ϵ��" << endl;
	cout << "3 ɾ����ϵ��" << endl;
	cout << "4 ������ϵ��" << endl;
	cout << "5 �޸���ϵ��" << endl;
	cout << "6 �����ϵ��" << endl;
	cout << "0 �˳�" << endl;
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
			/*cout << "����������" << endl;
			string name;
			cin >> name;
			if (isexist(&abs, name) == -1)
			{
				cout << "���޴���" << endl;
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
			cout << "��ӭ�´�ʹ��";
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