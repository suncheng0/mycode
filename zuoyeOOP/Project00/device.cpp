#include"kon.h"
Shebei::Shebei(string code, string name, int id, double mic)
{
	mCode = code;
	mName = name;
	mId = id;
	mIC = mic;
	Isempity = 1;

}
Shebei::Shebei()
{}
//¿½±´¹¹Ôì
Shebei::Shebei(Shebei& s)
{
	this->mCode = s.mCode;
	this->mName = s.mName;
	this->mId = s.mId;
	this->mIC = s.mIC;
	Isempity = 1;
}
string Shebei::GetCode()
{
	return this->mCode;
}
int Shebei::GetID(string code)
{
	if (code == mCode)
		return this->mId;
}
