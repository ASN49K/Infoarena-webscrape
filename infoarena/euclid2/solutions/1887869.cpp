#include <iostream>
using namespace std;

int cmmdc(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		return cmmdc(b, a % b);
	}
}

int main() {
	ifstream ifs("euclid2.in");
	ofstream ofs("euclid2.out");
	
	int t;
	ifs >> t;
	
	int a, b;
	for (int i = 0; i < t; ++i) {
		ifs >> a >> b;
		ofs << cmmdc(a, b);
	}
	
	return 0;
}