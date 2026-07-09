#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int, int);

int main() {
	int t;
	fin >> t;
	while (t--) {
		int a, b;
		fin >> a >> b;
		fout << gcd(a, b) << "\n";
	}
    return 0;
}

int gcd(int a, int b) {
	return (a == 0) ? b : gcd(b % a, a);
}
