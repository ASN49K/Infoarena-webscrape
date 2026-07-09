#include <fstream>
using namespace std;

inline int gcd(int a, int b) { return a==0 ?b :gcd(b%a,a); }

int main() {
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int n; fin >> n;
	for (int a,b; n>0; --n) {
		fin >> a >> b;
		fout << gcd(a,b) << '\n';
	}
	return 0;
}
