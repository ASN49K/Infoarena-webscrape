#include <fstream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main () {
	int t;
	fin >> t;
	while(t--) {
		int a, b;
		fin >> a >> b;
		fout << gcd(a, b) << '\n';
	}
}
