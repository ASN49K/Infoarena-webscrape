#include <iostream>
#include <fstream>
 
using namespace std;
 
#ifdef LOCAL
ifstream f("input.txt");
#define g cout
#else
ifstream f("euclid2.in");
ofstream g("euclid2.out");
#endif

int cmmdc(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int n, a, b;

int main() {
	f >> n;
	while (n--) {
		f >> a >> b;
		g << cmmdc(a, b) << '\n';
	}
	return 0;
}

