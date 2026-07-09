#include <iostream>
#include <fstream>

using namespace std;


#ifdef LOCAL
ifstream f("input.txt");
#define g cout
#else
ifstream f("nim.in");
ofstream g("nim.out");
#endif

int t, n, x;
int XOR;

int main() {
	f >> t;
	for (int i = 1; i <= t; i++) {
		f >> n;
		XOR = 0;
		for (int j = 1; j <= n; j++) {
			f >> x;
			XOR ^= x;
		}
		if (XOR == 0)
			g << "NU\n";
		else
			g << "DA\n";
	}
	return 0;
}

