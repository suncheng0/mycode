#pragma once
#include<iostream>
using namespace  std;
void Swap(int a, int b);
template<typename T>
void Swap(T a, T b) {
	cout << "Ä£°åº¯Êý" << endl;
}

template<>
void Swap(int a, int b);