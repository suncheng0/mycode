#include"employee.h"
Employee::Employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void Employee::showInfo()
{
	cout << "ְ�����" << this->m_id
		<< "\tְ������" << this->m_name
		<< "\t��λ" << this->getDeptname()
		<< "\tְ��" << endl;
}
string Employee::getDeptname()
{
	return "Ա��";
}