#include"public.h"

void Swap(int a, int b) {
	cout << "��ͨ����" << endl;
}

template<>
void Swap(int a, int b)
{
	cout << "ģ����廯" << endl;
}