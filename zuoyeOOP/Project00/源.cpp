#include"kon.h"
int main()
{
	Kon k;
	int index=0;
	
	while (1)
	{
		cout << "*************************************************" << endl;
		cout << "*\t1������豸������ʼ״̬¼����ϵͳ��\t*" << endl;
		cout << "*\t2���鿴���ϵͳ�����豸״̬\t\t*" << endl;
		cout << "*\t3���鿴�ֳ�ϵͳ�����豸״̬\t\t*" << endl;
		cout << "*\t4���ı�ĳ�ֳ�ϵͳ�ĵ�ѹ�������͹���״̬\t*" << endl;
		cout << "*\t5������һ�ֹ���״̬���\t\t\t*" << endl;
		cout << "*\t6������һ�ֵ�������ѹ״̬���ݲɼ�\t*" << endl;//����ʵ���豸�ĸ���Ϣ���µ����ϵͳ�У�
		cout << "*\t7������һ�ֹ���״̬�ɼ�\t\t\t*" << endl;
		cout << "*\t8������Ų鿴ĳ�豸�ĸ���Ϣ\t\t*" << endl;
		cout << "*\t9������Ų鿴ĳ�豸�Ĺ��ϼ�¼\t\t*" << endl;
		cout << "*\t10���˳�ϵͳ\t\t\t\t*" << endl;
		cout << "*************************************************" << endl<<endl<<endl;
		cout << "����������ѡ�����֣�" << endl;
		cin >> index;
		//����Ѱ�id��ѯ���ɰ���Ų�ѯ��Ȼ���ܲ�ѯ�ļ�¼�ټ�һЩ
		switch (index)
		{
		case 1:
			k.Add();
			system("pause");
			system("cls");
			break;
		case 2:
			k.Show1();
			system("pause");
			system("cls");
			break;
		case 3:
			k.Show2();
			system("pause");
			system("cls");
			break;

		case 4:
			k.Change();
			system("pause");
			system("cls");
			break;
		case 5:
			k.Look();
			system("pause");
			system("cls");
			break;
		case 6:
			k.Updata();
			system("pause");
			system("cls");
			break;
		case 7:
			k.UpdataG();
			system("pause");
			system("cls");
			break;
		case 8:
			k.ShowD();
			system("pause");
			system("cls");
			break;
		case 9:
			k.ShowG();
			system("pause");
			system("cls");
			break;
		case 10:
			exit(0);
			break;
		}
	}
	
	
	system("pause");
	system("cls");
}