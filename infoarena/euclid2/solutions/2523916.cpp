#include <iostream>
#include <fstream>
using namespace std;
int main() {
	int n, i, a, b, cmmdc;
	ifstream f1("euclid2.in");
	ofstream f2("euclid2.out");
	f1 >> n;
	for (i = 1; i <= n; i++) {
		f1 >> a;
		f1 >> b;
		while (a != b) {
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		cmmdc = a;
		f2 << cmmdc << endl;
	}
	f1.close();
	f2.close();
	return 0;
}