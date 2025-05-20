#pragma once
#include<string>
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std; 

class Employee :public Worker
{
public:
	Employee(int id,string name,int did);
	virtual void showInfo();
	virtual string getDeptname();
};
