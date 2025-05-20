#include<iostream>
using namespace std;
int main() {
	int grade = 0;
	cin >> grade;;
	string finalgrade=(grade>90)?"high pass":(grade>75)?"low pass":(grade>60)?"pass":"fail";
    cout << finalgrade << endl;
	return 0;
}