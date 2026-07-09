#include <iostream>
#include <fstream>
using namespace std;
int main() {
	int n, i, a, b, r, cmmdc;
	ifstream f1("euclid2.in.txt");
	ofstream f2("euclid2.out.txt");
	f1 >> n;
	for (i = 1; i <= n; i++) {
		f1 >> a;
		f1 >> b;
		while (b != 0) {
			r = a % b;
			a = b;
			b = r;
		}
		cmmdc = a;
		f2 << cmmdc << endl;
	}
	f1.close();
	f2.close();
}