#pragma once
#include<iostream>
using namespace  std;
void Swap(int a, int b);
template<typename T>
void Swap(T a, T b) {
	cout << "ģ�庯��" << endl;
}

template<>
void Swap(int a, int b);