#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b) {
	return (a == 0) ? b : gcd(b % a, a);
}

int main() {
	int t;
	fin >> t;
	int a, b;
	while (t-- > 0) {
		fin >> a >> b;
		fout << gcd(a, b) << "\n";
	}
    return 0;
}

