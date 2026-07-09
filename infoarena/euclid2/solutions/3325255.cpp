#include<fstream>
using namespace std;

int main() {
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int tests;
	fin >> tests;
	while (tests--) {
		int a, b, r;
		fin >> a >> b;
		if (b > a) swap(a, b);
		while (b) {
			r = a % b;
			a = b;
			b = r;
		}
		fout << a << '\n';
	}
	
}