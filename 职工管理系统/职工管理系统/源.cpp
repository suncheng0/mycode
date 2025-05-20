#include"WorkerManger.h"
#include"Worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
int main()
{
	WorkerManger wm;
	int choice = 0;
	while (1)
	{
		wm.show_Menu();
		cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exit_system();
			break;
		case 1:
			wm.Add_emp();
			break;
		case 2:
			wm.show_emp();
			break;
		case 3:
			wm.del_emp();
			break;
		case 4:
			wm.mod_emp();
			break;
		case 5:
			wm.find_emp();
			break;
		case 6:
			wm.sort_emp();
			break;
		case 7:
			wm.clean();
			break;
		default:
			system("cls");
			break;
		}

	}
	
	system("pause");
	return 0;
}