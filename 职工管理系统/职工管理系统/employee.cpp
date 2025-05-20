#include"employee.h"
Employee::Employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void Employee::showInfo()
{
	cout << "职工编号" << this->m_id
		<< "\t职工姓名" << this->m_name
		<< "\t岗位" << this->getDeptname()
		<< "\t职责" << endl;
}
string Employee::getDeptname()
{
	return "员工";
}