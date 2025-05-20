#pragma once
#include<string>
#include<iostream>
#include<string>
using namespace std;
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

class WorkerManger
{
public:
	WorkerManger();
	~WorkerManger();
	void show_Menu();
	void exit_system();
	int m_num;
	Worker** m_emparray;
	void Add_emp();
	void save();
	bool m_fileisempty;
	int get_empnum();
	void init_emp();
	void show_emp();
	void del_emp();
	int isexist(int id);
	void mod_emp();
	void find_emp();
	void sort_emp();
	void clean();
};
