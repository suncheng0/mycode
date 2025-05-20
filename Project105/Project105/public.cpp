#include"public.h"

void Swap(int a, int b) {
	cout << "普通函数" << endl;
}

template<>
void Swap(int a, int b)
{
	cout << "模板具体化" << endl;
}