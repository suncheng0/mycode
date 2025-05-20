#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>
#include<cmath>
using namespace std;

void file_it(ostream& os, double fo, const fe[], int n);
const int LIMIT = 5;
int main() {
	
}
void file_it(ostream& os, double fo, const double fe[], int n) {
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed);
	os.precision(0);
	os.setf(ios::showpoint);
	os.width(12);
}