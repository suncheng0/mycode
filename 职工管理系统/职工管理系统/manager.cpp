#include"manager.h"
Manager::Manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void Manager::showInfo()
{
	cout << "ְ�����" << this->m_id
		<< "\tְ������" << this->m_name
		<< "\t��λ" << this->getDeptname()
		<< "\t������" << endl;
}
string Manager::getDeptname()
{
	return "����";
}