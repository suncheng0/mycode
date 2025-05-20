#include<iostream>
using namespace std;
double f(double b, const char* c) {
	cout << b << " " << c << endl;
	return 2.3;
}
template<typename T>
void Swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}
int main() {
	//double (*p)(double, const char*);//声明函数指针
	auto p = f;
	p(12, "函数指针");
	int a = 10, b = 30;
	Swap<int>(a, b);//函数模板
	cout << a << " " << b << endl;

	return 0;
}