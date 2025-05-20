#include"kon.h"
int main()
{
	Kon k;
	int index=0;
	
	while (1)
	{
		cout << "*************************************************" << endl;
		cout << "*\t1、添加设备并将初始状态录入检测系统中\t*" << endl;
		cout << "*\t2、查看检测系统所有设备状态\t\t*" << endl;
		cout << "*\t3、查看现场系统所有设备状态\t\t*" << endl;
		cout << "*\t4、改变某现场系统的电压，电流和故障状态\t*" << endl;
		cout << "*\t5、进行一轮工作状态检测\t\t\t*" << endl;
		cout << "*\t6、进行一轮电流，电压状态数据采集\t*" << endl;//（将实际设备的各信息更新到检测系统中）
		cout << "*\t7、进行一轮故障状态采集\t\t\t*" << endl;
		cout << "*\t8、按编号查看某设备的各信息\t\t*" << endl;
		cout << "*\t9、按编号查看某设备的故障记录\t\t*" << endl;
		cout << "*\t10、退出系统\t\t\t\t*" << endl;
		cout << "*************************************************" << endl<<endl<<endl;
		cout << "请输入您的选择（数字）" << endl;
		cin >> index;
		//还差把按id查询换成按编号查询，然后能查询的记录再加一些
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