#include"boss.h"
Boss::Boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void Boss::showInfo()
{
	cout << "ְ�����" << this->m_id
		<< "\tְ������" << this->m_name
		<< "\t��λ" << this->getDeptname()
		<< "\t�ϴ�" << endl;
}
string Boss::getDeptname()
{
	return "�ϰ�";
}