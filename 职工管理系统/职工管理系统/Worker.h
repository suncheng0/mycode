#pragma once
#include<string>
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:
	virtual void showInfo() = 0;
	virtual string getDeptname() = 0;

	int m_id;
	string m_name;
	int m_deptid;
};
